#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct {
    int age;
    double height;
    char name[64];
} Person;

void printPersonInfo(Person *p) {
    printf("Person: %s, %d, %f\n", p->name, p->age, p->height);
}

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    Person p;

    if(argc != 2) {
        printf("USAGE: %s fileName\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "rb");
    if(fp == NULL) {
        perror("Error opening file!");
        return EXIT_FAILURE;
    }

    int linesCounter = 0;
    while(fread(&p, sizeof(Person), 1, fp) == 1) {
        linesCounter++;
    }

    // Correct declaration for dynamic array of Persons
    Person *persons = (Person *) malloc(linesCounter * sizeof(Person));
    if (!persons) {
        perror("Memory allocation failed");
        fclose(fp);
        return EXIT_FAILURE;
    }

    rewind(fp);
    for(int i = 0; fread(&p, sizeof(Person), 1, fp) == 1; i++) {
        persons[i] = p;  // Correct assignment
    }

    char answer;
    printf("Do you want to add people? (y/n) ");
    scanf(" %c", &answer);  // Notice the space before %c to skip any newline in the buffer

    int numPeople = 0;
    if(answer == 'y') {
        printf("How many people do you want to add? ");
        scanf("%d", &numPeople);

        persons = (Person *) realloc(persons, (linesCounter + numPeople) * sizeof(Person));
        if (!persons) {
            perror("Memory reallocation failed");
            fclose(fp);
            return EXIT_FAILURE;
        }

        for(int i = linesCounter; i < linesCounter + numPeople; i++) {
            p.age = p.age + 1;
            p.height = p.height + 0.03;
            persons[i] = p;
        }
    }

    for(int i = 0; i < linesCounter + numPeople; i++) {
        printPersonInfo(&persons[i]);
    }

    fclose(fp);
    free(persons);  // Don't forget to free the allocated memory

    return EXIT_SUCCESS;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b) {
    return strcasecmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *sortOrder = getenv("SORTORDER");
    int descending = sortOrder && strcmp(sortOrder, "DESC") == 0;

    int size = 0;
    printf("How many words do you want to sort? ");
    scanf("%d", &size);

    char *words[size];
    int maxSize = 100;

    for (int i = 0; i < size; i++) {
        words[i] = malloc(maxSize * sizeof(char));
        scanf("%99s", words[i]);
    }

    printf("-------------------SORTED-------------------\n");

    if (size > 1) {
        
        qsort(words, size, sizeof(char *), compareStrings);

        if (descending) {
            for (int i = size - 1; i >= 0; i--) {
                printf("%s\n", words[i]);
            }
        } else {
            for (int i = 0; i < size; i++) {
                printf("%s\n", words[i]);
            }
        }
    }


    for (int i = 0; i < size; i++) {
        free(words[i]);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
 man qsort
*/
#define LINEMAXSIZE 10


int compareInts(const void *px1, const void *px2)
{
    int x1 = *((int *)px1);
    int x2 = *((int *)px2);
    return(x1 < x2 ? -1 : x1 == x2 ? 0 : 1);
}

int main(int argc, char *argv[])
{
    int i=0;
    int numLines=0;
    int *numbers;
    FILE *fp = NULL;
    char line [LINEMAXSIZE]; 

    
    fp = fopen(argv[1], "r");
    if( fp == NULL ){
        perror ("Error opening file!");
        return EXIT_FAILURE;
    
    }

    while( fgets(line, sizeof(line), fp) != NULL ){
        numLines++;
    }

    rewind(fp);

    numbers = (int *) malloc(sizeof(int) * numLines);

    while( fgets(line, sizeof(line), fp) != NULL ){
        numbers[i] = atoi(line);
        i++;
    }

    fclose(fp);

    /* void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)); 
         The qsort() function sorts an array with nmemb elements of size size.*/
    qsort(numbers, numLines, sizeof(int), compareInts);

    /* Printing the sorted numbers */
    printf("Sorted numbers: \n");
    for(i = 0 ; i < numLines ; i++)
    {
        printf("%d\n", numbers[i]);
    }

    return EXIT_SUCCESS;
}

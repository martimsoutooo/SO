#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int numChars = 0;
    for (int i = 1; i < argc; i++) {
        numChars += strlen(argv[i]);
    }

    int whiteSpaces = argc - 2; 
    char quote[numChars + whiteSpaces + 1]; 
    int index = 0;

    for (int i = 1; i < argc; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            quote[index++] = argv[i][j];
        }
        if (i < argc - 1) {
            quote[index++] = ' ';
        }
    }
    quote[index] = '\0'; 

    printf("%s\n", quote);    
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareStrings(const void *a, const void *b) {
    return strcasecmp(*(const char **)a, *(const char **)b);
}

int main(int argc, char *argv[]) {
    char *sortOrder = getenv("SORTORDER");
    int descending = sortOrder && strcmp(sortOrder, "DESC") == 0;

    if (argc > 1) {
        qsort(&argv[1], argc - 1, sizeof(char *), compareStrings);

        if (descending) {
            for (int i = argc - 1; i > 0; i--) {
                if (argv[i][0] >= 'A' && argv[i][0] <= 'Z' || argv[i][0] >= 'a' && argv[i][0] <= 'z') {
                    printf("%s\n", argv[i]);
                }
            }
        } else {
            for (int i = 1; i < argc; i++) {
                if (argv[i][0] >= 'A' && argv[i][0] <= 'Z' || argv[i][0] >= 'a' && argv[i][0] <= 'z') {
                    printf("%s\n", argv[i]);
                }
            }
        }
    }

    return 0;
}


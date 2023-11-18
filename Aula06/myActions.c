#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char text[1024];
    FILE *file = fopen("command.log", "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    do {
        printf("Command: ");
        scanf("%1023[^\n]%*c", text);

        if (strcmp(text, "end")) {
            printf("\n * Command to be executed: %s\n", text);
            printf("---------------------------------\n");
            system(text);

            // Obter a data e hora atual usando o comando "date" da bash
            char currentDate[64];
            FILE *dateCommand = popen("date +\"[%Y-%m-%d %H:%M:%S]\"", "r");
            if (dateCommand == NULL) {
                perror("Erro ao executar o comando date");
                return 1;
            }
            fgets(currentDate, sizeof(currentDate), dateCommand);
            pclose(dateCommand);

            // Remova a quebra de linha no final da data
            currentDate[strcspn(currentDate, "\n")] = '\0';

            // Gravar a data, hora e comando na mesma linha no arquivo
            fprintf(file, "%s %s\n", currentDate, text);
            printf("---------------------------------\n");
        }
    } while (strcmp(text, "end"));

    fclose(file);
    printf("-----------The End---------------\n");

    return EXIT_SUCCESS;
}

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

/* SUGESTÂO: utilize as páginas do manual para conhecer mais sobre as funções usadas:
  man opendir
  man readdir
*/

void listDir(char dirname[])
{
    DIR *dp; 
    struct dirent *dent;

    dp = opendir(dirname); 
    if(dp == NULL)
    {
        perror("Error opening directory");
        return;
    }

    dent = readdir(dp);
    while(dent != NULL) 
    {
        if (dent->d_name[0] != '.') { /* do not list hidden dirs/files */
            char path[PATH_MAX]; // Declare uma matriz para armazenar o caminho completo
            snprintf(path, sizeof(path), "%s/%s", dirname, dent->d_name); // Construa o caminho completo

            if (dent->d_type == DT_DIR)
            {
                printf("d %s\n", path);
                listDir(path); // Chame recursivamente com o caminho completo
            }
            else if (dent->d_type == DT_REG)
            {
                printf("  %s\n", path);
            }
        }

        dent = readdir(dp);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage: %s base_directory\n",argv[0]);
        return EXIT_FAILURE;
    }

    listDir(argv[1]);
    
    return EXIT_SUCCESS;
}


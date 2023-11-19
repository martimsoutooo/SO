#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <getopt.h>

int fa = 0;
int da = 0;
int ea = 0;
char *ext;  

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

    while ((dent = readdir(dp)) != NULL)
    {
        if (dent->d_name[0] != '.') { 
            if (fa == 1 && dent->d_type == DT_REG) {
                printf("%s\n", dent->d_name);
            }
            if (da == 1 && dent->d_type == DT_DIR) {
                printf("%s d\n", dent->d_name);
            }
            if (ea == 1 && dent->d_type == DT_REG) {
                char *fileExt = strrchr(dent->d_name, '.');
                if (fileExt && strcmp(ext, fileExt) == 0) {
                    printf("%s\n", dent->d_name);
                }
            }
        }
    }

    closedir(dp);
}

int main(int argc, char *argv[]){
    int opt;
    int option_index = 0;


    struct option long_options[] = {
            {   "file",       no_argument, 0, 'f'  },
            {    "dir",       no_argument, 0, 'd'  },
            {    "ext", required_argument, 0, 'e'  },
    };
    
    while ( (opt = getopt_long(argc, argv, "fde:",long_options, &option_index)) != -1 ){
        switch (opt) {
            case 'f':
                fa = 1;
                break;
            case 'd':
                da = 1;
                break;
            case 'e':
                ea = 1;
                ext = optarg;
                break;
            
        }
    }

    // Check if at least one directory is provided
    if(optind == argc)
    {
        fprintf(stderr,"Usage: %s directory...\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Process each directory provided after the options
    for(int i = optind; i < argc; i++) {
        listDir(argv[i]);
    }

    return EXIT_SUCCESS;
}
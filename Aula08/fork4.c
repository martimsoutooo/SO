#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int stat;

    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
               if (execl("./child", "./child", NULL) < 0) { 
                   perror("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               break;
      default: /* processo pai */
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
               if (wait(&stat) < 0) { 
                   perror("erro na espera da terminação do processo-filho");
                   return EXIT_FAILURE;
               }
               printf("Pai: o processo-filho terminou. ");
               if (WIFEXITED(stat) != 0) {
                   printf("O seu status de saída foi %d.\n", WEXITSTATUS(stat));
               }
               else {
                   printf("O processo filho terminou de forma anormal.\n");
               }
    }

    return EXIT_SUCCESS;
}

// foi retirada alinha do printf que era desnecessária sendo que
// nunca seria executada, e foi adicionado um wait para esperar
// que o processo filho acabe para que o processo pai não acabe

// em primerio será imprimida a linha do pai antes do fork
// em segundo será imprimida a linha do pai depois do fork provavelmente
// em terceiro as linhas do processo filho que no caso estão no ficheiro ./child
// e por fim a linha do pai a dizer que o filho acabou e o seu status de saída
// sendo que o programa acabou normalmente o prompt não irá ter anomalias 


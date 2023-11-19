#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("Pai (antes do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    switch (fork())
    {
      case -1: /* fork falhou */
               perror("Erro no fork\n");
               return EXIT_FAILURE;
      case 0:  /* processo filho */
               if (execl("/bin/ls", "ls","-l" ,NULL) < 0) { 
                   perror("erro no lancamento da aplicacao");
                   return EXIT_FAILURE;
               }
               printf("Porque é que eu não apareço?\n");
               break;
      default: /* processo pai */
               sleep(1);
               printf("Pai (depois do fork): PID = %u, PPID = %u\n", getpid(), getppid());
    }

    return EXIT_SUCCESS;
}

// Os dois primeiros argumentos da função são iguais porque no caso o primeiro é o caminho que tem de seguir até ao file para
// executar e o segundo é a execução em si, como ele quer executar ./child, e o mesmo
// ja é um ficheiro de execução o comando para o executar é o nome dele

// o comando em shell equivalente á invocaçaõ da instrução execl
// é o comando exec

// a instrução nunca é executada porque esse processo é substituido pelo processo filho

// A diferença está no PPID que muda pelo facto que o pai "morreu"
// e o processo filho passou a ser filho de outro processo

// A causa da anomalia é mesmo o facto de o processo pai acabar antes
// do processo filho, e por consequencia o processo filho nã vai fechar o programa 

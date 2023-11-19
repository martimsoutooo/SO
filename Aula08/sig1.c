#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    unsigned int i;

    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= 10) { 
        printf("\r%08u ", i++);
        fflush(stdout);
        sleep(1);
    }
    printf("\n");

    return EXIT_SUCCESS;
}

// Neste caso a instrução fflush(stdout) é necessário para que 
// o buffer de saida seja limpo e escreva imediatamente a mensagem 
// ao invés de esperar que o buffer fique cheio.

// O programa cria um cronómetro de 10 segundos.

//O programa para de ser executado e a informação que fica 
// no output é o conteúdo que estava no buffer no momento em que 
// o programa foi interrompido.

// No caso das teclas CRTL-Z o programa é suspenso e podemos através de comandos 
// do sistema operativo continuar a sua execução ou terminar o processo.


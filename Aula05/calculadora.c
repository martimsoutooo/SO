#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("ERROR: Wrong number of arguments\n");
        return EXIT_FAILURE;
    }

    char *endptr1, *endptr2;
    double num1, num2;
    
    num1 = strtod(argv[1], &endptr1);
    num2 = strtod(argv[3], &endptr2);

    // Verifica se a conversão foi bem-sucedida
    if (*endptr1 != '\0' || *endptr2 != '\0') {
        printf("ERROR: Invalid number format\n");
        return EXIT_FAILURE;
    }
    
    char option = argv[2][0];

    switch(option) {
        case '+' : 
            printf("Soma: %0.1f\n", num1 + num2);
            break;
        case '-' :
            printf("Subtracao: %0.1f\n", num1 - num2);
            break;
        case 'x' :
            printf("Multiplicacao: %0.1f\n", num1 * num2);
            break;
        case '/' :
            // Adiciona verificação para divisão por zero
            if (num2 != 0.0) {
                printf("Divisao: %0.1f\n", num1 / num2);
            } else {
                printf("ERROR: Division by zero\n");
                return EXIT_FAILURE;
            }
            break;
        case 'p':
            printf("Potencia: %0.1f\n", pow(num1, num2));
            break;
    }

    return EXIT_SUCCESS;
}

// o * é um carater especial em c e por isso não pode ser usado como argumento


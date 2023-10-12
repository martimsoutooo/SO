#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Só pode ter 1 argumento"
else

    if [ -e "$1" ]; then
        if [ -f "$1" ]; then
                echo "$1 existe e é um ficheiro"
            if [ -r "$1" ]; then
                echo "$1 é possível ler"
            fi
            if [ -w "$1" ]; then
                echo "$1 é possível escrever"
            fi
            if [ -x "$1" ]; then
                echo "$1 é possível executar"
            fi
        elif [ -d "$1" ]; then
            echo "$1 existe e é um diretório."
        fi
    else
        echo "$1 não existe"
    fi
fi
echo "...feito."

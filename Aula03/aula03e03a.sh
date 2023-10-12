#!/bin/bash
# Este script verifica a existência de um arquivo

if [ "$#" -ne 1 ]; then
    echo "Só pode ter 1 argumento"
else
    echo "Verificando..."
    if [ -f "$1" ]; then
        echo "$1 existe e é uma diretoria."
    else
        echo "$1 não existe"
    fi
    echo "...feito."
fi
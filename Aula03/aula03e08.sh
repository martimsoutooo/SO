#!/bin/bash
# Exemplo de uso da estrutura select para criar menus
PS3="Escolha uma opção: " # Redefinindo PS3 para uma mensagem personalizada

select arg in "$@"; do
    if [ -n "$arg" ]; then
        echo "Você escolheu $arg ($REPLY)."
    else
        echo "Opção inválida."
        exit
    fi
done

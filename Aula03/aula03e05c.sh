#!/bin/bash

if [ $# -ne 2 ]; then
  echo "Só pode ter 2 argumentos"
  exit 1
fi

if [ ! -d "$1" ]; then
  echo "O argumento deve ser um diretório válido."
  exit 1
fi

cd "$1" 

if [[ $2 = "-r" ]]; then
    for f in *; do
        mv "$f" "${f#new_}"
    done
else
    for f in *; do
        mv "$f" "new_$f"
    done
fi

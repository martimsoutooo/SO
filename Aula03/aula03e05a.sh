#!/bin/bash
# For all the files in a folder, show their properties

if [ "$#" -ne 1 ]; then
    echo "Só pode ter 1 argumento"
    exit 1
fi

if [ -d " $1" ]; then
    echo "O argumento tem que ser um nome de uma diretoria"
    exit 1
fi

for f in "$1"/*; do
   file "$f"
done

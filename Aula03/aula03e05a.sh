#!/bin/bash
# For all the files in a folder, show their properties

if [ "$#" -ne 1 ]; then
    echo "Deve fornecer exatamente 1 argumento"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "O argumento deve ser um diretório existente"
    exit 1
fi

directory="$1"

for file in "$directory"/*; do
    if [ -f "$file" ]; then
        mv "$file" "${directory}/new_$(basename "$file")"
        file "$file"
    fi
done


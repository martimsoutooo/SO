#!/bin/bash
echo "Nome Base do Arquivo: $1"
echo "Nome da Pasta: $2"
mkdir $2
touch $2/$1{00..09}

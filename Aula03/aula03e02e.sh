#!bin/bash
echo:
if [[ $1 -gt 5 ]] && [[ $1 -lt 10 ]]; then
    echo -e "O arg1 é maior que 5 e menor que 10"
else
    echo -e "O arg1 não é maior que 5 e menor que 10"
fi
#!/bin/bash 
function imprime_msg() 
{ 
  echo "A minha primeira funcao" 
  return 0 
} 

function imprime_name_pcname_date() 
{ 
    echo "O nome de usuario e: $USER"
    echo "O nome do computador e: $HOSTNAME" 
    echo "A data de hoje e: $(date)" 
    return 0 
}
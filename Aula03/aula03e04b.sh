#!/bin/bash
# This script checks disk space usage and provides a message based on the usage level.

# Obtém informações de todas as partições
partition_info=$(df -h)

# Extrai o número de ocupação (uso) para cada partição
space_info=$(echo "$partition_info" | awk '{print $5}' | grep % | grep -v Use)

# Obtém a partição com mais espaço livre
partition_with_most_space=$(echo "$space_info" | sort -n | tail -1 | cut -d '%' -f1)

echo "Largest occupied space = $partition_with_most_space%"

# Use a case statement to determine the appropriate message
case $partition_with_most_space in
    [0-6][0-9])
        Message="All OK."
        ;;
    [7-8][0-9])
        Message="Cleaning out. One partition is $partition_with_most_space% full."
        ;;
    9[0-9])
        Message="Better buy a new disk. One partition is $partition_with_most_space% full."
        ;;
    100)
        Message="I'm drowning here! There's a partition at $partition_with_most_space%!"
        ;;
esac

# Adicione a funcionalidade para identificar a partição com mais espaço livre
partition_with_most_free_space=$(echo "$partition_info" | sort -n -k 4 | tail -1 | awk '{print $6}')

Message="$Message The partition with the most free space is: $partition_with_most_free_space"

echo "$Message"

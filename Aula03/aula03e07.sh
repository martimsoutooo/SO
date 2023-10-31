#!/bin/bash 
# Calculate the sum of a series of numbers. 
SCORE="0" 
SUM="0" 
NUM="0"
I="1"

while true; do 
    echo -n "Enter your score [0-10] ('q' to quit): " 
    read SCORE; 
    if (("$SCORE" < "0"))  || (("$SCORE" > "10")); then 
        echo "Try again: " 
    elif [[ "$SCORE" == "q" ]]; then 
        echo "Sum: $SUM." 
        echo "Med: $((SUM / NUM))."

        break 

    elif [[ "$SCORE" == "-r" ]]; then
        echo "Reseting..."
        SUM="0"
        NUM="0"

    else 
        SUM=$((SUM + SCORE)) 
        NUM=$((NUM + I))
    fi 
done 
echo "Exiting."

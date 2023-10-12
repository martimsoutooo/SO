#!/bin/bash
# This script checks disk space usage and provides a message based on the usage level.

space=$(df -h | awk '{print $5}' | grep % | grep -v Use | sort -n | tail -1 | cut -d '%' -f1)

echo "Largest occupied space = $space%"

# Use a case statement to determine the appropriate message
case $space in
    [0-6][0-9])
        Message="All OK."
        ;;
    [7-8][0-9])
        Message="Cleaning out. One partition is $space% full."
        ;;
    9[0-9])
        Message="Better buy a new disk. One partition is $space% full."
        ;;
    100)
        Message="I'm drowning here! There's a partition at $space%!"
        ;;
esac

echo "$Message"
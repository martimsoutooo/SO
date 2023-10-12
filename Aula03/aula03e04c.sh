#!bin/bash

case $1 in
    [0-9][0-9])
        Message="All OK with the first argument"
        ;;
    *)
        Message="NOT OK with the first argument"
        ;;
esac

echo "$Message"

case $2 in 
    sec*)
        Message1="All OK with the second argument"
        ;;
    *)
        Message1="NOT OK with the second argument"
        ;;
esac

echo "$Message1"



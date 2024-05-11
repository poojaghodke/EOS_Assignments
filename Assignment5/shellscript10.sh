#!/bin/bash
echo "enter a number to generate fiboncci series"
read num

echo "The Fibonacci series is : "
a=0
b=1

for (( i=0; i<num; i++ ))
do
    echo -n "$a "
    res=$((a + b))
    a=$b
    b=$res
done

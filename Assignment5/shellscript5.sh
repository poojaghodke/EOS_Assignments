#!/bin/bash
echo -n "enter three  numbers : "
read num1 num2 num3
max=0

if [ $num1 -gt  $num2 -a $num1 -gt $num3 ]
then
	echo "num1 is greater "
	max=$num1
elif [ $num1 -lt $num2 -a $num2 -gt $num3 ]
then
	echo "num2 is greater"
	max=$num2
else
	echo "num3 is greater"
	max=$num3
fi

echo "maximum number=$max"


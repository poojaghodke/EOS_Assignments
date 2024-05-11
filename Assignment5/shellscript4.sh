#!/bin/bash
echo "enter a number"
read num
j=`expr $num / 2`

i=2
k=0
while [ $i -le $j ] 
do
	if  [ $((num % i)) -eq 0 ]
	then
  		k=`expr $k + 1`
	fi	
	i=`expr $i + 1`
done

if [ $k -gt 0 ]
then
	echo "number is not prime"

else
	echo "number is prime"

fi	

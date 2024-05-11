#!bin/bash

echo "enter a number"
read num

for i in `seq 1 10`
do
	echo `expr $i \* $num`
done	

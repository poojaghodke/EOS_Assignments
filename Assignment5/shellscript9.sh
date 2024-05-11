#!/bin/bash

echo "enter a number"
read num
res=1
for i in `seq 1 $num`
do 
	res=`expr $res \* $i`
done

echo "factorial number = $res"

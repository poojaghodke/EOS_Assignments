#!/bin/bash
i=1
while [ $i -le 5 ]
do 
	j=$i
	while [ $j -gt 0 ]
	do
		echo -n "*"
		j=`expr $j - 1`
	done
	echo -e "\n"
	i=`expr $i + 1`
done	

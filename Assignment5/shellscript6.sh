#!/bin/bash

echo -n "enter a year : "
read yr

if [ `expr $yr % 400` -eq 0 -a `expr $yr % 100` -eq 0 -o `expr $yr % 4` -eq 0 ]
then 
	echo "leap year"

else
	echo "not leap year"

fi	

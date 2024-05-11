#!/bin/bash

echo "enter file name"
read file

if [ -e $file ]
then
	if [ -f $file ]
	then
		echo "file is exist"
		stat $file
	fi		

else
	echo "file is not exist"
fi	

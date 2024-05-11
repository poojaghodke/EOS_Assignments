#!/bin/bash
echo -n "enter file name or directory name : "
read file

if [ -e $file ]
then 
	if [ -f $file ]
	then
		echo "It is Reguler File"
		du -sh $file

	elif [ -d $file ]
	then
		echo "It is directory"
		ls $file

	else
		echo "path is something else"
	fi
	
else
	echo "path does not exist"
fi	


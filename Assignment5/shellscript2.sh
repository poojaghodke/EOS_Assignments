#!/bin/bash

echo -e "1.Date 2.cal 3.ls 4.pwd 5.exit"
echo -n "enter your choice : "
read choice

case $choice in
1)echo "$(date '+%Y-%m-%d')"
	;;

2)echo "$(cal)"
    ;;

3)echo "$(ls)"
	;;

4)echo "$(pwd)"
	;;

5)echo "$(exit)"
	;;

*)echo "invalid operation"	
	;;
esac

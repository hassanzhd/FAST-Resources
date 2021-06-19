#!/bin/bash
cd ~/Desktop

fileType=( "*.txt" "*.cpp" "*.c" )
directory=( "TXT" "CPP" "CP" )
length=${#fileType[@]}

for ((i=0;i<$length;i++)); do
	for fileName in ${fileType[$i]} ; do
		if [ -e $fileName ] ; then
			if [ -d ${directory[$i]} ] ; then
				mv ./$fileName ./${directory[$i]}	
			else
				mkdir ./${directory[$i]}
				mv ./$fileName ./${directory[$i]}
			fi
		else
			echo "${fileName} not found"	
		fi
	done
done

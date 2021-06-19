#!/usr/bin/env bash

#variable declaration and printing
name="HASSAN ZAHID" # creation of variable
echo $name #printing of variable

#read and printing

# echo "Enter name: "
# read name #longhand method

read -p "Enter name: " name #shorthand method
echo $name

read -p "Enter iterations: " iterations

#for loop
echo "FOR LOOP: "
for ((i=0;i<$iterations;i++)); do
    if (($i>0)); then
        echo $name
    else 
        echo "BAD NAME"
    fi
done

#while loop
i=0
echo "WHILE LOOP: "
while (($i<$iterations)); do
    echo $name
    i=$i+1;
done

abc() {
    echo "I AM IN ABC"
}

abc
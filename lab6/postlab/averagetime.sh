#!/bin/bash
# Yu Du, yd2am
# averagetime.sh
# 2019.10.22

#read in the dictionary and the grid
echo "Please enter the name of your dictionary file: "
read dictionary
echo "Please enter the name of your grid file: "
read grid

# run 5 times
RUNNING_TIME1=`./a.out ${dictionary} ${grid} | tail -1`
RUNNING_TIME2=`./a.out ${dictionary} ${grid} | tail -1`
RUNNING_TIME3=`./a.out ${dictionary} ${grid} | tail -1`
RUNNING_TIME4=`./a.out ${dictionary} ${grid} | tail -1`
RUNNING_TIME5=`./a.out ${dictionary} ${grid} | tail -1`

# get total running time
total=$((${RUNNING_TIME1}+${RUNNING_TIME2}+${RUNNING_TIME3}+${RUNNING_TIME4}+${RUNNING_TIME5}))
# get average run time
average=$((total/5))
echo "The average running time is" ${average} "milliseconds."
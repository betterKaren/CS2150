#!/bin/bash
# Yu Du, yd2am
# averagetime.sh
# 2019.10.30

#read in
echo "enter the exponent for counter.cpp:"
read exponent

if [ "$exponent" == "quit" ]
then
	exit 0
fi

# run 5 times
for i in {1..5} ; do
	echo "Running iteration ${i}..."
	time=`./a.out ${exponent} | tail -1`
	echo "time taken:" ${time} "ms"
	total=$((${total}+${time}))
done

echo "5 iterations took" ${total} "ms"
average=$((${total}/5))
echo "Average time was" ${average} "ms"
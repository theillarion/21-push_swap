#!/bin/bash

if [ ! -n "$1" ]; then
	echo "Error"
	exit 1
fi

make > /dev/null
valgrind --leak-check=full --leak-resolution=high --log-file=leaks.log -s $1 > /dev/null

awk '{$1=""; print $0}' leaks.log > new_leaks.log

heap_allocs=$(cat new_leaks.log | grep "total heap usage" | awk '{print($4)}')
heap_frees=$(cat new_leaks.log | grep "total heap usage" | awk '{print($6)}')

leaks=$(cat new_leaks.log | grep "LEAK SUMMARY")

errors=$(cat new_leaks.log | grep "ERROR SUMMARY" | awk '{print($3)}')
errors_context=$(cat new_leaks.log | grep "ERROR SUMMARY" | awk '{print($6)}')

if [ "${heap_allocs}" == "${heap_frees}" ]; then
	heap_result="\033[32mOK\033[0m"
else
	heap_result="\033[31mKO\n$(cat new_leaks.log | grep "total heap usage")\033[0m"
fi

if [ -z "${leaks}" ]; then
	leaks_result="\033[32mOK\033[0m"
else
	line_start=$(cat new_leaks.log | grep -n "LEAK SUMMARY" | grep -Eo '^[^:]+')
	(( line_start++ ))
	line_end="$(( line_start + 4 ))"
	leaks_result="\033[31mKO\n$(sed -n "${line_start},${line_end}p" new_leaks.log)\033[0m"
fi

if [ "${errors}" == "${errors_context}" ]; then
	errors_result="\033[32mOK\033[0m"
else
	errors_result="\033[31mKO\n$(cat new_leaks.log | grep "ERROR SUMMARY" | sort | uniq )\033[0m"
fi

echo -e \
"\
Heap: $heap_result
LEAK SUMMARY: $leaks_result
ERROR SUMMARY: $errors_result\
"

if [ -n "leaks.log" ]; then
	rm -f leaks.log
fi
if [ -n "new_leaks.log" ]; then
	rm -f new_leaks.log
fi
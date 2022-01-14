#!/bin/bash

valgrind --leak-check=full --leak-resolution=high --log-file=leaks.log -s ./push_swap > /dev/null

heap_allocs=$(cat leaks.log | grep "total heap usage" | awk '{print($5)}')
heap_frees=$(cat leaks.log | grep "total heap usage" | awk '{print($7)}')

leaks=$(cat leaks.log | grep "LEAK SUMMARY")

errors=$(cat leaks.log | grep "ERROR SUMMARY" | awk '{print($4)}')
errors_context=$(cat leaks.log | grep "ERROR SUMMARY" | awk '{print($7)}')

if [ "${heap_allocs}" == "${heap_frees}" ]; then
	heap_result="\033[32mOK\033[0m"
else
	heap_result="\033[31mKO\n$(cat leaks.log | grep "total heap usage")\033[0m"
fi

if [ -z "${leaks}" ]; then
	leaks_result="\033[32mOK\033[0m"
else
	leaks_result="\033[31mKO\n$(leaks)\033[0m"
fi

if [ "${errors}" == "${errors_context}" ]; then
	errors_result="\033[32mOK\033[0m"
else
	errors_result="\033[31mKO\n$(cat leaks.log | grep "ERROR SUMMARY")\033[0m"
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
#!/bin/bash

valgrind --leak-check=full --leak-resolution=high --log-file=leaks.log -s ./push_swap > /dev/null

heap_allocs=$(cat leaks.log | grep "total heap usage" | awk '{print($5)}')
heap_frees=$(cat leaks.log | grep "total heap usage" | awk '{print($7)}')

error_summary_errors=$(cat leaks.log | grep "ERROR SUMMARY" | awk '{print($4)}')
error_summary_context=$(cat leaks.log | grep "ERROR SUMMARY" | awk '{print($7)}')

leak_summary=$(cat leaks.log | grep "LEAK SUMMARY")

echo -n "Heap: " 
if [ "${heap_allocs}" == "${heap_frees}" ]; then
	echo -e "\033[32mOK\033[0m"
else
	echo -e "\033[31mKO\n$(cat leaks.log | grep "total heap usage")\033[0m"
fi

echo -n "LEAK SUMMARY: "
if [ -z "${leak_summary}" ]; then
	echo -e "\033[32mOK\033[0m"
else
	echo -e "\033[31mKO\n$(leak_summary)\033[0m"
fi

echo -n "ERROR SUMMARY: "
if [ "${error_summary_errors}" == "${error_summary_context}" ]; then
	echo -e "\033[32mOK\033[0m"
else
	echo -e "\033[31mKO\n$(cat leaks.log | grep "ERROR SUMMARY")\033[0m"
fi

if [ -n "leaks.log" ]; then
	rm -f leaks.log
fi
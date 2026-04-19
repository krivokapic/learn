#!/bin/bash

touch result.txt
first=$(tr -dc A-Za-z0-9 </dev/urandom | head -c 13; echo)
test=$(tr -dc A-Za-z0-9 </dev/urandom | head -c 13; echo)
i=0
while [ "$first" != "$test" ]
do
    echo "${i} ${test}"
    ((i++))
    test=$(tr -dc A-Za-z0-9 </dev/urandom | head -c 13; echo)
done >> result.txt

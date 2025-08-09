#!/bin/bash

# insert 1000 random value rows into a sales table
for i in {1..1000}; do 
    echo "insert into sales(salesperson, region, sale_date, amount) values ('Person_$i', 'Region_$i', 'Date_$i', $((RANDOM % 2000 + 1)));" >> insert.sql;
done

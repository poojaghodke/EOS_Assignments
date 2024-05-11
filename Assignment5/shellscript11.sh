#!/bin/bash

echo "enter salary"
read salary

HRA=`expr 20 \* $salary / 100`
DA=`expr 40 \* $salary / 100`

GrossSalary=`expr $salary + $HRA + $DA`
echo "Gross Salary : $GrossSalary"

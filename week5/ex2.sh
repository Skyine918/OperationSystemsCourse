#!/bin/bash
for i in {1..1000}
do
  number=$(tail -n 1 "input.txt")
  echo "$(($number+1))" >> "input.txt"
done
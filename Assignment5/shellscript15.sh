#!/bin/bash
echo "enter two filename"
read file1 file2

content=$(cat "$file1" | tr '[:upper:][:lower:]' '[:lower:][:upper:]')
echo "$content" >> "$file2"

#!/bin/bash

if [ $# -ne 2 ]; then
	echo "ERROR: Invalid number of arguments."
	echo "Usage: $0 <writefile> <writestr>"
	exit 1
fi

WRITEFILE=$1
WRITESTR=$2

DIRPATH=$(dirname "$WRITEFILE")
mkdir -p "$DIRPATH"

echo "$WRITESTR" > "$WRITEFILE"

if [ $? -ne 0 ]; then
	echo "ERROR: Could not create or write to file $WRITEFILE"
	exit 1
fi
exit 0

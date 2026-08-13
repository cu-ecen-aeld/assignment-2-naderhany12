#!/bin/bash

if [ $# -ne 2 ]; then
	echo "ERROR: Invalid number of arguments."
	echo "Usage: $0 <filesdir> <searchstr>"
	exit 1
fi

FILESDIR=$1
SEARCHSTR=$2

if [ ! -d "$FILESDIR" ]; then
	echo "ERROR: Directory $FILESDIR does not exist."
	exit 1
fi

NUM_FILES=$(find "$FILESDIR" -type f | wc -l)
NUM_MATCHES=$(grep -r "$SEARCHSTR" "$FILESDIR" | wc -l)

echo "The number of files are $NUM_FILES and the number of matching lines are $NUM_MATCHES"
exit 0

#!/bin/bash

file=$1


if [ $# -lt 1 ]; then
  echo "Gebe einem Parameter."
  exit 1
fi


#grep -i "\b([aeiou][bcdfghjklmnpqrstvwxyz][bcdfghjklmnpqrstvwxyz][aeiou]){2,4}\b" $file
grep -i "\b[aeiou][bcdfghjklmnpqrstvwxyz]\b" $file
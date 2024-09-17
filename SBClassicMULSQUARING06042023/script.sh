#/!usr/bin/bash

SIZE=$1

STR="#include \"sb512_$1.c\""


echo $SIZE

echo $STR

echo $STR > mulsquare512.c


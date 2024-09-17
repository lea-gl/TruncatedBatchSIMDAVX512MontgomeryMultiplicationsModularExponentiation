#!/bin/bash

echo test

DATE=$(date +"%d%m%Y")

echo "$DATE"

FILE="perfsInspiron${DATE}.txt"

echo "$FILE"

i=1

echo "WIN_WIDTH = 1"
echo "WIN_WIDTH = $i"
echo "" > "$FILE"
echo "********************************" >> "$FILE"
echo "" >> "$FILE"
echo "		W    W __  $i$i$i" >> "$FILE"
echo "		 W  W  __  $i$i$i" >> "$FILE"
echo "		  WW       $i$i$i" >> "$FILE"
echo "" >> "$FILE"
echo "********************************" >> "$FILE"
echo "" >> "$FILE"
make -B WIN_WIDTH=1 TEST=1
./main > tmp

tail -n 39 tmp >> $FILE

for i in 2 3 4 5
do
 echo "WIN_WIDTH = $i"
 echo "" >> "$FILE"
 echo "********************************" >> "$FILE"
 echo "" >> "$FILE"
 echo "		W    W __  $i$i$i" >> "$FILE"
 echo "		 W  W  __  $i$i$i" >> "$FILE"
 echo "		  WW       $i$i$i" >> "$FILE"
 echo "" >> "$FILE"
 echo "********************************" >> "$FILE"
 echo "" >> "$FILE"

 make -B WIN_WIDTH=$i TEST=1
 ./main > tmp
 tail -n 39 tmp >> "$FILE"
 echo "" >> "$FILE"

done


rm tmp

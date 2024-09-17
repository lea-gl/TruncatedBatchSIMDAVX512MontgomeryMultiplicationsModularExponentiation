#!/bin/bash

echo test

DATE=$(date +"%d%m%Y")

echo "$DATE"

FILE="perfsInspiron${DATE}.txt"

echo "$FILE"

i=1

echo "SIZE = 104"
echo "SIZE = $i"
echo "" > "$FILE"
echo "********************************" >> "$FILE"
echo "" >> "$FILE"
echo "		W    W __  $i$i$i" >> "$FILE"
echo "		 W  W  __  $i$i$i" >> "$FILE"
echo "		  WW       $i$i$i" >> "$FILE"
echo "" >> "$FILE"
echo "********************************" >> "$FILE"
echo "" >> "$FILE"
make -B SIZE=104
./main > tmp

tail -n 54 tmp >> $FILE

for i in 208 260 520 1040 2080 4108 4160 8216 8320
do
 echo "SIZE = $i"
 echo "" >> "$FILE"
 echo "********************************" >> "$FILE"
 echo "" >> "$FILE"
 echo "		W    W __  $i$i$i" >> "$FILE"
 echo "		 W  W  __  $i$i$i" >> "$FILE"
 echo "		  WW       $i$i$i" >> "$FILE"
 echo "" >> "$FILE"
 echo "********************************" >> "$FILE"
 echo "" >> "$FILE"

 make -B SIZE=$i
 ./main > tmp
 tail -n 54 tmp >> "$FILE"
 echo "" >> "$FILE"

done


rm tmp

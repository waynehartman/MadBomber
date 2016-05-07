#!/bin/bash 
DIR="$1"
 
# failsafe - fall back to current directory
[ "$DIR" == "" ] && DIR="."
 
# save and change IFS
OLDIFS=$IFS
IFS=$'\n'
 
# read all file name into an array
fileArray=($(find . -name '*.caf'))
 
# restore it
IFS=$OLDIFS
 
# get length of an array
tLen=${#fileArray[@]}
 
# use for loop read all filenames
for (( i=0; i<${tLen}; i++ ));
do
  afconvert -f caff -d LEI16 "${fileArray[$i]}" "${fileArray[$i]}"
done

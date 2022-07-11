#!/bin/bash

source env.sh

mkdir fileOut

./anal_ical $1 $2 $3 $4 $5 $6 $7 $8 $9 1>out.txt 2>err.txt

# ./a.out 1>tmp.txt 2>tmpe.txt                                                                                                                             

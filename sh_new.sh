#!/bin/bash
./vm_champs/asm $1.s
for ((i = $3; i < $4; i = i + $2))
do
echo "Cikles $i"
./vm_champs/corewar $1.cor $1.cor $1.cor  -d $i > test
./cor_1  $1.cor  $1.cor $1.cor  -dump $i > my
md5 test
md5 my
done

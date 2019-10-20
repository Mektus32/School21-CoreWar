#!/bin/bash
make
rm my
rm test
rm md_test
rm md_my
./vm_champs/asm $1.s
for ((i = $3; i <= $4; i = i + $2))
do
#echo "Cikles $i"
./vm_champs/corewar $1.cor $1.cor $1.cor  -d $i > test
./cor_1  $1.cor  $1.cor $1.cor  -dump $i > my
md5 test > md_test
md5 my > md_my

v_1=$(cut -d= -f2 md_test)
v_2=$(cut -d= -f2 md_my)
if [ "$v_1" = "$v_2" ]
then
	echo "$v_1 = $v_2"
else
	echo "Cikles $i"
	echo "test = $v_1 != my = $v_2"
	break
fi
done
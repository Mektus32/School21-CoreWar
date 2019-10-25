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
end_file=13000
v_1=$(wc -c <test)

if [ "$v_1" -ge $sss ]
then
	echo "Cikles $i = $v_1"
else
	echo "Cikles $i = $v_1"
	break	
fi
done
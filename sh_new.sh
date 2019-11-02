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
./vm_champs/corewar $1.cor $1.cor $1.cor -d $i > test # $1.cor $1.cor 
./cor_1 $1.cor $1.cor $1.cor  -dump $i   > my #   $1.cor $1.cor
md5 test > md_test
md5 my > md_my
end_file=13000
v_1_end=$(wc -c <test)
v_2_end=$(wc -c <my)


v_1=$(cut -d= -f2 md_test)
v_2=$(cut -d= -f2 md_my)
if [  \( "$v_1" = "$v_2" \) -a \( "$v_1_end" -gt $end_file \) ]
then
	echo "$i Cikles size = $v_1_end md5 = $v_1"
else
		echo "Cikles $i"
#	echo "test = $v_1 != my = $v_2"
	echo "size_end_test = $v_1_end"
	echo "size_end_my = $v_2_end"
	break
fi
done
#!/bin/bash
#make
rm -f my
rm -f test
rm -f md_test
rm -f md_my
#./vm_champs/asm $1.s
for ((i = $3; i <= $4; i = i + $2))
do
#echo "Cikles $i"
./new_check_kk/Corewar/corewar  $1.cor $5.cor  -dump $i > test # $1.cor $1.cor#$6.cor $7.cor
#оригинал
#./corewar_copy   $1.cor $5.cor $6.cor $7.cor -d  $i > test # $1.cor $1.cor # $6.cor $7.cor

./corewar_arina $1.cor $5.cor -dump $i  > my #   $1.cor $1.cor #$6.cor $7.cor
#вместо моего чек corewar_kk/Corewar/corewar   $1.cor $5.cor  -dump $i > my # $1.cor $1.cor
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
	diff my test  > ddd
	#cat my 
	break
fi
done

# Cikles 11836 - ломается corelol и HORACE

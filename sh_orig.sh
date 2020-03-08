#!/bin/bash
#make
rm -f my
rm -f test
rm -f md_test
rm -f md_my
#./vm_champs/asm $1.s
# for ((i = $2; i <= $4; i = i + $3))
# do
#echo "Cikles $i"
./corewar_orig  $1.cor -v $2 > test # $1.cor $1.cor#$6.cor $7.cor
#оригинал
#./corewar_copy   $1.cor $5.cor $6.cor $7.cor -d  $i > test # $1.cor $1.cor # $6.cor $7.cor

./corewar $1.cor -v  $2 > my #   $1.cor $1.cor #$6.cor $7.cor
#вместо моего чек corewar_kk/Corewar/corewar   $1.cor $5.cor  -dump $i > my # $1.cor $1.cor
diff my test  > ddd
# done

# Cikles 11836 - ломается corelol и HORACE

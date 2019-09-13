#include "corewar.h"

void	ft_live(t_cor *cor, t_carr *tmp)
{
	unsigned char t_dir[4];
	//char *b2;

	// запоминаем номер цикла в котором проводилась опирация live
	tmp->cycles_live = cor->live->cycles;
	tmp->cur = (tmp->cur + 1) % MEM_SIZE;
	//tmp->cur++;
	//codage oclat = 0
	//считывает T_DIR
	ft_memcpy(t_dir, (cor->code + tmp->cur) % MEM_SIZE, 4);
	printf("T_DIR = %d\n", t_dir);
	tmp->cur = (tmp->cur + 4) % MEM_SIZE;
	//Если указанный в качестве аргумента операции live
	//номер совпадает с номером игрока, то она засчитывает,
	//что это игрок жив. Например, если значение аргумента равно -2, значит игрок с номером 2 жив.
	if (t_dir == tmp->reg[0])
		tmp->live = 1;
	else
		tmp->live = 0;
}


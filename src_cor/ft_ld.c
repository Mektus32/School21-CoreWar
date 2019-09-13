#include "corewar.h"

void ft_ld(t_cor *cor, t_carr *tmp)
{
	unsigned char	c[1];//codage octal
	char *b2;
	unsigned char t_dir[DIR_SIZE];
	unsigned char t_ind[IND_SIZE];
	//	unsigned int t_dir;
	//short		t_dir;
	 // T_REG занимает только 1 байт
	unsigned char t_reg[1];//Название регистра (r1, r2...) в байт-коде занимает 1 байт. Но сам регистр вмещает в себя 4 байта, как указано в константе REG_SIZE.

//codage octal
	ft_memcpy(c, (cor->code + tmp->cur) % MEM_SIZE, 1); //У 02 команды load - codage 1, значит мы считываем первое число после команды
	printf("c + 1 = %x\n", c[0]);
	tmp->cur = (tmp->cur + 1) % MEM_SIZE;
	b2 = base16_2(c[0]); // 90 = 144 = 10 01 00 00
	//printf("c2 = %d\n", b2[0] == 1);
	// какой аргумент t_dir?
	int i;
	i = 0;
	if (b2[0] == 1 && b2[1] == 0 ) // T_DIR
	{
		ft_memcpy(t_dir, (cor->code + tmp->cur) % MEM_SIZE, DIR_SIZE); //Число 2 или 4 байта в зависимости от label ХЗ
		printf("T_DIR = %d\n", t_dir); //T_DIR - столько байтов сколько указано в label_size у команды
		//t_dir = (t_dir[0] << 24) | (t_dir[1] << 16) | (t_dir[2] << 8) | t_dir[3];
		tmp->cur = (tmp->cur + DIR_SIZE) % MEM_SIZE;
		// и если второй аргумент REG
		if (b2[2] == 0 && b2[3] == 1)
		{
			ft_memcpy(t_reg, tmp->cur, 1);
			tmp->cur = (tmp->cur + 1) % MEM_SIZE;
			//Один нюанс, если T_REG не последний аргумент в функции,
			//то нужно использовать значения из регистра каретки, т.е. argument1 = karetka->[T_REG].
			tmp->reg[t_reg] = t_dir;
			tmp->carry = (t_dir == 0) ? 1 : 0
		}
		else if ((b2[4] == 0 && b2[5] == 1) || (b2[6] == 0 && b2[7] == 1))
		{

		}
	}
	// else if (b2[0] == 0 && b2[1] == 1)
	// 	printf("T_REG\n");
	else if (b2[0] == 1 && b2[1] == 1) //T_IND - 2 байта
	{	
		ft_memcpy(t_ind, (cor->code + tmp->cur) % MEM_SIZE, IND_SIZE);
		tmp->cur = (tmp->cur + IND_SIZE) % MEM_SIZE;
		t_ind = (t_ind % IDX_MOD) % MEM_SIZE;
		ft_memcpy(t_reg, tmp->cur + t_ind, 1);
		tmp->cur = (tmp->cur + 1) % MEM_SIZE;
		tmp->reg[t_reg] = t_dir;
		tmp->carry = (t_dir == 0) ? 1 : 0
		printf("T_IND = %d \n", t_ind);
	}
	if ((b2[4] != 0 && b2[5] != 0) || (b2[6] != 0 && b2[7] != 0))
	{
		printf("ERROR????\n");

	}
}

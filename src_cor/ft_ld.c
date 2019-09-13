#include "corewar.h"

int valid_ld(char *b2)
{
	int i;
	unsigned char t_reg;

	i = 0;
	t_reg = 0;

	//Поскольку данная операция принимает три аргумента,
	// мы рассматриваем значения только первых трех пар битов в коде типов.
	// Значения остальных пар нас не интересуют.

	if ( !(b2[2] == 0 && b2[3] == 1))
	{
		if (b2[0] == 0 && b2[1] == 1)
			{

			}
			else if (b2[0] == 1 && b2[1] == 0)
			{

			}
			else if (b2[0] == 1 && b2[1] == 1)
			{

			}
	}


}

void ft_ld(t_cor *cor, t_carr *tmp)
{
	int cur;
	unsigned char	c[1];//codage octal
	char *b2;
	unsigned char t_dir[DIR_SIZE];
	unsigned char t_ind[IND_SIZE];
	 // T_REG занимает только 1 байт
	unsigned char t_reg;//Название регистра (r1, r2...) в байт-коде занимает 1 байт. Но сам регистр вмещает в себя 4 байта, как указано в константе REG_SIZE.

//codage octal
	// сдвиг на операцию
	cur = 1;
	// сдвиг на аргументы
	cur += 1;

	ft_memcpy(c, cor->code + (tmp->cur + 1) % MEM_SIZE, 1); //У 02 команды load - codage 1, значит мы считываем первое число после команды
	printf("c + 1 = %x\n", c[0]);
	tmp->cur = (tmp->cur + 2) % MEM_SIZE;
	b2 = base16_2(c[0]); // 90 = 144 = 10 01 00 00

	//if (((b2[0] == 1 && b2[1] == 0) || (b2[0] == 1 && b2[1] == 1)) && (b2[2] == 0 && b2[3] == 0) && (b2[4] == b2[5] && b2[4] == 0))

	//printf("c2 = %d\n", b2[0] == 1);
	// какой аргумент t_dir?
	int i;
	i = 0;
	if (b2[0] == 1 && b2[1] == 0 ) // T_DIR
	{
		ft_memcpy(t_dir, cor->code + (tmp->cur) % MEM_SIZE, DIR_SIZE); //Число 2 или 4 байта в зависимости от label ХЗ
		printf("T_DIR = %d %d %d %d \n", t_dir[0], t_dir[1], t_dir[2], t_dir[3]); //T_DIR - столько байтов сколько указано в label_size у команды
		//t_dir = (t_dir[0] << 24) | (t_dir[1] << 16) | (t_dir[2] << 8) | t_dir[3]);
		tmp->cur = (tmp->cur + DIR_SIZE) % MEM_SIZE;
		// и если второй аргумент REG
		if (b2[2] == 0 && b2[3] == 1)
		{
			ft_memcpy_all(&t_reg,  cor->code + tmp->cur, 1);
			tmp->cur = (tmp->cur + 1) % MEM_SIZE;
			//Один нюанс, если T_REG не последний аргумент в функции,
			//то нужно использовать значения из регистра каретки, т.е. argument1 = karetka->[T_REG].
			//ft_memcpy();
			if ((int)t_reg >= 0 && (int)t_reg < REG_NUMBER)
			{
				tmp->reg[(int)t_reg] = *((int*)t_dir);
				tmp->carry = (*((int*)t_dir) == 0) ? 1 : 0;
				// и передвинуть каретку
			}

		}
		else if ((b2[4] == 0 && b2[5] == 1) || (b2[6] == 0 && b2[7] == 1))
		{

		}
	}
	// else if (b2[0] == 0 && b2[1] == 1)
	// 	printf("T_REG\n");
	else if (b2[0] == 1 && b2[1] == 1) //T_IND - 2 байта
	{	
		ft_memcpy(t_ind, cor->code + (tmp->cur) % MEM_SIZE, IND_SIZE);
		tmp->cur = (tmp->cur + IND_SIZE) % MEM_SIZE;

		//t_ind = ((int)t_ind % IDX_MOD);
		int a = 0;
		a = ((t_ind[0] << 8) | t_ind[1]);
		ft_memcpy(&t_dir, cor->code + (tmp->cur + a) % MEM_SIZE, 1);
		ft_memcpy_all(&t_reg,  cor->code + tmp->cur, 1);
		//tmp->cur = (tmp->cur + 1) % MEM_SIZE;
		tmp->reg[(int)t_reg] = *((int*)t_dir);
		tmp->carry = (*((int*)t_dir) == 0) ? 1 : 0;
		//printf("T_IND = %d \n", t_ind);
	}
	if ((b2[4] != 0 && b2[5] != 0) || (b2[6] != 0 && b2[7] != 0))
	{
		printf("ERROR????\n");

	}
}

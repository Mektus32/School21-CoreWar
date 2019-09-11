#include "corewar.h"

void ft_ld(t_cor *cor, int i)
{
	unsigned char	c[1];
	char *b2;
	unsigned char t_dir[4];
	//	unsigned int t_dir;
	//short		t_dir;
	unsigned char t_reg[1];

	//int				registe[REG_NUMBER];


	ft_memcpy(c, cor->code + i, 1); //У 02 команды load - codage 1, значит мы считываем первое число после команды
	printf("c + 1 = %x\n", c[0]);

	b2 = base16_2(c[0]); // 90 = 144 = 10 01 00 00
	printf("c2 = %d\n", b2[0] == 1);


	if (b2[0] == 1 && b2[1] == 0 ) // T_DIR
	{
		ft_memcpy(t_dir, cor->code + i + 1, 4); //Число 2 или 4 байта в зависимости от label ХЗ
		printf("T_DIR\n"); //T_DIR - столько байтов сколько указано в label_size у команды

	}
	else if (b2[0] == 0 && b2[1] == 1)
		printf("T_REG\n");
	else if (b2[0] == 1 && b2[1] == 1) //T_IND - 2 байта
		printf("T_IND\n");


	if (b2[2] == 1 && b2[3] == 0)
	{
		printf("T_DIR\n");

	}
	else if (b2[2] == 0 && b2[3] == 1)  // T_REG занимает только 1 байт
	{
		printf("T_REG\n");
		ft_memcpy_all(t_reg, cor->code + i + 1 + 4, 1);
	}
	else if (b2[2] == 1 && b2[3] == 1)
		printf("T_IND\n");

	if (b2[4] == 1 && b2[5] == 0)
		printf("T_DIR\n");
	else if (b2[4] == 0 && b2[5] == 1)
		printf("T_REG\n");
	else if (b2[4] == 1 && b2[5] == 1)
		printf("T_IND\n");

	//registe[t_reg] = t_dir;

}

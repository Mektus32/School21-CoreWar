#include "corewar.h"
int ft_ld_write(t_cor *cor, t_carr *tmp, int i, int l)
{
	int a;
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];
	unsigned char t_reg;//Название регистра (r1, r2...) в байт-коде занимает 1 байт. Но сам регистр вмещает в себя 4 байта, как указано в константе REG_SIZE.

	a = 0;
	if (i == 5)
	{
		ft_memcpy(t_ind, cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, IND_SIZE);
		if (l)
			a = ((t_ind[0] << 8) | t_ind[1]);
		else
			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
	}


//	int k = 0;
//	printf("code  = |||");
//	while (k < 10)
//		printf("%x/",cor->code + (tmp->cur + 1 + 1 + a + k++)% MEM_SIZE);
//	printf("||| \n");

	ft_memcpy(&t_dir, cor->code + (tmp->cur + 1 + 1 + a) % MEM_SIZE, DIR_SIZE);
	//printf("code  = %s\n",cor->code + (tmp->cur + 1 + 1 + a));

	ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + (i - 1)) % MEM_SIZE, 1);
	if ((int)t_reg > 0 && (int)t_reg < REG_NUMBER)
	{
	//	ft_memcpy_all(tmp->reg[(int)t_reg], (void *)t_dir, 4);
		//k = IFR16(t_dir);//(t_dir[0] << 24) | (t_dir[1] << 16) | (t_dir[2] << 8) | t_dir[3];
		tmp->reg[(int)t_reg] = (IFR16(t_dir));
	//	ft_memcpy_all((tmp->reg[(int)t_reg]),  t_dir, 4);
//когда о все работало нормально
//		tmp->reg[(int)t_reg] = *((int*)t_dir);
		tmp->carry = (tmp->reg[(int)t_reg] == 0) ? 1 : 0;

//		tmp->carry = (*((int*)t_dir) == 0) ? 1 : 0;
	//	tmp->cur = (tmp->cur + i) % MEM_SIZE;
		//printf("ok\n");
		return (0);
	}
	else
		return (1);
}

void ft_ld(t_cor *cor, t_carr *tmp, int l)
{
	// когда сюда заходим, знаем что операция валидна но не передвигаем до этого
	unsigned char	c[1];//codage octal
	char *b2;
	int f_err; // флаг, сообщающей об оштбке аргументов = 0, если ошибки нет
	int i;

	i = 1;// операция валидна уже знаем
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1); //У 02 команды load - codage 1, значит мы считываем первое число после команды

	//ft_memcpy(c, cor->code + (tmp->cur + i) % MEM_SIZE, 1); //У 02 команды load - codage 1, значит мы считываем первое число после команды

	printf("c + 1 = %x\n", c[0]);
	b2 = base16_2(c[0]); // 90 = 144 = 10 01 00 00

	if ((b2[0] == 1 && b2[1] == 0) || (b2[0] == 1 && b2[1] == 1))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];//i += 4;
	else if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
		f_err = 1;
	}
	else
		f_err = 1;
	// и второй аргумент надо проверить
	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		// надо проверить еслт ли такой регистр - записать, если все нормалбно
		if (i == 5 || i == 7)
			f_err = ft_ld_write(cor, tmp, i, l);
		else
			f_err = 1;
	}
	else if ((b2[2] == 1 && b2[3] == 1) || b2[2] == 1 && b2[3] == 0)
	{
		f_err = 1;
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	}
	else
		f_err = 1;
//	if (f_err)
//		tmp->cur = (tmp->cur + i) % MEM_SIZE;
	tmp->i = i;
}

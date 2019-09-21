#include "corewar.h"

void ft_st(t_cor *cor, t_carr *tmp)
{
	unsigned char	c[1];
	unsigned char t_ind[IND_SIZE];
	unsigned char t_reg;
	unsigned char t_reg_2;
	char *b2;
	int f_err;
	int i;
	int a;
	unsigned char *p;

	i = 1;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1); //У 02 команды load - codage 1, значит мы считываем первое число после команды
	printf("c + 1 = %x\n", c[0]);
	b2 = base16_2(c[0]); // 90 = 144 = 10 01 00 00

	if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	else if (b2[0] == 1 && b2[1] == 0)
	{
		i += 4;
		f_err = 1;
	}
	else if (b2[0] == 1 && b2[1] == 1)
	{
		i += 2;
		f_err = 1;
	}
	else
		f_err;

	if ((b2[2] == 0 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 1))
	{
		if (i == 3)
		{
			a = 0;
			// считаем из 1 ого параметра значение регистра
			ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
			if ((int)t_reg >= 0 && (int)t_reg < REG_NUMBER)
			{
				if (b2[2] == 1)
				{
					ft_memcpy(t_ind, cor->code + (tmp->cur + 1 + 1 + 1) % MEM_SIZE, IND_SIZE);
					a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
					p = inttobyte(tmp->reg[(int) t_reg]);
					ft_memcpy_all(cor->code + (tmp->cur + a) % MEM_SIZE, p, 4);
					i += 2;
				}
				else
				{
					i += 1;
					ft_memcpy_all(&t_reg_2,  cor->code + (tmp->cur + 1 + 1 + 1 + a) % MEM_SIZE, 1);
					if ((int)t_reg_2 >= 0 && (int)t_reg_2 < REG_NUMBER)
					{
						tmp->reg[(int)t_reg_2] = (int)tmp->reg[(int)t_reg];
						// нужно ли удалять из рег первого значение?
					}
					else
						f_err = 1;
				}
			}
			else
				f_err = 1;

		}
		else
		{
			f_err = 1;
			i = i + (b2[2] == 0 ? 1 : 2);
		}
	}
	else if (b2[2] == 1 && b2[3] == 0)
	{
		i += 4;
		f_err = 1;
	}
	else
		f_err = 1;
	//tmp->cur = (tmp->cur + i) % MEM_SIZE;
	tmp->i = i;



}
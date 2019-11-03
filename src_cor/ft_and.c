#include "corewar.h"




void    ft_and(t_cor *cor, t_carr *tmp)
{
	int a1;
	int a2;
	unsigned char t_reg_3;
	char *b2;
	int f_err;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	a1 = arg_4(b2, tmp, cor, &f_err);
	a2 = arg_4(b2 + 2, tmp, cor, &f_err);
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if ((VAL_REG(t_reg_3)) && !f_err)
		{
			tmp->reg[t_reg_3 - 1] = a1 & a2;
			tmp->carry = (tmp->reg[t_reg_3 - 1] == 0) ? 1 : 0;
		}


	}
	else
		tmp->i += 4 * (int)b2[4] - 2 * (int)b2[5];
	free(b2);
}

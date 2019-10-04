#include "corewar.h"

void    ft_and(t_cor *cor, t_carr *tmp)
{
	int a1;
	int a2;
	unsigned char t_reg_3;
	char *b2;
	int f_err;
	int i;
	short			t_ind;
	unsigned int	t_dir;

	i = 2;
	f_err = 0;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + i++);
		a1 = (int)t_reg_3;
		if (!(t_reg_3 > 0 && t_reg_3 <= REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		t_ind = 0;
		if (b2[1] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + i);
		}
		// точно ли не надо сначало по i еще подвинуться?
		t_dir = read_byte_4(cor->code, tmp->cur + t_ind % IDX_MOD);
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		a1 = t_dir;
	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + i++);
		if (!(t_reg_3 > 0 && (t_reg_3) <= REG_NUMBER))
			f_err = 1;
		a2 = t_reg_3;
	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
	{
		t_ind = 0;
		if (b2[3] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + i);
		}
		t_dir = read_byte_4(cor->code, tmp->cur + t_ind % IDX_MOD);
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		a2 = t_dir;
	}
	else
		f_err = 1;
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + i++);
		if ((t_reg_3 > 0 && (t_reg_3) <= REG_NUMBER) && !f_err)
		{
			tmp->reg[(int)t_reg_3 - 1] = a1 & a2;
			tmp->carry = (tmp->reg[(int)t_reg_3 - 1] == 0) ? 1 : 0;
		}
	}
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	tmp->i = i;
	free(b2);
}

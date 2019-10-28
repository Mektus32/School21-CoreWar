
#include "corewar.h"

/*
** я не знаю чит ли это
** //		if (((int)t_reg > 0 && (int)(t_reg) <= REG_NUMBER) &&
** //			((int)t_reg_2 > 0 && (int)(t_reg_2) <= REG_NUMBER) &&
** //				((int)t_reg_3 > 0 && (int)(t_reg_3) <= REG_NUMBER))
** запихнуть в дифайн
*/

void				ft_add(t_cor *cor, t_carr *tmp)
{
	unsigned char	t_reg;
	unsigned char	t_reg_2;
	unsigned char	t_reg_3;
	char			*b2;
	int 			f_err;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	if (b2[0] == 0 && b2[1] == 1)
		t_reg = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[0] - 2 * b2[1];
	if (b2[2] == 0 && b2[3] == 1)
		t_reg_2 = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[2] - 2 * b2[3];
	if (b2[4] == 0 && b2[5] == 1)
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[4] - 2 * b2[5];
	if (tmp->i == 5 && (!f_err) && VAL_REG(t_reg) && VAL_REG(t_reg_2) && VAL_REG(t_reg_3))
	{
			tmp->reg[t_reg_3 - 1] = tmp->reg[t_reg - 1] +
					tmp->reg[t_reg_2 - 1];

	}
	tmp->carry = (tmp->reg[t_reg_3 - 1] == 0) ? 1 : 0;
	free(b2);
}

void				ft_zjmp(t_cor *cor, t_carr *tmp)
{
	short	t_ind;
	short	a;

	if (tmp->carry == 1)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + 1);
		a = idx_mod(t_ind);
		tmp->cur = mem_size(tmp->cur + a);
		tmp->i = 0;
	}
	else
		tmp->i = 3;
}

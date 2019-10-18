
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

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
		t_reg = read_byte_1(cor->code, (tmp->cur + tmp->i++));
	else
		tmp->i += 4 * (int)b2[0] - 2 * (int)b2[1];
	if (b2[2] == 0 && b2[3] == 1)
		t_reg_2 = read_byte_1(cor->code, (tmp->cur + tmp->i++));
	else
		tmp->i += 4 * (int)b2[2] - 2 * (int)b2[3];
	if (b2[4] == 0 && b2[5] == 1)
		t_reg_3 = read_byte_1(cor->code, (tmp->cur + tmp->i++));
	else
		tmp->i += 4 * (int)b2[4] - 2 * (int)b2[5];
	if (tmp->i == 5 && VAL_REG(t_reg) && VAL_REG(t_reg_2) && VAL_REG(t_reg_3))
	{
			tmp->reg[(int)t_reg_3 - 1] = (int)tmp->reg[(int)t_reg - 1] +
					(int)tmp->reg[(int)t_reg_2 - 1];
			tmp->carry = (tmp->reg[(int)t_reg_3 - 1] == 0) ? 1 : 0;
	}
	free(b2);
}

void				ft_zjmp(t_cor *cor, t_carr *tmp)
{
	short	t_ind;
	short	a;

	if (tmp->carry == 1)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + 1);
		while (t_ind < 0)
			t_ind += MEM_SIZE;
		a = (t_ind) % IDX_MOD;
//		while (a < 0)
//			a += MEM_SIZE;
		tmp->cur = tmp->cur + a;
//		while (tmp->cur < 0)
//			tmp->cur = tmp->cur + MEM_SIZE;
//		tmp->cur = tmp->cur % MEM_SIZE;
		tmp->i = 0;
	}
	else
		tmp->i = 3;
}

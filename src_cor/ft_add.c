#include "corewar.h"

void    ft_add(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	char *b2;
	int i;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
		t_reg = read_byte_1(cor->code, (tmp->cur + i++));
	else
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	if (b2[2] == 0 && b2[3] == 1)
		t_reg_2 = read_byte_1(cor->code, (tmp->cur + i++));
	else
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
	if (b2[4] == 0 && b2[5] == 1)
		t_reg_3 = read_byte_1(cor->code, (tmp->cur + i++));
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	if (i == 5)
	{
		if (((int)t_reg > 0 && (int)(t_reg) <= REG_NUMBER) &&
			((int)t_reg_2 > 0 && (int)(t_reg_2) <= REG_NUMBER) &&
				((int)t_reg_3 > 0 && (int)(t_reg_3) <= REG_NUMBER))
		{
			tmp->reg[(int)t_reg_3 - 1] = (int)tmp->reg[(int)t_reg - 1] + (int)tmp->reg[(int)t_reg_2 - 1];
			tmp->carry = (tmp->reg[(int)t_reg_3 - 1] == 0) ? 1 : 0;
		}
	}
	free(b2);
	tmp->i = i;
}

void	ft_zjmp(t_cor *cor, t_carr *tmp)
{
	short	t_ind;
	short		a;

	if (tmp->carry == 1)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + 1);
		a = ((unsigned int)t_ind) % IDX_MOD;
		//tmp->cur = tmp->cur + a;
		tmp->i = a;
	}
	else
		tmp->i = 3;
	//МААААААААААААТ
}




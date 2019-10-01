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
		ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + 2 + i++), 0);
	else
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	if (b2[2] == 0 && b2[3] == 1)
		ft_memcpy_all(&t_reg_2,  cor->code , 1, (tmp->cur + 2 + i++), 0);
	else
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
	if (b2[4] == 0 && b2[5] == 1)
		ft_memcpy_all(&t_reg_3,  cor->code, 1, (tmp->cur + 2 + i++), 0);
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	if (i == 5)
	{
		if (((int)t_reg > 0 && (int)(t_reg) < REG_NUMBER) &&
			((int)t_reg_2 > 0 && (int)(t_reg_2) < REG_NUMBER) &&
				((int)t_reg_3 > 0 && (int)(t_reg_3) < REG_NUMBER))
		{
			tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg] + tmp->reg[(int)t_reg_2];
			tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
		}
	}
	free(b2);
	tmp->i = i;
}







void    ft_zjmp(t_cor *cor, t_carr *tmp)
{
	unsigned char t_ind[IND_SIZE];
	int a;

	if (tmp->carry == 1)
	{
		ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 1), 0);
		a = IFR8(t_ind) % IDX_MOD;//((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		tmp->cur = (tmp->cur + a) % MEM_SIZE;
	}
	tmp->i = 3;

}




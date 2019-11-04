#include "corewar.h"
/*
** 4 * (int)b2[0] - 2 * (int)b2[1];
** если t_dir 10 4*1 - 2*0 = 4
** если t_ind 11 4*1 - 2*2 = 2
** если 00 = 0
*/

void	ft_aff(t_cor *cor, t_carr *tmp)
{
	unsigned char	t_reg;
	char			*b2;
	int				i;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg = read_byte_1(cor->code, (tmp->cur + i++));
		if (VAL_REG(t_reg))
			ft_putchar((char)tmp->reg[(int)t_reg]);
	}
	else
		i = i + 4 * (int)b2[0] - 2 * (int)b2[1];
	tmp->i = i;
	free(b2);
}
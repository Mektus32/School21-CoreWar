#include "corewar.h"

void    ft_aff(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	char *b2;
	int i;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
	{
		i++;
		ft_memcpy_all(&t_reg,  cor->code, 1,  (tmp->cur + 2));
		if (((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
			ft_putchar((char)tmp->reg[(int)t_reg]);
	}
	else
		i = i + 4 * (int)b2[0] - 2 * (int)b2[1];
	tmp->i = i;
}
#include "corewar.h"

void print_dump_code(t_cor *cor)
{
	int i;


	i = 0;
	ft_printf("%05p: ", cor->code[i] - cor->code[i]);
	while (i < MEM_SIZE)
	{
		if (i % (64) == 0 && i != 0)
		{
			ft_putchar('\n');
			ft_printf("%p: ", cor->code[i] - cor->code[0]);

		}
		ft_printf("%.2x ", cor->code[i]);

		i++;
	}
}

//-dump 10 ../vm_champs/champs/championships/2018/sboulet/Hidden.cor
// ../vm_champs/champs/championships/2018/sboulet/NoIdea.cor
// ../vm_champs/champs/championships/2018/bcozic/sencha.cor
#include "corewar.h"

void print_dump_code(t_cor *cor)
{
	int i;


	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0)
			ft_putchar('\n');
		ft_printf("%.2x ",cor->code[i]);

		i++;
	}
}
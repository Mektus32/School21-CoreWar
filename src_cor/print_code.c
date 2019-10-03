#include "corewar.h"

void print_dump_code(t_cor *cor)
{
	int i;
	int k;

	k = 0;
	i = 0;
	printf("%.4p : ", k);
	while (i < MEM_SIZE)
	{
		if (i % (64) == 0 && i != 0)
		{
			k++;
			printf("\n");
			printf("%.4p : ", k * 64);
		}
		if (cor->code[i] < 0)
			printf("%.2x ", 256 - -1 * cor->code[i]);
		else
			printf("%.2x ", cor->code[i]);

		i++;
	}
}

//-dump 10 ../vm_champs/champs/championships/2018/sboulet/Hidden.cor
// ../vm_champs/champs/championships/2018/sboulet/NoIdea.cor
// ../vm_champs/champs/championships/2018/bcozic/sencha.cor
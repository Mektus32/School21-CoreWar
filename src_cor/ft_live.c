#include "corewar.h"

void	ft_live(t_cor *cor, int i)
{
	unsigned char	c[1];
	char *b2;





	ft_memcpy(c, cor->code + i, 1);
	printf("c + 1 = %x\n", c[0]);

	b2 = base16_2(c[0]);
	//if (b2 == )
	printf("c2 = %d\n", b2[0] == 1);


	if (b2[0] == 1 && b2[1] == 0)
		printf("T_DIR\n");
	else if (b2[0] == 0 && b2[1] == 1)
		printf("T_REG\n");
	else if (b2[0] == 1 && b2[1] == 1)
		printf("T_IND\n");
}


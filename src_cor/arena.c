#include "corewar.h"

/*
**	//После того, как на арене были размещены исполняемые коды чемпионов, на начало каждого из них устанавливается каретка.
* // надо создать список для всех кареток - добавляем сверху сверху начинаем заполнять
** cor->carr = carr_list(cor);
 */

void	arena(t_cor *cor)
{

	int i;
	char *code_i;

	cor->code = (char *)ft_memalloc(sizeof(char) * MEM_SIZE);
	cor->live = (t_live *)ft_memalloc(sizeof(t_live));
	cor->colormap = (int *)ft_memalloc(sizeof(int) * MEM_SIZE);
	i = 0;
	while (i < cor->n)
	{
		code_i = cor->code + i * (MEM_SIZE / cor->n);
		ft_strncpy_all((code_i), cor->m_ch[i]->code, cor->m_ch[i]->prog_size);
		i++;
	}
	cor->carr = carr_list(cor);

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < cor->n)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
				  (cor->m_ch[i])->prog_size, (cor->m_ch[i])->prog_name,
				  (cor->m_ch[i])->comment);
		i++;
	}
//	ft_printf("=============\n");
//	print_dump_code(cor);
//	ft_printf("=============\n");
	go_cor(cor);
	//ft_printf("end = %d\n", cor->live->cycles);
	ft_printf("Contestant %d, \"%s\", has won !\n", cor->live->id_live, (cor->m_ch[cor->live->id_live - 1])->prog_name);
	free_cor(cor);

}

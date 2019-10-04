#include "corewar.h"

/*
 * 1. тут дир по 2 байта
 *
 * */

void    ft_sti(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	char *b2;
	unsigned char *p;
	int f_err;
	int i;
	int l;
	short			t_ind;
	short	t_dir;
	unsigned int	t_dir_1;

	i = 2;
	l = 0;
	f_err = 0;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg = read_byte_1(cor->code, tmp->cur + i++);
		if (!(t_reg > 0 && (t_reg) <= REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		f_err = 1;
		i += 2;
	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		t_reg_2 = read_byte_1(cor->code, tmp->cur + i++);
		if (!((t_reg_2 > 0) && t_reg_2 <= REG_NUMBER))
			f_err = 1;
		else
			l = l +  tmp->reg[t_reg_2 - 1];

	}
	else if ((b2[2] == 1 && b2[3] == 0) || (b2[2] == 1 && b2[3] == 1))
	{
		t_ind = 0;
		if (b2[3] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + i);
			i += 2;
		}
		t_dir = read_byte_2(cor->code, (tmp->cur + i + t_ind) % IDX_MOD);
		i += 2;
		l = l + t_dir;
	}
	else
		f_err = 1;
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg_2 = read_byte_1(cor->code, tmp->cur + i++);
		if (!(((t_reg_2) > 0) && (t_reg_2) <= REG_NUMBER))
			f_err = 1;
		else
			l = l + tmp->reg[t_reg_2 - 1];
	}
	else if (b2[4] == 1 && b2[5] == 0)
	{
		t_dir_1 = read_byte_2(cor->code, (tmp->cur + i) % IDX_MOD);
		i += 2;
		l = l + t_dir_1;
	}
	else
	{
		i += 2;
		f_err = 1;
	}

	if (!f_err)
	{

//
//	unsigned char	c[1];
//		write(1,"!!\n",3);
//		int k = 0;
//		while (k < 8)
//		{
//			ft_memcpy(c, (cor->code + tmp->cur +  (l + k++) % IDX_MOD % MEM_SIZE), 1);
//			ft_printf("|%x| %x|\n",c[0], c[1]);
//		}
		p = inttobyte(tmp->reg[t_reg - 1]);
		//printf("tmp->reg[t_reg] = %d\n", tmp->reg[t_reg]);
		copy_p(cor->code, p, tmp->cur + l % IDX_MOD, 0);
//
//		write(1,"!!\n",3);
//		k = 0;
//		while (k <8)
//		{
//			ft_memcpy(c, (cor->code + tmp->cur + (l + k++) % IDX_MOD % MEM_SIZE), 1);
//			ft_printf("|%x| %x|\n",c[0], c[1]);
//		}
		free(p);
	}
	//ft_printf("tmp_num = %d, tmp_car = %d, l = %d, IDX_MOD = %d\n", tmp->num, tmp->cur, l, (tmp->cur+ l) % IDX_MOD);
	free(b2);

	tmp->i = i;

}

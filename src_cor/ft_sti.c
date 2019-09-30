#include "corewar.h"

void    ft_sti(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	char *b2;
	int f_err;
	int i;
	int a;
	int l;
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];
	unsigned char t_dir_1[DIR_SIZE];

	i = 2;
	l = 0;
	f_err = 0;
	b2 = base16_2_cor(cor, tmp);

	if (b2[0] == 0 && b2[1] == 1)
	{
		ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + i++));
		if (!((int)t_reg > 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		f_err = 1;
		i = i + 4 * (int)b2[0] - 2 * (int)b2[1];
	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		ft_memcpy_all(&t_reg_2,  cor->code, 1, (tmp->cur + 1 + i++));
		if (!(((int)t_reg_2) > 0) && (int)(t_reg_2) < REG_NUMBER)
			f_err = 1;
		else
			l = l +  tmp->reg[(int) t_reg_2];
			//a = a + tmp->reg[(int) t_reg_2];
	}
	else if ((b2[2] == 1 && b2[3] == 0) || (b2[2] == 1 && b2[3] == 1))
	{
		a = 0;
		if (b2[3] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 1 + 1 + i));
			a = IFR8(t_ind);
		}
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + 1 + 1 + i +  a) % IDX_MOD);
		l = l + IFR16(t_dir);
	}
	else
		f_err = 1;
	if (b2[4] == 0 && b2[5] == 1)
	{
		ft_memcpy_all(&t_reg_2,  cor->code, 1, (tmp->cur + 1 + i++));
		if (!(((int)t_reg_2) > 0) && (int)(t_reg_2) < REG_NUMBER)
			f_err = 1;
		else
			l = l + tmp->reg[(int) t_reg_2];
	}
	else if (b2[4] == 1 && b2[5] == 0)
	{
		i += 4;
		ft_memcpy_all(t_dir_1, cor->code, DIR_SIZE, (tmp->cur + 1 + 1 + i));
		l = l + IFR16(t_dir_1);
	}
	else
	{
		i += 2;
		f_err = 1;
	}

	if (!f_err)
	{

		//ft_memcpy_all(&(tmp->reg[(int) t_reg]),  1, 1);
		//	tmp->reg[(int) t_reg] = inttobyte(tmp->reg[(int) t_reg]);
//		unsigned char	c[1];
//
//		write(1,"!!\n",3);
//		int k = 0;
//		while (k < 10)
//		{
//			ft_memcpy(c, (cor->code + (tmp->cur + 1 + 1 + l + k++) % IDX_MOD % MEM_SIZE), 1);
//			printf("|%x| %x|\n",c[0], c[1]);
//		}
		unsigned char *p;

		p = inttobyte(tmp->reg[(int) t_reg]);
		ft_memcpy_all(cor->code + (tmp->cur + 1 + 1 + l) % IDX_MOD , p, 4, 0);
//
//		write(1,"!!\n",3);
//		k = 0;
//		while (k < 10)
//		{
//			ft_memcpy(c, (cor->code + (tmp->cur + 1 + 1 + l + k++) % IDX_MOD % MEM_SIZE), 1);
//			printf("|%x| %x|\n",c[0], c[1]);
//		}
//		free(p);
	}

	tmp->i = i;

}

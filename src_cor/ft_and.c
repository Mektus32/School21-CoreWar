#include "corewar.h"

// точно ли не надо сначало по i еще подвинуться?

unsigned int arg_4(char *b2, t_carr *tmp, t_cor *cor,  int *f_err)
{
	unsigned int				a1;
	unsigned char	t_reg_3;
	short			t_ind;
	unsigned int	t_dir;

	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		a1 = tmp->reg[t_reg_3 - 1];
		if (!(VAL_REG(t_reg_3)))
			*f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		if (b2[1] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + tmp->i);
			while (t_ind < 0)
				t_ind += MEM_SIZE;
			t_dir = read_byte_4(cor->code, tmp->cur +tmp->i + t_ind % IDX_MOD);//++ tmp->i???
			tmp->i += 2;
		}
		else
		{
			t_dir = read_byte_4(cor->code, tmp->cur + tmp->i);
			tmp->i += 4;
		}
		a1 = t_dir;
	}
	else
	*f_err = 1;
	return (a1);
}

unsigned int arg_2(char *b2, t_carr *tmp, t_cor *cor,  int *f_err)
{
	unsigned int	a1;
	unsigned char	t_reg_3;
	short			t_ind;
	unsigned int	t_dir;

	a1 = 0;
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		a1 = tmp->reg[t_reg_3 - 1];
		if (!(VAL_REG(t_reg_3)))
			*f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		if (b2[1] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + tmp->i);
			while (t_ind < 0)
				t_ind += MEM_SIZE;
			t_dir = read_byte_4(cor->code, tmp->cur /*+ tmp->i*/ + t_ind % IDX_MOD);
			a1 = t_dir;
		}
		else
		{
			t_ind = read_byte_2(cor->code, tmp->cur + tmp->i);
			a1 = t_ind;
		}
		tmp->i += 2;
	}
	else
		*f_err = 1;
	return (a1);
}


void    ft_and(t_cor *cor, t_carr *tmp)
{
	int a1;
	int a2;
	unsigned char t_reg_3;
	char *b2;
	int f_err;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	a1 = arg_4(b2, tmp, cor, &f_err);
	a2 = arg_4(b2 + 2, tmp, cor, &f_err);
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if ((VAL_REG(t_reg_3)) && !f_err)
		{
			tmp->reg[t_reg_3 - 1] = a1 & a2;

		}
		tmp->carry = (tmp->reg[t_reg_3 - 1] == 0) ? 1 : 0;

	}
	else
		tmp->i += 4 * (int)b2[4] - 2 * (int)b2[5];
//	if (b2[2] == 1 && b2[3] == 0)
//		tmp->i += 2;
//	if (b2[0] == 1 && b2[1] == 0)
//		tmp->i += 2;
	tmp->carry = (tmp->reg[t_reg_3 - 1] == 0) ? 1 : 0;
	free(b2);
}

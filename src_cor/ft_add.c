
#include "corewar.h"

int arg_4(char *b2, t_carr *tmp, t_cor *cor,  int *f_err)
{
	int				a1;
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
			t_ind = idx_mod(t_ind);
			t_dir = read_byte_4(cor->code, tmp->cur  + t_ind);
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

short arg_2(char *b2, t_carr *tmp, t_cor *cor,  int *f_err)
{
	short				a1;
	unsigned char	t_reg_3;
	short			t_ind;
	unsigned int	t_dir;

	a1 = 0;
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
		a1 = (short)tmp->reg[t_reg_3 - 1];
		if (!(VAL_REG(t_reg_3)))
			*f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		if (b2[1] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + tmp->i);
			t_ind = idx_mod(t_ind);
			t_dir = read_byte_2(cor->code, tmp->cur /*+ tmp->i*/ + t_ind);
			a1 = t_dir;
		}
		else
		{
			t_ind = read_byte_2(cor->code, tmp->cur + tmp->i);
			a1 = idx_mod(t_ind);
		}
		tmp->i += 2;
	}
	else
		*f_err = 1;
	return ((int)a1);
}

void				ft_add(t_cor *cor, t_carr *tmp)
{
	unsigned char	t_reg;
	unsigned char	t_reg_2;
	unsigned char	t_reg_3;
	char			*b2;
	int 			f_err;

	tmp->i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	if (b2[0] == 0 && b2[1] == 1)
		t_reg = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[0] - 2 * b2[1];
	if (b2[2] == 0 && b2[3] == 1)
		t_reg_2 = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[2] - 2 * b2[3];
	if (b2[4] == 0 && b2[5] == 1)
		t_reg_3 = read_byte_1(cor->code, tmp->cur + tmp->i++);
	else
		tmp->i += 4 * b2[4] - 2 * b2[5];
	if (tmp->i == 5 && (!f_err) && VAL_REG(t_reg) && VAL_REG(t_reg_2) && VAL_REG(t_reg_3))
	{
			tmp->reg[t_reg_3 - 1] = tmp->reg[t_reg - 1] +
					tmp->reg[t_reg_2 - 1];
		tmp->carry = (tmp->reg[t_reg_3 - 1] == 0) ? 1 : 0;
	}

	free(b2);
}

void				ft_zjmp(t_cor *cor, t_carr *tmp)
{
	short	t_ind;
	short	a;

	if (tmp->carry == 1)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + 1);
		a = idx_mod(t_ind);
		tmp->cur = mem_size(tmp->cur + a);
		//tmp->i = 3;
	}
	else
		tmp->i = 3;
	//tmp->carry = 0;
}

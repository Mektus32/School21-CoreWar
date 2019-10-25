#include "corewar.h"

int					ft_ld_write(t_cor *cor, t_carr *tmp, int i, int l)
{
	short			t_ind;
	unsigned int	t_dir;
	unsigned char	t_reg;

	t_dir = 0;
	if (i == 5)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + 2);
		while (t_ind < 0)
			t_ind += MEM_SIZE;
		t_ind = (l == 1) ? t_ind : t_ind % IDX_MOD;
		t_dir = read_byte_4(cor->code, (tmp->cur + t_ind));
	}
	else
		t_dir = read_byte_4(cor->code, tmp->cur + 2);
	t_reg = read_byte_1(cor->code, tmp->cur + (i - 1));
	if (VAL_REG(t_reg))
	{
		tmp->reg[t_reg - 1] = 0;
		tmp->reg[t_reg - 1] = t_dir;
		tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;
	}
	//tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;

	return (1);
}

void	ft_ld(t_cor *cor, t_carr *tmp, int l)
{
	char	*b2;
	int		i;
	int		f_err;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	f_err = 0;
	//f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	if ((b2[0] == 1 && b2[1] == 0) || (b2[0] == 1 && b2[1] == 1))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	else if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		if ((i == 5 || i == 7) && !f_err)
			ft_ld_write(cor, tmp, i, l);
	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	free(b2);
	tmp->i = i;
}

int					ft_lld_write(t_cor *cor, t_carr *tmp, int i)
{
	short			t_ind;
	unsigned int	t_dir;
	unsigned char	t_reg;

	t_dir = 0;
	t_ind = 0;
	if (i == 5)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + 2);
//		while (t_ind < 0)
//			t_ind += MEM_SIZE;
		//t_ind = (l == 1) ? t_ind : t_ind % IDX_MOD;
		t_ind = read_byte_2(cor->code, (tmp->cur + t_ind));
	}
	else
		t_dir = read_byte_2(cor->code, tmp->cur + 2);
	t_reg = read_byte_1(cor->code, tmp->cur + i - 1);
	if (VAL_REG(t_reg))
	{
		tmp->reg[t_reg - 1] = 0;
		tmp->reg[t_reg - 1] = (t_ind == 0) ? t_dir : t_ind;
		tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;
	}
	tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;

	return (1);
}

void	ft_lld(t_cor *cor, t_carr *tmp)
{
	char	*b2;
	int		i;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	if ((b2[0] == 1 && b2[1] == 0) || (b2[0] == 1 && b2[1] == 1))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	else if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		if (i == 5 || i == 7)
			ft_lld_write(cor, tmp, i);
	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	free(b2);
	tmp->i = i;
}


void    ft_ldi(t_cor *cor, t_carr *tmp, int l)
{
	unsigned char t_reg;
	char *b2;
	int f_err;
	int k;// на сколько надо передвинуть


	tmp->i = 2;
	k = 0;
	b2 = base16_2_cor(cor, tmp);
	f_err = (b2[6] == 0 && b2[7] == 0) ? 0 : 1;
	k += arg_2(b2, tmp, cor, &f_err);
	if (b2[2] == 0 && b2[3] == 1)
	{
		t_reg = read_byte_1(cor->code, (tmp->cur + tmp->i++));
		if (VAL_REG(t_reg))
			k += tmp->reg[(int)t_reg - 1];
		else
			f_err = 1;
//		while (k < 0)
//			k += MEM_SIZE;
	}
	else if ((b2[2] == 1 && b2[3] == 0))
	{
		//может и 2
		k += read_byte_4(cor->code, tmp->cur + tmp->i);
		tmp->i += 4;
	}
	else
	{
		tmp->i +=  2 * b2[2];
		f_err = 1;
	}
	if (b2[4] == 0 && b2[5] == 1)
	{
		t_reg = read_byte_1(cor->code, tmp->cur + tmp->i++);
		if (f_err == 0 && (VAL_REG(t_reg)))
		{
//			while (k < 0)
//				k += MEM_SIZE;
			tmp->reg[(int)t_reg - 1] =
				read_byte_4(cor->code, tmp->cur  + k % (IDX_MOD - l *  IDX_MOD + 1 * l));
			if (l)
				tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;
		}
	}
	else
		tmp->i += 2 * b2[4];
	free(b2);
}


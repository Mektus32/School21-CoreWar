#include "corewar.h"

void    ft_add(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	unsigned char	c[1];
	char *b2;
	int f_err;
	int i;

	i = 1;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);
	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
	}
	else
	{
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
		f_err = 1;
	}
	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
	}
	else
	{
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		f_err = 1;
	}
	if (b2[4] == 0 && b2[5] == 1)
	{
		i += 1;
	}
	else
	{
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		f_err = 1;
	}
	if (i == 5)
	{
		ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1 + 1) % MEM_SIZE, 1);
		ft_memcpy_all(&t_reg_2,  cor->code + (tmp->cur + 1 + 1 + 2) % MEM_SIZE, 1);
		ft_memcpy_all(&t_reg_3,  cor->code + (tmp->cur + 1 + 1 + 3) % MEM_SIZE, 1);
		if (((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER) &&
			((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER) &&
				((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER))
		{
			tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg] + tmp->reg[(int)t_reg_2];
			tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
			tmp->cur = (tmp->cur + i) % MEM_SIZE;
		}
		else
			f_err = 1;
	}
	if (f_err)
		tmp->cur = (tmp->cur + i) % MEM_SIZE;
}

void    ft_sub(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	unsigned char	c[1];
	char *b2;
	int f_err;
	int i;

	i = 1;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);
	if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	else
	{
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
		f_err = 1;
	}
	if (b2[2] == 0 && b2[3] == 1)
		i += 1;
	else
	{
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		f_err = 1;
	}
	if (b2[4] == 0 && b2[5] == 1)
		i += 1;
	else
	{
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		f_err = 1;
	}
	if (i == 5)
	{
		ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1 + 1) % MEM_SIZE, 1);
		ft_memcpy_all(&t_reg_2,  cor->code + (tmp->cur + 1 + 1 + 2) % MEM_SIZE, 1);
		ft_memcpy_all(&t_reg_3,  cor->code + (tmp->cur + 1 + 1 + 3) % MEM_SIZE, 1);
		if (((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER) &&
			((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER) &&
			((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER))
		{
			tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg] - tmp->reg[(int)t_reg_2];
			tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
			tmp->cur = (tmp->cur + i) % MEM_SIZE;
		}
		else
			f_err = 1;
	}
	if (f_err)
		tmp->cur = (tmp->cur + i) % MEM_SIZE;
}

void    ft_and(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	unsigned char	c[1];
	char *b2;
	int f_err;
	int i;
	int a;
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];
	unsigned char t_dir_1[DIR_SIZE];

	i = 1;
	a = 0;
	f_err = 0;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);

	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
		if ( !((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{

		a = 0;
		if (b2[0] == 1)
		{
			ft_memcpy(t_ind, cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, IND_SIZE);
			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		ft_memcpy(t_dir, cor->code + (tmp->cur + 1 + 1 + a) % MEM_SIZE, DIR_SIZE);
		a = 1;

	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		ft_memcpy_all(&t_reg_2,  cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
		if ((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER)
		{

		}
		else
			f_err = 1;
	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
	{

		a = 0;
		if (b2[2] == 1)
		{
			ft_memcpy(t_ind, cor->code + (tmp->cur + i) % MEM_SIZE, IND_SIZE);
			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		ft_memcpy(t_dir_1, cor->code + (tmp->cur + i + a) % MEM_SIZE, DIR_SIZE);
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		a = 2;
	}
	else
		f_err = 1;



	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		if (f_err == 0)
		{
			ft_memcpy_all(&t_reg_3,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
			if ((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER)
			{
				if (a == 0 && i == 5)
					tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg_2] & tmp->reg[(int)t_reg];
				else if (a == 1 && (i == 6 || i == 8))
					tmp->reg[(int)t_reg_3] = (int)t_dir & tmp->reg[(int)t_reg_2];
				else if (a == 2 && (i == 6 || i == 8))
					tmp->reg[(int)t_reg_3] = (int)t_dir_1 & tmp->reg[(int)t_reg];
				else if (a == 2 && (i == 7 || i == 9 || i == 11))
					tmp->reg[(int)t_reg_3] = (int)t_dir_1 & (int)t_dir;
				else
					f_err = 1;
				if (f_err == 0)
				{
					tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
					tmp->cur = (tmp->cur + i) % MEM_SIZE;
				}
			}
		}

	}
	else
	{
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		f_err = 1;
	}
	if (f_err)
		tmp->cur = (tmp->cur + i) % MEM_SIZE;
}

void    ft_or(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	unsigned char	c[1];
	char *b2;
	int f_err;
	int i;
	int a;
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];
	unsigned char t_dir_1[DIR_SIZE];

	i = 1;
	a = 0;
	f_err = 0;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);

	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
		if ( !((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{

		a = 0;
		if (b2[0] == 1)
		{
			ft_memcpy(t_ind, cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, IND_SIZE);
			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		ft_memcpy(t_dir, cor->code + (tmp->cur + 1 + 1 + a) % MEM_SIZE, DIR_SIZE);
		a = 1;

	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg_2,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
		if ((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER)
		{

		}
		else
			f_err = 1;
	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
	{

		a = 0;
		if (b2[2] == 1)
		{
			ft_memcpy(t_ind, cor->code + (tmp->cur + i) % MEM_SIZE, IND_SIZE);
			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		ft_memcpy(t_dir_1, cor->code + (tmp->cur + i + a) % MEM_SIZE, DIR_SIZE);
		a = 2;
	}
	else
		f_err = 1;



	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		if (f_err == 0)
		{
			ft_memcpy_all(&t_reg_3,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
			if ((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER)
			{
				if (a == 0 && i == 5)
					tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg_2] | tmp->reg[(int)t_reg];
				else if (a == 1 && (i == 6 || i == 8))
					tmp->reg[(int)t_reg_3] = (int)t_dir | tmp->reg[(int)t_reg_2];
				else if (a == 2 && (i == 6 || i == 8))
					tmp->reg[(int)t_reg_3] = (int)t_dir_1 | tmp->reg[(int)t_reg];
				else if (a == 2 && (i == 7 || i == 9 || i == 11))
					tmp->reg[(int)t_reg_3] = (int)t_dir_1 | (int)t_dir;
				else
					f_err = 1;
				if (f_err == 0)
				{
					tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
					tmp->cur = (tmp->cur + i) % MEM_SIZE;
				}
			}
		}

	}
	else
	{
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		f_err = 1;
	}
	if (f_err)
		tmp->cur = (tmp->cur + i) % MEM_SIZE;
}
void    ft_xor(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	unsigned char	c[1];
	char *b2;
	int f_err;
	int i;
	int a;
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];
	unsigned char t_dir_1[DIR_SIZE];

	i = 1;
	a = 0;
	f_err = 0;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);

	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
		if ( !((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{

		a = 0;
		if (b2[0] == 1)
		{
			ft_memcpy(t_ind, cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, IND_SIZE);
			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		ft_memcpy(t_dir, cor->code + (tmp->cur + 1 + 1 + a) % MEM_SIZE, DIR_SIZE);
		a = 1;

	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg_2,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
		if ((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER)
		{

		}
		else
			f_err = 1;
	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
	{

		a = 0;
		if (b2[2] == 1)
		{
			ft_memcpy(t_ind, cor->code + (tmp->cur + i) % MEM_SIZE, IND_SIZE);
			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[2] - 2 * (int)b2[3];
		ft_memcpy(t_dir_1, cor->code + (tmp->cur + i + a) % MEM_SIZE, DIR_SIZE);
		a = 2;
	}
	else
		f_err = 1;



	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		if (f_err == 0)
		{
			ft_memcpy_all(&t_reg_3,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
			if ((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER)
			{
				if (a == 0 && i == 5)
					tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg_2] ^ tmp->reg[(int)t_reg];
				else if (a == 1 && (i == 6 || i == 8))
					tmp->reg[(int)t_reg_3] = (int)t_dir ^ tmp->reg[(int)t_reg_2];
				else if (a == 2 && (i == 6 || i == 8))
					tmp->reg[(int)t_reg_3] = (int)t_dir_1 ^ tmp->reg[(int)t_reg];
				else if (a == 2 && (i == 7 || i == 9 || i == 11))
					tmp->reg[(int)t_reg_3] = (int)t_dir_1 ^ (int)t_dir;
				else
					f_err = 1;
				if (f_err == 0)
				{
					tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
					tmp->cur = (tmp->cur + i) % MEM_SIZE;
				}
			}
		}

	}
	else
	{
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		f_err = 1;
	}
	if (f_err)
		tmp->cur = (tmp->cur + i) % MEM_SIZE;
}

void    ft_zjmp(t_cor *cor, t_carr *tmp)
{
	unsigned char t_ind[IND_SIZE];
	int a;

	if (tmp->cur == 1)
	{
		ft_memcpy(t_ind, cor->code + (tmp->cur + 1) % MEM_SIZE, IND_SIZE);
		a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		tmp->cur = (tmp->cur + a) % MEM_SIZE;
		// НАДО ЛИ
		ft_memcpy(&tmp->prog, cor->code + tmp->cur, 1);		//ft_memcpy(&(tmp->prog), cor->code + (tmp->cur + a) % MEM_SIZE, 1);
		tmp->cycles_to = ft_cycles_to(tmp->prog);
	}
}

void    ft_ldi(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char t_reg_2;
	unsigned char t_reg_3;
	unsigned char	c[1];
	char *b2;
	int f_err;
	int i;
	int a;
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];
	unsigned char t_dir_1[DIR_SIZE];

	i = 1;
	a = 0;
	f_err = 0;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);

	if (b2[0] == 0 && b2[1] == 1)
	{
		i += 1;
		ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
		if ( !((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{

		a = 0;
		if (b2[0] == 1)
		{
			ft_memcpy(t_ind, cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, IND_SIZE);
			a = ((t_ind[0] << 8) | t_ind[1]) % IDX_MOD;
		}
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		ft_memcpy(t_dir, cor->code + (tmp->cur + 1 + 1 + a) % MEM_SIZE, DIR_SIZE);
		a = 1;

	}
	else
		f_err = 1;

	if (b2[2] == 0 && b2[3] == 1)
	{
		ft_memcpy_all(&t_reg_2,  cor->code + (tmp->cur + 1 + i++) % MEM_SIZE, 1);
		if ((int)t_reg_2 >= 0 && (int)(t_reg_2) < REG_NUMBER)
		{

		}
		else
			f_err = 1;
	}
	else if ((b2[2] == 1 && b2[3] == 0))
	{

		ft_memcpy(t_dir_1, cor->code + (tmp->cur + i) % MEM_SIZE, DIR_SIZE);
		i += 4;
		a = 2;
	}
	else
	{
			i += 4 * (int)b2[2] - 2 * (int)b2[3];
			f_err = 1;
	}



	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		if (f_err == 0)
		{
			ft_memcpy_all(&t_reg_3,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
			if ((int)t_reg_3 >= 0 && (int)(t_reg_3) < REG_NUMBER)
			{
				if (a == 0 && i == 5)
					tmp->reg[(int)t_reg_3] = tmp->reg[(int)t_reg_2] ^ tmp->reg[(int)t_reg];
				else if (a == 1 && (i == 6 || i == 8))
					tmp->reg[(int)t_reg_3] = (int)t_dir ^ tmp->reg[(int)t_reg_2];
				else if (a == 2 && (i == 6 || i == 8))
					tmp->reg[(int)t_reg_3] = (int)t_dir_1 ^ tmp->reg[(int)t_reg];
				else if (a == 2 && (i == 7 || i == 9 || i == 11))
					tmp->reg[(int)t_reg_3] = (int)t_dir_1 ^ (int)t_dir;
				else
					f_err = 1;
				if (f_err == 0)
				{
					tmp->carry = (tmp->reg[(int)t_reg_3] == 0) ? 1 : 0;
					tmp->cur = (tmp->cur + i) % MEM_SIZE;
				}
			}
		}

	}
	else
	{
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
		f_err = 1;
	}
	if (f_err)
		tmp->cur = (tmp->cur + i) % MEM_SIZE;
}
//
//void    ft_sti(t_cor *cor, t_carr *tmp)
//{
//
//}
//void    ft_fork(t_cor *cor, t_carr *tmp)
//{
//
//}
//
//void    ft_lld(t_cor *cor, t_carr *tmp)
//{
//
//}
//
//void    ft_lldi(t_cor *cor, t_carr *tmp);
//{
//
//}
//void    ft_lfork(t_cor *cor, t_carr *tmp)
//{
//
//}
void    ft_aff(t_cor *cor, t_carr *tmp)
{
	unsigned char t_reg;
	unsigned char	c[1];
	char *b2;
	int i;

	i = 1;
	ft_memcpy(c, cor->code + (tmp->cur + i++) % MEM_SIZE, 1);
	b2 = base16_2(c[0]);

	if (b2[0] == 0 && b2[1] == 1)
	{
		i++;
		ft_memcpy_all(&t_reg,  cor->code + (tmp->cur + 1 + 1) % MEM_SIZE, 1);
		if (((int)t_reg >= 0 && (int)(t_reg) < REG_NUMBER))
			ft_putchar((char)tmp->reg[(int)t_reg]);
	}
	else
		i = i + 4 * (int)b2[0] - 2 * (int)b2[1];
	tmp->cur = (tmp->cur + i) % MEM_SIZE;


}

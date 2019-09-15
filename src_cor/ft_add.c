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

//void    ft_and(t_cor *cor, t_carr *tmp)
//{
//
//}
//
//void    ft_or(t_cor *cor, t_carr *tmp)
//{
//
//}
//void    ft_xor(t_cor *cor, t_carr *tmp)
//{
//
//}
//
//void    ft_zjmp(t_cor *cor, t_carr *tmp)
//{
//
//}
//
//void    ft_ldi(t_cor *cor, t_carr *tmp)
//{
//
//}
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
//void    ft_aff(t_cor *cor, t_carr *tmp)
//{
//
//}


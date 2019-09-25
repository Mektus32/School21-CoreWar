/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:35:55 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/23 21:35:57 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_ld_write(t_cor *cor, t_carr *tmp, int i, int l)
{
	int				a;
	unsigned char	t_ind[IND_SIZE];
	unsigned char	t_dir[DIR_SIZE];
	unsigned char	t_reg;

	a = 0;
	if (i == 5)
	{
		ft_memcpy_all(&t_ind, cor->code, IND_SIZE, (tmp->cur + 1 + 1));
		a = (l == 1) ? IFR8(t_ind) : (IFR8(t_ind)) % IDX_MOD;
	}

	ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + 1 + 1 + a));
	//ft_memcpy(&t_dir, cor->code + (tmp->cur + 1 + 1 + a) % MEM_SIZE, IND_SIZE);

	ft_memcpy_all(&t_reg, cor->code, 1, (tmp->cur + (i - 1)));
	if ((int)t_reg > 0 && (int)t_reg < REG_NUMBER)
	{
		tmp->reg[(int)t_reg] = (IFR16(t_dir));
		tmp->carry = (tmp->reg[(int)t_reg] == 0) ? 1 : 0;
	}
	return (1);
}

void	ft_ld(t_cor *cor, t_carr *tmp, int l)
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
			ft_ld_write(cor, tmp, i, l);
	}
	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	free(b2);
//	if ((b2[2] == 1 && b2[3] == 0))
//		i = i - 2;
	tmp->i = i;
}

void    ft_ldi(t_cor *cor, t_carr *tmp, int l)
{
	unsigned char t_reg;
	char *b2;
	int f_err;
	int i;
	int a;
	int k;// на сколько надо передвинуть
	unsigned char t_ind[IND_SIZE];
	unsigned char t_dir[DIR_SIZE];
	unsigned char res[DIR_SIZE];

	i = 2;
	a = 0;
	f_err = 0;
	k = 0;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
	{
		ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + i++));
		if (!((int)t_reg > 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
		k = k + (int)t_reg;
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		a = 0;
		if (b2[1] == 1)
		{
			ft_memcpy_all(t_ind, cor->code, IND_SIZE, (tmp->cur + 2));
			a = IFR8(t_ind) % IDX_MOD;
		}
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
		ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + 2 + a));
		k = k + IFR16(t_dir);
	}
	else
		f_err = 1;
	if (b2[2] == 0 && b2[3] == 1)
	{
		ft_memcpy_all(&t_reg,  cor->code, 1, (tmp->cur + i++));
		if (!((int)t_reg > 0 && (int)(t_reg) < REG_NUMBER))
			f_err = 1;
		k = k + (int)t_reg;
	}
	else if ((b2[2] == 1 && b2[3] == 0))
	{
		ft_memcpy_all(t_dir, cor->code, DIR_SIZE, (tmp->cur + i));
		i += 4;
		k = k + IFR16(t_dir);
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
			ft_memcpy_all(&t_reg,  cor->code, 1, tmp->cur + i);
			if ((int)t_reg > 0 && (int)(t_reg) < REG_NUMBER)
			{
				ft_memcpy_all(res,  cor->code , 4, (tmp->cur + k) % (IDX_MOD - l *  IDX_MOD + 1 * l) % MEM_SIZE);
				tmp->reg[(int)t_reg] = IFR16(res);
			}
		}
	}
	else
		i += 4 * (int)b2[4] - 2 * (int)b2[5];
	tmp->i = i;
}
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

//int					ft_ld_write(t_cor *cor, t_carr *tmp, int i, int l)
//{
//	short			t_ind;
//	short	t_dir;
//	unsigned char	t_reg;
//
//	t_ind = 0;
//	if (i == 3)
//	{
//		t_ind = read_byte_2(cor->code, tmp->cur + 2);
//		t_ind = (l == 1) ? t_ind : t_ind % IDX_MOD;
//		t_dir = read_byte_2(cor->code, (tmp->cur + t_ind));
//	}
//	else
//		t_dir = read_byte_2(cor->code, tmp->cur + 2);
//	t_reg = read_byte_1(cor->code, tmp->cur + (i - 1));
//	if ((int)t_reg > 0 && (int)t_reg <= REG_NUMBER)
//	{
//		tmp->reg[t_reg - 1] = t_dir;
//		tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;
//	}
//	return (1);
//}
//
//void	ft_ld(t_cor *cor, t_carr *tmp, int l)
//{
//	char	*b2;
//	int		i;
//
//	i = 2;
//	b2 = base16_2_cor(cor, tmp);
//	if ((b2[0] == 1 && b2[1] == 0) || (b2[0] == 1 && b2[1] == 1))
//		i += 2;//4 * (int)b2[0] - 2 * (int)b2[1];
//	else if (b2[0] == 0 && b2[1] == 1)
//		i += 1;
//	if (b2[2] == 0 && b2[3] == 1)
//	{
//		i += 1;
//		if (i == 3 || i == 5)
//			ft_ld_write(cor, tmp, i, l);
//	}
//	else if ((b2[2] == 1 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 0))
//		i += 4 * (int)b2[0] - 2 * (int)b2[1];
//	free(b2);
//	tmp->i = i;
//}

int					ft_ld_write(t_cor *cor, t_carr *tmp, int i, int l)
{
	short			t_ind;
	unsigned int	t_dir;
	unsigned char	t_reg;

	t_ind = 0;
	if (i == 5)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + 2);
		t_ind = (l == 1) ? t_ind : t_ind % IDX_MOD;
		t_dir = read_byte_4(cor->code, (tmp->cur + t_ind));
	}
	else
		t_dir = read_byte_4(cor->code, tmp->cur + 2);
	t_reg = read_byte_1(cor->code, tmp->cur + (i - 1));
	if ((int)t_reg > 0 && (int)t_reg <= REG_NUMBER)
	{
		tmp->reg[t_reg - 1] = t_dir;
		tmp->carry = (tmp->reg[t_reg - 1] == 0) ? 1 : 0;
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
	tmp->i = i;
}

void    ft_ldi(t_cor *cor, t_carr *tmp, int l)
{
	unsigned char t_reg;
	char *b2;
	int f_err;
	int i;
	int k;// на сколько надо передвинуть
	unsigned int res;
	short			t_ind;
	short			t_dir;

	i = 2;
	f_err = 0;
	k = 0;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
	{
		t_reg = read_byte_1(cor->code, tmp->cur + i++);
		if (!((int)t_reg > 0 && (int)(t_reg) <= REG_NUMBER))
			f_err = 1;
		else
			k = k + tmp->reg[t_reg - 1];
	}
	else if ((b2[0] == 1 && b2[1] == 1) || (b2[0] == 1 && b2[1] == 0))
	{
		t_ind = 0;
		if (b2[1] == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + 2);
			i += 2;
			t_dir = read_byte_2(cor->code, tmp->cur + t_ind % IDX_MOD);
		}
		else
		{
			//t_dir = read_byte_2(cor->code, tmp->cur + 2 + t_ind % IDX_MOD);
			t_dir = read_byte_2(cor->code, tmp->cur + i);
			i += 2;
		}
		k = k + t_dir;
	}
	else
		f_err = 1;
	if (b2[2] == 0 && b2[3] == 1)
	{
		t_reg = read_byte_1(cor->code, (tmp->cur + i++));
		if (!((int)t_reg > 0 && (int)(t_reg) <= REG_NUMBER))
			f_err = 1;
		else
			k = k + tmp->reg[(int)t_reg - 1];
	}
	else if ((b2[2] == 1 && b2[3] == 0))
	{
		t_dir = read_byte_2(cor->code, tmp->cur + i);
		i += 2;
		k = k + t_dir;
	}
	else
	{
		i +=  b2[2] + b2[3];
		f_err = 1;
	}
	if (b2[4] == 0 && b2[5] == 1)
	{
		i++;
		if (f_err == 0)
		{
			t_reg = read_byte_1(cor->code, tmp->cur + (i - 1));
			if ((int)t_reg > 0 && (int)(t_reg) <= REG_NUMBER)
			{
				res = read_byte_4(cor->code, tmp->cur + k % (IDX_MOD - l *  IDX_MOD + 1 * l));
				tmp->reg[(int)t_reg - 1] = res;
			}
		}
	}
	else
		i += 2 * (int)b2[4];
	tmp->i = i;
	free(b2);
}
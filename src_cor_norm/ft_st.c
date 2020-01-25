/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 22:03:46 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/23 22:03:47 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"


/*
 * копировать в зависимости от положения
 * по модулю MEM_SIZE
 * копирует 4 байта
 * dst - куда
 * src - откуда
 * d_s - куда начинать вставлять
 * s_s - откуда
 * */
void copy_p(void *dst, const void *src, int d_s, int s_s)
{
	int i;
	unsigned char		*str1;
	unsigned char	*str2;
	char c[1];

	while (d_s < 0)
		d_s = MEM_SIZE + d_s;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	while (i < 4)
	{
		c[0] = str2[(i + s_s) % MEM_SIZE];
		str1[(i + d_s) % MEM_SIZE] = (unsigned char)str2[(i + s_s) % MEM_SIZE];
		i++;
	}
}
/*
 * Эта операция записывает значение из регистра, который был передан как первый параметр.
 * А вот куда данная операция его записывает, зависит от типа второго аргумента:
 *
 * Аргумент #2 — T_REG
 * Если второй аргумент соответствует типу T_REG, то значение записывается в регистр.
 *
 * Например, в данном случае значение из регистра номер 7 записывается в регистр с номером 11:
 * 			st    r7, r11
 *
 * Аргумент #2 — T_IND
Как мы помним аргументы типа T_IND это об относительных адресах. Поэтому в данном случае порядок работы операции st такой:

Усечь значение второго аргумента по модулю IDX_MOD.

Определить адрес — текущая позиция + <ВТОРОЙ_АРГУМЕНТ> % IDX_MOD

Записать значение из регистра, который был передан в качестве первого аргумента, в память по полученному адресу.
 * */

void	ft_st_write(t_cor *cor, t_carr *tmp, int b2_2)
{
	unsigned char	*p;
	short			t_ind;
	unsigned char	t_reg;
	unsigned char	t_reg_2;

	t_reg = read_byte_1(cor->code, tmp->cur + 2);
	if (t_reg > 0 && t_reg <= REG_NUMBER)
	{
		if (b2_2 == 1)
		{
			t_ind = read_byte_2(cor->code, tmp->cur + 3);
			p = inttobyte(tmp->reg[t_reg - 1]);
//			while (t_ind < 0)
//				t_ind += MEM_SIZE;
			copy_p(cor->code, p, tmp->cur + t_ind % IDX_MOD, 0); //+3
			free(p);
		}
		else
		{
			t_reg_2 = read_byte_1(cor->code, tmp->cur + 3);
			if (t_reg_2 > 0 && t_reg_2 <= REG_NUMBER)
				tmp->reg[t_reg_2 - 1] = tmp->reg[t_reg - 1];
		}
	}

}

void	ft_st(t_cor *cor, t_carr *tmp)
{
	char	*b2;
	int		i;

	i = 2;
	b2 = base16_2_cor(cor, tmp);
	if (b2[0] == 0 && b2[1] == 1)
		i += 1;
	else if ((b2[0] == 1 && b2[1] == 0) || (b2[0] == 1 && b2[1] == 1))
		i += 4 * (int)b2[0] - 2 * (int)b2[1];
	if ((b2[2] == 0 && b2[3] == 1) || (b2[2] == 1 && b2[3] == 1))
	{
		if (i == 3)
		{
			ft_st_write(cor, tmp, b2[2]);
			i += (b2[2] == 1) ? 2 : 1;
		}
		else
			i = i + (b2[2] == 0 ? 1 : 2);
	}
	else if (b2[2] == 1 && b2[3] == 0)
		i += 4;
	tmp->i = i;
	free(b2);
}
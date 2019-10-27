/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_byte.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:20:24 by qgilbert          #+#    #+#             */
/*   Updated: 2019/10/16 21:20:26 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** возможно три случая
** 1 - получить номер регистра (1 байт) unsigned char
** 2 - получтить ссылку (2 байт) short
** 3 - получить 4 байта unsigned int
*/


unsigned char	read_byte_1(const char *src, int i)
{
	unsigned char	c_1;

	while (i < 0)
		i += MEM_SIZE;
	c_1 = 0;
	c_1 = src[i % MEM_SIZE];
	return ((unsigned char)c_1);
}

short			read_byte_2(const char *src, int i)
{
	short	c_2;

	while (i < 0)
		i = MEM_SIZE + i;
	c_2 = 0;
	c_2 = (c_2 << 8);
	c_2 = c_2 | (unsigned char)src[(i) % MEM_SIZE];
	c_2 = (c_2 << 8);
	c_2 = c_2 | (unsigned char)src[(i + 1) % MEM_SIZE];
	return ((short)c_2);
//	c_2 = src[i % MEM_SIZE];
//	c_2 = c_2 << 8;
//	c_2 = c_2 | (unsigned char)src[(i + 1) % MEM_SIZE];
	return ((short)c_2);
}

unsigned int	read_byte_4(const char *src, int i)
{
	unsigned int	c_4;

	while (i < 0)
		i = MEM_SIZE + i;
	c_4 = 0;
	c_4 = (c_4 << 8);
	c_4 = c_4 | (unsigned char)(src[(i) % MEM_SIZE]);
	c_4 = (c_4 << 8);
	c_4 = c_4 | (unsigned char)(src[(i + 1) % MEM_SIZE]);
	c_4 = (c_4 << 8);
	c_4 = c_4 | (unsigned char)(src[(i + 2) % MEM_SIZE]);
	c_4 = (c_4 << 8);
	c_4 = c_4 | (unsigned char)(src[(i + 3) % MEM_SIZE]);
	return ((unsigned int)c_4);
}

void do_op(t_cor *cor, t_carr	*tmp)
{
//	if (tmp->prog > 0 && tmp->prog  <=16)
//		ft_printf("cyc = %d, prog = %d\n",cor->live->cycles, tmp->prog);
	if	(tmp->prog == 1)
		ft_live(cor, tmp);
	else if (tmp->prog == 2)
		ft_ld(cor, tmp, 0);
	else if (tmp->prog == 3)
		ft_st(cor, tmp);
	else if (tmp->prog == 4)
		ft_add(cor, tmp);
	else if (tmp->prog == 5)
		ft_sub(cor, tmp);
	else if (tmp->prog == 6)
		ft_and(cor, tmp);
	else if (tmp->prog == 7)
		ft_or(cor, tmp);
	else if (tmp->prog == 8)
		ft_xor(cor, tmp);
	else if (tmp->prog == 9)
		ft_zjmp(cor, tmp);
	else if (tmp->prog == 10)
		ft_ldi(cor, tmp, 0);
	else if (tmp->prog == 11)
		ft_sti(cor, tmp);
	else if (tmp->prog == 12)
		ft_fork(cor, tmp, 0);
	else if (tmp->prog == 13)
		ft_lld(cor, tmp);
		//ft_ld(cor, tmp, 1);
	else if (tmp->prog == 14)
		ft_ldi(cor, tmp, 1);
	else if (tmp->prog == 15)
		ft_fork(cor, tmp, 1);
	else if (tmp->prog == 16)
		ft_aff(cor, tmp);
	else
		tmp->i = 1;
}

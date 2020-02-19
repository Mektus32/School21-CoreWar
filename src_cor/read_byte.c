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

unsigned char	read_byte_1( unsigned char *src, int i)
{
	unsigned char	c_1;

	while (i < 0)
		i += MEM_SIZE;
	c_1 = src[i % MEM_SIZE];
	return ((unsigned char)c_1);
}

short			read_byte_2( unsigned char *src, int i)
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
}

unsigned int	read_byte_4( unsigned char *src, int i)
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

char			*base16_2_cor(t_cor *cor, t_carr *tmp)
{
	char			*b2;
	unsigned char	c;
	int				i;

	b2 = (char *)ft_memalloc(sizeof(char) * 9);
	c = read_byte_1(cor->code, tmp->cur + 1);
	i = 7;
	while (i >= 0)
	{
		b2[i--] = c % 2;
		c = c / 2;
	}
	return (b2);
}

unsigned char	*inttobyte(int a)
{
	unsigned char	*bt;

	bt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 4);
	bt[0] = (unsigned char)((a >> 24) & 0xff);
	bt[1] = (unsigned char)((a >> 16) & 0xff);
	bt[2] = (unsigned char)((a >> 8) & 0xff);
	bt[3] = (unsigned char)((a >> 0) & 0xff);
	return (bt);
}

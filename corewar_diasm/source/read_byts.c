/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_byts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:02:45 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 13:03:59 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/diasm.h"

unsigned int	move_to_uint(unsigned char *buf)
{
	unsigned int	rez;
	int				i;

	rez = 0;
	i = -1;
	while (++i < 4)
	{
		rez = rez << 8;
		rez = rez | (unsigned char)buf[i];
	}
	return (rez);
}

unsigned short	move_to_ushort(unsigned char *buf)
{
	unsigned short	rez;
	int				i;

	rez = 0;
	i = -1;
	while (++i < 2)
	{
		rez = rez << 8;
		rez = rez | (unsigned char)buf[i];
	}
	return (rez);
}

unsigned char	read_one_byte(t_diasm *diasm)
{
	unsigned int	one_byte;

	if (read(diasm->fd_cor, &one_byte, 1) == -1)
		sys_err("Error read files.\n");
	return (one_byte);
}

unsigned int	read_four_byte(t_diasm *diasm)
{
	unsigned int	four_byte;
	unsigned char	buf[4];

	if (read(diasm->fd_cor, buf, 4) == -1)
		sys_err("Error read files.\n");
	four_byte = move_to_uint(buf);
	return (four_byte);
}

unsigned short	read_two_byte(t_diasm *diasm)
{
	unsigned short	tow_byte;
	unsigned char	buf[2];

	if (read(diasm->fd_cor, buf, 2) == -1)
		sys_err("Error read files.\n");
	tow_byte = move_to_ushort(buf);
	return (tow_byte);
}

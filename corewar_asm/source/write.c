/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:41:16 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/15 21:01:24 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int				write_to_buffer(t_assm *assm, void *bits, int len_bits)
{
	int	count_oct;

	count_oct = 0;
	while (len_bits > 0)
	{
		len_bits--;
		if (assm->buffer_pos < assm->buffer_size)
			assm->buffer[assm->buffer_pos++] =
					*((unsigned char *)bits + len_bits);
		else
		{
			assm->buffer = (unsigned char*)
					realloc((void*)assm->buffer,
							2 * assm->buffer_size * sizeof(unsigned char));
			assm->buffer_size *= 2;
			assm->buffer[assm->buffer_pos++] =
					*((unsigned char *)bits + len_bits);
		}
		count_oct++;
	}
	return (count_oct);
}

void			write_char_to_buffer(t_assm *assm, unsigned char chr)
{
	if (assm->buffer_pos < assm->buffer_size)
		assm->buffer[assm->buffer_pos++] = chr;
	else
	{
		assm->buffer = (unsigned char*)realloc((void*)assm->buffer,
				2 * assm->buffer_size * sizeof(unsigned char));
		assm->buffer_size *= 2;
		assm->buffer[assm->buffer_pos++] = chr;
	}
}

int				write_to_file(int fd, void *bits, int len_bits)
{
	int	count_oct;

	count_oct = 0;
	while (len_bits > 0)
	{
		len_bits--;
		if ((count_oct += write(fd, (unsigned char *)bits + len_bits, 1)) == -1)
			sys_err("Error write: func write_big_endian\n");
	}
	return (count_oct);
}

void			write_header(t_assm *assm)
{
	int		sector;

	sector = COREWAR_EXEC_MAGIC;
	write_to_file(assm->fd_cor, &sector, 4);
	sector = 0x00;
	write(assm->fd_cor, assm->head.prog_name, PROG_NAME_LENGTH);
	write_to_file(assm->fd_cor, &sector, 4);
	write_to_file(assm->fd_cor, &sector, 4);
	write(assm->fd_cor, assm->head.comment, COMMENT_LENGTH);
	write_to_file(assm->fd_cor, &sector, 4);
}

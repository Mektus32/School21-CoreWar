/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_non_printabl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:03:41 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 15:03:42 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	print_ne(t_ob *ob, int c)
{
	if (c == 30)
		write(ob->fd, "[RS]", 4);
	else if (c == 31)
		write(ob->fd, "[US]", 4);
	else if (c == 9)
		write(ob->fd, "[TAB]", 5);
	else
		ft_printf("%c", c);
	ob->i++;
}

static	void	print_nex(t_ob *ob, int c)
{
	if (c == 20)
		write(ob->fd, "[DC4]", 5);
	else if (c == 21)
		write(ob->fd, "[NAK]", 5);
	else if (c == 22)
		write(ob->fd, "[SYN]", 5);
	else if (c == 23)
		write(ob->fd, "[ETB]", 5);
	else if (c == 24)
		write(ob->fd, "[CAN]", 5);
	else if (c == 25)
		write(ob->fd, "[EM]", 4);
	else if (c == 26)
		write(ob->fd, "[SUB]", 5);
	else if (c == 27)
		write(ob->fd, "[ESC]", 5);
	else if (c == 28)
		write(ob->fd, "[FS]", 4);
	else if (c == 29)
		write(ob->fd, "[GS]", 4);
	else
		print_ne(ob, c);
	ob->i++;
}

static	void	print_next(t_ob *ob, int c)
{
	if (c == 10)
		write(ob->fd, "[LF]", 4);
	else if (c == 11)
		write(ob->fd, "[VT]", 4);
	else if (c == 12)
		write(ob->fd, "[FF]", 4);
	else if (c == 13)
		write(ob->fd, "[CR]", 4);
	else if (c == 14)
		write(ob->fd, "[SO]", 4);
	else if (c == 15)
		write(ob->fd, "[SI]", 4);
	else if (c == 16)
		write(ob->fd, "[DLE]", 5);
	else if (c == 17)
		write(ob->fd, "[DC1]", 5);
	else if (c == 18)
		write(ob->fd, "[DC2]", 5);
	else if (c == 19)
		write(ob->fd, "[DC3]", 5);
	else
		print_nex(ob, c);
	ob->i++;
}

void			print_non_printabl(t_ob *ob)
{
	int		c;

	init_char_arg(ob, &c);
	if (c == 0)
		write(ob->fd, "[NUL]", 5);
	else if (c == 1)
		write(ob->fd, "[SOH]", 5);
	else if (c == 2)
		write(ob->fd, "[STX]", 5);
	else if (c == 3)
		write(ob->fd, "[ETX]", 5);
	else if (c == 4)
		write(ob->fd, "[EOT]", 5);
	else if (c == 5)
		write(ob->fd, "[ENQ]", 5);
	else if (c == 6)
		write(ob->fd, "[ACK]", 5);
	else if (c == 7)
		write(ob->fd, "[BEL]", 5);
	else if (c == 8)
		write(ob->fd, "[BS]", 4);
	else
		print_next(ob, c);
	ob->i++;
}

void			print_invalid(t_ob *ob, char c)
{
	ob->ret += write(ob->fd, &c, 1);
	ob->i++;
}

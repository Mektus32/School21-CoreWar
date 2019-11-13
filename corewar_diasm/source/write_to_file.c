/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:04:43 by widraugr          #+#    #+#             */
/*   Updated: 2019/11/13 13:06:12 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/diasm.h"

void	write_registr(t_diasm *diasm, int flag)
{
	unsigned char	reg;
	char			*str_num;

	reg = read_one_byte(diasm);
	str_num = ft_itoa(reg);
	ft_putchar_fd('r', diasm->fd_s);
	ft_putstr_fd(str_num, diasm->fd_s);
	ft_strdel(&str_num);
	flag == 1 ? ft_putstr_fd(", ", diasm->fd_s) :
		ft_putstr_fd("\n", diasm->fd_s);
}

void	write_direct(t_diasm *diasm, int flag)
{
	unsigned int	dir;
	char			*str_num;

	dir = read_four_byte(diasm);
	str_num = ft_itoa((int)dir);
	ft_putchar_fd('%', diasm->fd_s);
	ft_putstr_fd(str_num, diasm->fd_s);
	ft_strdel(&str_num);
	flag == 1 ? ft_putstr_fd(", ", diasm->fd_s) :
		ft_putstr_fd("\n", diasm->fd_s);
}

void	write_direct_two_byte(t_diasm *diasm, int flag)
{
	unsigned short	dir;
	char			*str_num;

	dir = read_two_byte(diasm);
	str_num = ft_itoa((short)dir);
	ft_putchar_fd('%', diasm->fd_s);
	ft_putstr_fd(str_num, diasm->fd_s);
	ft_strdel(&str_num);
	flag == 1 ? ft_putstr_fd(", ", diasm->fd_s) :
		ft_putstr_fd("\n", diasm->fd_s);
}

void	write_indirect(t_diasm *diasm, int flag)
{
	unsigned short	ind;
	char			*str_num;

	ind = read_two_byte(diasm);
	str_num = ft_itoa((short)ind);
	ft_putstr_fd(str_num, diasm->fd_s);
	ft_strdel(&str_num);
	flag == 1 ? ft_putstr_fd(", ", diasm->fd_s) :
		ft_putstr_fd("\n", diasm->fd_s);
}

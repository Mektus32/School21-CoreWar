/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:14:41 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 15:14:42 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	set_options(const char *restrict fmt, t_ob *ob)
{
	if (!ft_strncmp(fmt + ob->i, "{set:bo}", 8))
		ob->ret += write(ob->fd, "\x1B[1m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{set:ft}", 8))
		ob->ret += write(ob->fd, "\x1B[2m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{set:it}", 8))
		ob->ret += write(ob->fd, "\x1B[3m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{set:ul}", 8))
		ob->ret += write(ob->fd, "\x1B[4m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{set:bl}", 8))
		ob->ret += write(ob->fd, "\x1B[5m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{set:re}", 8))
		ob->ret += write(ob->fd, "\x1B[7m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{set:cc}", 8))
		ob->ret += write(ob->fd, "\x1B[8m", 4);
	else if (!ft_strncmp(fmt + ob->i, "{set:rv}", 8))
		ob->ret += write(ob->fd, "\x1B[28m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{set:fd}", 8))
		init_int_arg(ob, &ob->fd);
	else
		return ;
	ob->i += 8;
}

static	void	set_background(const char *restrict fmt, t_ob *ob)
{
	if (!ft_strncmp(fmt + ob->i, "{bgc:blk}", 9))
		ob->ret += write(ob->fd, "\x1B[40m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{bgc:red}", 9))
		ob->ret += write(ob->fd, "\x1B[41m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{bgc:grn}", 9))
		ob->ret += write(ob->fd, "\x1B[42m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{bgc:yel}", 9))
		ob->ret += write(ob->fd, "\x1B[43m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{bgc:blu}", 9))
		ob->ret += write(ob->fd, "\x1B[44m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{bgc:mgt}", 9))
		ob->ret += write(ob->fd, "\x1B[45m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{bgc:cyn}", 9))
		ob->ret += write(ob->fd, "\x1B[46m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{bgc:wht}", 9))
		ob->ret += write(ob->fd, "\x1B[47m", 5);
	else
		return ;
	ob->i += 9;
}

static	void	set_color(const char *restrict fmt, t_ob *ob)
{
	if (!ft_strncmp(fmt + ob->i, "{blk}", 5))
		ob->ret += write(ob->fd, "\x1B[30m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{red}", 5))
		ob->ret += write(ob->fd, "\x1B[31m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{grn}", 5))
		ob->ret += write(ob->fd, "\x1B[32m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{yel}", 5))
		ob->ret += write(ob->fd, "\x1B[33m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{blu}", 5))
		ob->ret += write(ob->fd, "\x1B[34m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{mgt}", 5))
		ob->ret += write(ob->fd, "\x1B[35m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{cyn}", 5))
		ob->ret += write(ob->fd, "\x1B[36m", 5);
	else if (!ft_strncmp(fmt + ob->i, "{wht}", 5))
		ob->ret += write(ob->fd, "\x1B[37m", 5);
	else
		return ;
	ob->i += 5;
}

void			check_settings(const char *restrict fmt, t_ob *ob)
{
	int		tmp;

	tmp = ob->i;
	if (!ft_strncmp(fmt + tmp, "{off}", 5))
	{
		ob->ret += write(ob->fd, "\x1B[0m", 4);
		ob->i += 5;
	}
	else if (!ft_strncmp(fmt + tmp, "{set:", 5))
		set_options(fmt, ob);
	else if (!ft_strncmp(fmt + tmp, "{bgc:", 5))
		set_background(fmt, ob);
	else
		set_color(fmt, ob);
	if (tmp == ob->i)
		ob->ret += write(ob->fd, &fmt[ob->i++], 1);
}

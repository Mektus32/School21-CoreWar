/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:52:21 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 14:52:22 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	init_flag(t_flag *flag)
{
	flag->minus = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->zero = 0;
	flag->quote = 0;
	flag->dot = 0;
	flag->weight = -1;
	flag->prec = -1;
	flag->negativ = 0;
}

static	void	begin_check(const char *restrict fmt, t_ob *ob)
{
	ob->i++;
	init_flag(&(ob->flag));
	ob->type = type_notype;
	ob->dollar.dollar = 0;
	check_args(fmt, ob);
	choise_specs(fmt, ob);
}

int				ft_printf(const char *restrict fmt, ...)
{
	t_ob	ob;

	ob.ret = 0;
	ob.fd = 1;
	ob.i = 0;
	va_start(ob.ap[0], fmt);
	va_copy(ob.ap[1], ob.ap[0]);
	while (fmt[ob.i])
	{
		if (fmt[ob.i] == '{')
			check_settings(fmt, &ob);
		else if (fmt[ob.i] == '%')
			begin_check(fmt, &ob);
		else
			ob.ret += write(ob.fd, &fmt[ob.i++], 1);
	}
	return (ob.ret);
}

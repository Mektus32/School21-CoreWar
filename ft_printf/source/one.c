/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:01:44 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/09 12:01:46 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_check(const char *format, va_list ap, t_print *pr)
{
	if ((*pr).format == 1)
		return (ft_print_str(format, va_arg(ap, char *), pr));
	else if ((*pr).format == 2)
		return (ft_print_d(format, ap, pr));
	else if ((*pr).format == 3)
		return (ft_print_c(format, ap, pr));
	else if ((*pr).format == 9)
		return (ft_print_x(format, ap, pr));
	else if ((*pr).format == 4)
		return (ft_print_d(format, ap, pr));
	else if ((*pr).format == 5 || (*pr).format == 12)
		ft_print_o(format, ap, pr);
	else if ((*pr).format == 6 || (*pr).format == 11)
		return (ft_print_u(format, ap, pr));
	else if ((*pr).format == 7)
		return (ft_print_x(format, ap, pr));
	else if ((*pr).format == 8)
		return (ft_print_x(format, ap, pr));
	else if ((*pr).format == 10)
		return (ft_print_f(format, ap, pr));
	else
		(*pr).net = 1;
	return (format);
}

const char	*ft_format(const char *format, va_list ap, t_print *pr)
{
	format++;
	if (ft_strncmp(format, "%", 1) == 0)
	{
		(*pr).len += 1;
		ft_putstr("%");
		format++;
		return (format);
	}
	format = ft_flag_check(format, pr);
	if ((*pr).minus == 1 && (*pr).space == 1)
		(*pr).space = 0;
	format = ft_width_check(format, pr, ap);
	format = ft_precision_check(format, pr, ap);
	format = ft_mod_check(format, pr);
	format = ft_format_check(format, pr);
	format = ft_check(format, ap, pr);
	if ((*pr).net == 1)
		if (ft_strncmp(format, "%", 1) == 0)
		{
			(*pr).space = 0;
			ft_print_str(format, "%", pr);
		}
	return (format);
}

t_print		*ft_make_0(int len, t_print *pr_old)
{
	t_print	*pr;

	if (pr_old)
		free(pr_old);
	pr = (t_print*)malloc(sizeof(t_print));
	(*pr).len = len;
	(*pr).minus = 0;
	(*pr).width = 0;
	(*pr).prec_p = 0;
	(*pr).prec = 0;
	(*pr).net = 0;
	(*pr).rr = 0;
	(*pr).space = 0;
	(*pr).plus = 0;
	(*pr).zero = 0;
	(*pr).mod = -1;
	(*pr).leftzero = 0;
	(*pr).format = 0;
	(*pr).pr_x = 0;
	(*pr).pr_4erez_0 = 0;
	(*pr).pr_5 = 0;
	return (pr);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_print	*pr;
	int		len;

	va_start(ap, format);
	pr = ft_make_0(0, NULL);
	while (*format)
	{
		if (ft_strncmp(format, "%", 1) == 0)
		{
			if ((*pr).len)
				pr = ft_make_0((*pr).len, pr);
			format = ft_format(format, ap, pr);
		}
		else
		{
			ft_putchar(*format++);
			(*pr).len++;
		}
	}
	va_end(ap);
	len = (*pr).len;
	free(pr);
	return (len);
}

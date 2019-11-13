/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:51:30 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/29 16:30:24 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_flag_check(const char *format, t_print *pr)
{
	while (ft_strncmp(format, "#", 1) == 0 || ft_strncmp(format, " ", 1) == 0 ||
		ft_strncmp(format, "+", 1) == 0 || ft_strncmp(format, "-", 1) == 0 ||
		ft_strncmp(format, "0", 1) == 0)
	{
		if (ft_strncmp(format, "#", 1) == 0)
			(*pr).rr = 1;
		else if (ft_strncmp(format, " ", 1) == 0)
			(*pr).space = 1;
		else if (ft_strncmp(format, "+", 1) == 0)
			(*pr).plus = 1;
		else if (ft_strncmp(format, "-", 1) == 0)
			(*pr).minus = 1;
		else
			(*pr).zero = 1;
		format++;
	}
	return (format);
}

const char	*ft_width_check(const char *format, t_print *pr, va_list ap)
{
	if (format[0] == '*')
	{
		(*pr).width = (int)va_arg(ap, int);
		if ((*pr).width < 0)
		{
			(*pr).width = -(*pr).width;
			(*pr).minus = 1;
		}
		format++;
	}
	(*pr).width = (ft_isdigit(*format)) ? 0 : (*pr).width;
	while (ft_isdigit(*format))
	{
		(*pr).width = (*pr).width * 10 + (*format - '0');
		format++;
	}
	if (format[0] == '*')
	{
		(*pr).width = (int)va_arg(ap, int);
		if ((*pr).width < 0)
			(*pr).width = 1;
		format++;
	}
	return (format);
}

const char	*ft_precision_check(const char *format, t_print *pr, va_list ap)
{
	if (ft_strncmp(format, ".", 1) == 0)
	{
		format++;
		(*pr).prec_p = 1;
		if (format[0] == '*')
		{
			(*pr).prec = (int)va_arg(ap, int);
			if ((*pr).prec < 0)
			{
				(*pr).prec = (*pr).width;
				if ((*pr).zero != 1)
					(*pr).prec_p = 0;
			}
			return (++format);
		}
		while (ft_isdigit(*format))
		{
			(*pr).prec = (*pr).prec * 10 + (*format - '0');
			format++;
		}
	}
	return (format);
}

const char	*ft_mod_check(const char *format, t_print *pr)
{
	if (!ft_strncmp(format, "hh", 2) || !ft_strncmp(format, "ll", 2))
	{
		if (ft_strncmp(format, "hh", 2) == 0)
			(*pr).mod = 4;
		else
			(*pr).mod = 5;
		format++;
	}
	else if (ft_strncmp(format, "h", 1) == 0)
		(*pr).mod = 1;
	else if (ft_strncmp(format, "l", 1) == 0)
		(*pr).mod = 2;
	else if (ft_strncmp(format, "j", 1) == 0)
		(*pr).mod = 7;
	else if (ft_strncmp(format, "z", 1) == 0)
		(*pr).mod = 6;
	else if (!ft_strncmp(format, "L", 1))
		(*pr).mod = 3;
	else
		(*pr).mod = 0;
	if ((*pr).mod != 0)
		format++;
	return (format);
}

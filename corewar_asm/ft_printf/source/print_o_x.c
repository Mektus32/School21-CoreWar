/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:33:36 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/08 18:33:37 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void					print_o(t_print *pr, const char *format,
	unsigned long long n)
{
	char					*str;

	if ((*pr).prec > 0)
		(*pr).rr = 0;
	str = n == 0 ? ft_strdup("0") : ft_int_base(n, (*pr).format);
	if (str[0] == '0' && (((*pr).prec_p && (*pr).prec == 0) || (*pr).rr == 1))
		((*pr).rr == 1) ? ft_print_num("\0", pr) : ft_print_str(F, "\0", pr);
	else
		ft_print_num(str, pr);
	free(str);
}

void						ft_print_o(const char *format, va_list ap,
	t_print *pr)
{
	long long int			num;
	unsigned long long int	n;

	if ((*pr).mod == 5 || (*pr).mod == 2)
		n = (long long)va_arg(ap, long long);
	else if ((*pr).mod == 7 || (*pr).mod == 6)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if ((*pr).mod == 1)
	{
		num = (int)va_arg(ap, int);
		n = (num < 0) ? 65536 + num : num;
	}
	else if ((*pr).mod == 4)
	{
		num = (signed char)va_arg(ap, int);
		n = (num < 0) ? 256 + num : num;
	}
	else
	{
		num = va_arg(ap, int);
		n = (num < 0) ? 4294967296 + num : num;
	}
	print_o(pr, F, n);
}

static void					print_x(t_print *pr, const char *format,
	unsigned long long n)
{
	char					*str;

	str = n == 0 ? ft_strdup("0") : ft_int_base(n, (*pr).format);
	(*pr).pr_0 = n == 0 ? 1 : 0;
	if (str[0] == '0' && (((*pr).prec_p && (*pr).prec == 0) || (*pr).rr == 1))
	{
		if ((*pr).format == 9 && !(*pr).prec_p)
			ft_print_num(str, pr);
		else if ((*pr).format == 9)
			ft_print_str(format, "0", pr);
		else if ((*pr).rr == 1)
			ft_print_str(format, "0", pr);
		else
			ft_print_str(format, "\0", pr);
	}
	else
		ft_print_num(str, pr);
	free(str);
}

const char					*ft_print_x(const char *format, va_list ap,
	t_print *pr)
{
	long long				num;
	unsigned long long		n;

	if ((*pr).mod == 5 || (*pr).mod == 2)
		n = (long long)va_arg(ap, long long);
	else if ((*pr).mod == 4)
		n = (unsigned char)va_arg(ap, int);
	else if ((*pr).format == 9)
		n = (long)va_arg(ap, long);
	else if ((*pr).mod == 7)
		n = (unsigned long long)va_arg(ap, unsigned long long);
	else if ((*pr).mod == 1)
	{
		num = (int)va_arg(ap, int);
		n = (num < 0) ? 32767 + num : num;
	}
	else if (!(*pr).mod || (*pr).format == 5)
	{
		num = va_arg(ap, int);
		n = (num < 0) ? 4294967296 + num : num;
	}
	else
		n = (unsigned long long)va_arg(ap, unsigned long long);
	print_x(pr, format, n);
	return (format);
}

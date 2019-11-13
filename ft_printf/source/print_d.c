/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:56:24 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/08 17:56:29 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*str_num_ll(va_list ap, t_print *pr)
{
	long long	num_ll;
	char		*str;

	num_ll = (long long)va_arg(ap, long long);
	if (num_ll < 0 || num_ll == MIN_LL)
	{
		(*pr).leftzero = 1;
		num_ll = -num_ll;
	}
	if (num_ll == MIN_LL)
		str = ft_strdup("9223372036854775807");
	else
		str = ft_itoa_lu(num_ll);
	return (str);
}

static char		*str_int(va_list ap, t_print *pr)
{
	int			num;
	char		*str;

	num = va_arg(ap, int);
	if (num < 0 || num == MIN_INT)
	{
		(*pr).leftzero = 1;
		num = -num;
	}
	str = (num == MIN_INT) ? ft_strdup("2147483648") : ft_itoa_lu(num);
	return (str);
}

static char		*str_short_int(t_print *pr, int num)
{
	char		*str;

	if (num < 0)
	{
		(*pr).leftzero = 1;
		num = -num;
	}
	str = ft_itoa_lu(num);
	return (str);
}

const char		*ft_print_d(const char *format, va_list ap, t_print *pr)
{
	int			num;
	char		*str;

	str = NULL;
	if ((*pr).mod == 1)
		num = (short int)va_arg(ap, int);
	else if ((*pr).mod == 4)
		num = (signed char)va_arg(ap, int);
	else if ((*pr).mod == 5 || (*pr).mod == 2 || (*pr).mod == 7 ||
		(*pr).mod == 6)
		str = str_num_ll(ap, pr);
	else
		str = str_int(ap, pr);
	if (!str)
		str = str_short_int(pr, num);
	if (str[0] == '0' && !(*pr).mod && (*pr).prec_p && (*pr).prec == 0)
		ft_print_str(format, "", pr);
	else
		ft_print_num(str, pr);
	if (str)
		free(str);
	return (format);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:19:00 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/08 18:19:02 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void				memset_str(char *str, int len, int c, t_print *pr)
{
	if ((*pr).minus)
	{
		ft_memset(str, c, 1);
		ft_memset(str + 1, ' ', len - 1);
	}
	else
	{
		ft_memset(str, ' ', len);
		ft_memset(str + (len - 1), c, 1);
	}
}

const char				*ft_print_c(const char *format, va_list ap, t_print *pr)
{
	int					c;
	char				*str;
	int					len;

	c = (char)va_arg(ap, int);
	len = ((*pr).width) ? ((*pr).width) : 1;
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	if (c)
		memset_str(str, len, c, pr);
	else
	{
		if ((*pr).minus)
			write(1, "\0", 1);
		((*pr).zero == 1) ? ft_memset(str, '0', len - 1) :
		ft_memset(str, ' ', len - 1);
	}
	ft_putstr(str);
	if (!c && !(*pr).minus)
		write(1, "\0", 1);
	(*pr).len += ft_strlen(str) + 1 * (!c);
	free(str);
	return (format);
}

const char				*ft_print_u(const char *format, va_list ap, t_print *pr)
{
	unsigned long long	num;
	char				*str;

	if (!(*pr).mod && !((*pr).format == 11))
		num = (unsigned int)va_arg(ap, unsigned int);
	else if ((*pr).mod == 4)
		num = (unsigned char)va_arg(ap, int);
	else
		num = (unsigned long long)va_arg(ap, unsigned long long);
	(*pr).space = 0;
	(*pr).plus = 0;
	str = ((*pr).mod == 5 || (*pr).mod == 2 || (*pr).mod == 6 ||
		(*pr).mod == 7) ? ft_itoa_lu(num) : ft_itoa_lu(num);
	if (str[0] == '0' && !(*pr).mod && (*pr).prec_p && (*pr).prec == 0)
		ft_print_str(format, "\0", pr);
	else
		ft_print_num(str, pr);
	free(str);
	return (format);
}

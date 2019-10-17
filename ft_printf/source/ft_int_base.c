/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:56:27 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/29 16:31:03 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	len_char(unsigned long long one, int base)
{
	int		count;
	int		b;

	count = 0;
	if (base == 5)
		b = 8;
	else if (base >= 7 && base <= 9)
		b = 16;
	else
		b = 2;
	while (one > 0)
	{
		count++;
		one = one / b;
	}
	return (count);
}

static char	*base_char(int base)
{
	char	*digits;

	digits = ft_strnew(16);
	if (base == 5)
		ft_memcpy(digits, "01234567", 8);
	else if (base == 12)
		ft_memcpy(digits, "01", 2);
	else if (base == 8)
		ft_memcpy(digits, "0123456789ABCDEF", 16);
	else
		ft_memcpy(digits, "0123456789abcdef", 16);
	return (digits);
}

char		*ft_int_base(unsigned long long one, int base)
{
	char	*c_base;
	char	*digits;
	int		len;

	if (one == 0)
		return ("0");
	digits = base_char(base);
	len = len_char(one, base);
	c_base = (char*)malloc(sizeof(char) * (len + 1));
	c_base[len--] = '\0';
	if (base == 7 || base == 8 || base == 9)
		while (one > 0)
		{
			c_base[len--] = digits[one % 16];
			one = one / 16;
		}
	else
		while (one > 0)
		{
			c_base[len--] = base == 5 ? digits[one % 8] : digits[one % 2];
			one = base == 5 ? one / 8 : one / 2;
		}
	free(digits);
	return (c_base);
}

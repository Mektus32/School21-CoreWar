/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:50:01 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/12 17:23:41 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_int(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		if (n == -2147483648)
		{
			i++;
			n = -214748364;
		}
		n = -n;
	}
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*new;

	len = ft_size_int(n);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len--] = '\0';
	if (n < 0)
	{
		new[0] = '-';
		if (n == -2147483648)
		{
			new[len--] = '0' + 8;
			n = -214748364;
		}
		n = -n;
	}
	while (n / 10 > 0)
	{
		new[len--] = n % 10 + '0';
		n = n / 10;
	}
	new[len] = n + '0';
	return (new);
}

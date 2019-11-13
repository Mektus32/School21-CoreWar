/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:56:35 by qgilbert          #+#    #+#             */
/*   Updated: 2019/06/29 16:31:18 by kwalter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_size_int_lu(unsigned long long n)
{
	int		i;

	i = 0;
	while (n / 10 > 0)
	{
		i++;
		n = n / 10;
	}
	i++;
	return (i);
}

char		*ft_itoa_lu(unsigned long long n)
{
	int		len;
	char	*new;

	len = ft_size_int_lu(n);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	new[len--] = '\0';
	while (n / 10 > 0)
	{
		new[len--] = n % 10 + '0';
		n = n / 10;
	}
	new[len] = n + '0';
	return (new);
}

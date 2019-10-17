/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:53:59 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 14:54:00 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ultoa(unsigned long n)
{
	char			*tmp;
	unsigned long	nbr;
	int				len;

	len = 1;
	nbr = n;
	while (nbr / 10)
	{
		nbr /= 10;
		len++;
	}
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	while (n > 9)
	{
		tmp[--len] = n % 10 + '0';
		n /= 10;
	}
	tmp[--len] = n + 48;
	return (tmp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:00:30 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/09 22:00:44 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ultoa_base(unsigned long n, int base)
{
	char			*tmp;
	unsigned long	nbr;
	int				len;

	len = 1;
	nbr = n;
	while (nbr / (unsigned)base)
	{
		nbr /= (unsigned)base;
		len++;
	}
	tmp = (char*)malloc(sizeof(char) * (len + 1));
	tmp[len] = '\0';
	while (n >= (unsigned)base)
	{
		tmp[--len] = n % base < 10 ? (n % base) + '0' : (n % base) + 55;
		n /= base;
	}
	tmp[--len] = n % base < 10 ? (n % base) + '0' : (n % base) + 55;
	return (tmp);
}

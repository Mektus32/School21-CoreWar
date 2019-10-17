/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:15:23 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/12 17:26:10 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	unsigned char		c_uc;
	size_t				i;

	i = 0;
	str = s;
	c_uc = c;
	while (n--)
	{
		if (*str == c_uc)
			return ((void*)str);
		str++;
	}
	return (NULL);
}

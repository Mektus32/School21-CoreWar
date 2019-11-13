/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:29:03 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/05 19:29:05 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	const unsigned char *s;

	i = 0;
	s = src;
	while (i < n)
	{
		ft_memset(&dest[i], s[i], 1);
		if (s[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}

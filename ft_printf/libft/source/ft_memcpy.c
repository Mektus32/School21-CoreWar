/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:57:09 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/05 18:57:11 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *srcptr, size_t num)
{
	size_t				i;
	const unsigned char *s;

	i = 0;
	s = srcptr;
	while (i < num)
	{
		ft_memset(&dest[i], s[i], 1);
		i++;
	}
	return (dest);
}

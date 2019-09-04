/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:57:54 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/09 20:29:46 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t count)
{
	unsigned char		*d;
	const unsigned char	*s;
	const unsigned char	*lasts;
	unsigned char		*lastd;

	d = dest;
	s = source;
	lastd = d + (count - 1);
	lasts = s + (count - 1);
	if (d < s)
		while (count-- > 0)
			*d++ = *s++;
	else
		while (count-- > 0)
			*lastd-- = *lasts--;
	return (dest);
}

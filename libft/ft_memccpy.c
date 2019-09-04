/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:43:20 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/09 22:10:07 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int ch, size_t count)
{
	unsigned char		*dst;
	const unsigned char	*src;
	int					i;

	dst = dest;
	src = source;
	if (!count)
		return (NULL);
	i = 0;
	while (count-- > 0)
	{
		dst[i] = src[i];
		if (src[i] == (unsigned char)ch)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}

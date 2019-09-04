/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:26:21 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/09 20:29:46 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str1;
	const unsigned char	*str2;
	int					i;

	str1 = dst;
	str2 = src;
	i = 0;
	while (n-- > 0)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}

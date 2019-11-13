/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:35:30 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/05 19:35:37 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *srcptr, size_t num)
{
	size_t				i;
	const unsigned char	*s;

	i = 0;
	s = srcptr;
	if (dest < srcptr)
		while (i < num)
		{
			ft_memset(&dest[i], s[i], 1);
			i++;
		}
	else
		while (i < num)
		{
			ft_memset(&dest[num - i - 1], s[num - i - 1], 1);
			i++;
		}
	return (dest);
}

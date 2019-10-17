/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:21:03 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/06 15:21:06 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int		i;
	size_t	s;

	i = 0;
	s = 0;
	while (dest[i] != '\0')
		i++;
	while ((src[s] != '\0') && s < nb)
	{
		dest[i] = src[s];
		s++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

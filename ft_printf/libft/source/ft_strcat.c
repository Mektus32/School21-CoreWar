/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:20:54 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/06 15:20:55 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int	s;

	i = 0;
	s = 0;
	while (dest[i] != '\0')
		i++;
	while (src[s] != '\0')
	{
		dest[i] = src[s];
		s++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

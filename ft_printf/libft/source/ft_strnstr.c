/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:01:02 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/06 15:01:04 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		k;

	i = 0;
	k = 0;
	if (to_find[k] == '\0')
		return ((char *)str + i);
	while (str[i] != '\0')
	{
		while (str[i] != to_find[0] && str[i] != '\0' && i < len)
			i++;
		if (str[i] == '\0')
			return (0);
		while (str[i] == to_find[k] && str[i] != '\0' && i < len &&
			to_find[k++] != '\0')
			i++;
		if (to_find[k] == '\0')
			return ((char *)str + i - k);
		else
		{
			i = i - k + 1;
			k = 0;
		}
	}
	return (0);
}

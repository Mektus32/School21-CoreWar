/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:04:16 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/06 15:04:20 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int k;

	i = 0;
	k = 0;
	if (to_find[k] == '\0')
		return ((char *)str + i);
	while (str[i] != '\0')
	{
		while (str[i] != to_find[0] && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return (0);
		while (str[i] == to_find[k] && str[i] != '\0' && to_find[k++] != '\0')
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

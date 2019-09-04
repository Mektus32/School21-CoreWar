/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 20:02:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/09 23:26:56 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	int		j;

	if (!s)
		return (NULL);
	str = NULL;
	j = 0;
	i = 0;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		while (s[i] != '\0')
		{
			if (i >= start && i < len + start)
			{
				str[j] = s[i];
				j++;
			}
			i++;
		}
		str[j] = '\0';
	}
	return (str);
}

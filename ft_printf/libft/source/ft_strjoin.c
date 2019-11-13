/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:05:12 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/08 18:05:14 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		len1;

	if (!s1 || !s2)
		return (NULL);
	new = NULL;
	new = (char*)malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	len1 = i;
	i = 0;
	while (s2[i])
	{
		new[len1 + i] = s2[i];
		i++;
	}
	return (new);
}

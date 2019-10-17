/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 15:30:24 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/06 15:30:26 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*src2;
	int		len;
	int		i;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	src2 = (char*)malloc(sizeof(*src2) * (len + 1));
	if (src2 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}

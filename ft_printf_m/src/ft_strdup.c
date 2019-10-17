/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:40:08 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/24 13:05:29 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		i;
	int		l;

	i = 0;
	ptr = NULL;
	while (str[i])
		i++;
	ptr = (char*)malloc(sizeof(char) * (i + 1));
	if (ptr)
	{
		l = -1;
		while (l++ < i)
			ptr[l] = str[l];
		ptr[i] = '\0';
	}
	return (ptr);
}

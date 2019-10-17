/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:34:38 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/22 17:15:17 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char*)&str[i]);
		i++;
	}
	if (ch == '\0')
		return ((char*)&str[i]);
	return (NULL);
}

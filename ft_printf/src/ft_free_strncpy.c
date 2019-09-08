/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strncpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:03:04 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/24 12:43:50 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_free_strncpy(char *dest, const char *new, size_t n)
{
	size_t	i;
	int		f;

	f = 0;
	i = 0;
	while (new[i] != '\0' && i < n)
	{
		dest[i] = new[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	free((char*)new);
	return (dest);
}

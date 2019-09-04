/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 16:36:45 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/11 16:44:46 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t n)
{
	size_t	i;
	int		l;

	if (!source || !dest)
		return (0);
	if (n == 0)
	{
		n = ft_strlen(dest) + 1;
		dest[n] = '\0';
		return (ft_strlen(source));
	}
	i = 0;
	l = 0;
	while (dest[l] != '\0')
		l++;
	while (source[i] != '\0' && i < n - 1)
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (source[i] != '\0')
		i++;
	return (i);
}

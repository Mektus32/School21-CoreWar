/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:51:57 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/11 13:52:03 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int			i;
	const char	*place;

	i = 0;
	place = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			place = &str[i];
		i++;
	}
	if (ch == '\0')
		place = &str[i];
	return ((char*)place);
}

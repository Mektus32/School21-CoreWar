/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:38:44 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/09 23:34:35 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s)
{
	int		count;
	int		i;

	if (!s)
		return (0);
	count = 0;
	i = -1;
	if (!ft_isspace(s[0]) && s[0] != '\0')
		count++;
	while (s[++i] != '\0')
		if (ft_isspace(s[i]) && !ft_isspace(s[i + 1]) && s[i + 1] != '\0')
			count++;
	return (count);
}

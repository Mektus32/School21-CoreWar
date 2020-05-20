/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:33:36 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/11 15:45:13 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_begin_count(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == ' ')
		i++;
	return (i);
}

static	int		ft_end_count(char const *s)
{
	int		i;

	i = ft_strlen(s);
	while ((s[i] == '\t' || s[i] == '\n' || s[i] == ' ' || s[i] == '\0')
			&& i > 0)
		i--;
	return (i + 1);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	begin;
	size_t	end;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	begin = ft_begin_count(s);
	end = ft_end_count(s);
	if ((begin == ft_strlen(s)) && end == 0)
		len = 0;
	else
		len = end - begin;
	if (len < 0)
		len = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (begin < end)
		str[i++] = s[begin++];
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:12:13 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/11 15:04:05 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define FREEONE free(str[d]); str[d] = NULL;
#define FREETWO free(str); return (NULL);

static	int		ft_count_word(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = -1;
	if (s[0] != c && s[0] != '\0')
		count++;
	while (s[++i] != '\0')
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
	return (count);
}

static	int		ft_len_word(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	char	**ft_memall(char const *s, int countwords, char **str, char c)
{
	int i;
	int j;
	int d;

	i = -1;
	d = 0;
	while (countwords != d)
		if (s[++i] != c)
		{
			j = 0;
			str[d] = NULL;
			if (!(str[d] = (char*)malloc(sizeof(char) *
							(ft_len_word(&s[i], c) + 1))))
			{
				while (--d >= 0)
				{
					FREEONE;
				}
				FREETWO;
			}
			while ((ft_len_word(&s[i], c)))
				str[d][j++] = s[i++];
			str[d++][j] = '\0';
		}
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		countwords;
	char	**str;

	if (!s)
		return (NULL);
	countwords = 0;
	countwords = ft_count_word(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (countwords + 1))))
		return (NULL);
	if (!countwords)
	{
		*str = NULL;
		return (str);
	}
	str[countwords] = NULL;
	str = ft_memall(s, countwords, str, c);
	return (str);
}

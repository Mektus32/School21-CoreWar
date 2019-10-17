/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:24:34 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/08 19:24:41 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_word(char *str, char c)
{
	int i;
	int wor;
	int f;

	i = 0;
	wor = 0;
	while (str[i] != '\0')
	{
		f = 0;
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			f = 1;
			i++;
		}
		while (str[i] == c && str[i] != '\0')
			i++;
		if (f == 1)
			wor++;
	}
	return (wor);
}

static int		len_w(char *s, char c)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (s[k] == c)
		k++;
	while (s[k] != c && s[k] != '\0')
	{
		k++;
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s_n, char c)
{
	char	**new_m;
	int		count_w;
	int		i;
	int		k;

	if (!s_n)
		return (NULL);
	count_w = count_word((char*)s_n, c);
	if (!(new_m = (char **)malloc(sizeof(char *) * (count_w + 1))))
		return (NULL);
	new_m[count_w] = NULL;
	i = -1;
	while (++i < count_w)
	{
		if (!(new_m[i] = (char*)malloc(sizeof(char) * (len_w((char*)s_n, c)
				+ 1))))
			return (NULL);
		new_m[i][len_w((char*)s_n, c)] = '\0';
		while (*s_n == c)
			s_n++;
		k = 0;
		while (*s_n != c && *s_n != '\0')
			new_m[i][k++] = *s_n++;
	}
	return (new_m);
}

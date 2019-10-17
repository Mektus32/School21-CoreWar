/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:21:39 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/08 18:21:40 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_whithoutspase(char const *s)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (len > i && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (len - i);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	int		len_new;
	int		i;

	i = 0;
	if (!s)
		return (0);
	len_new = ft_len_whithoutspase(s);
	new = (char*)malloc(sizeof(char) * (len_new + 1));
	if (!new)
		return (0);
	new[len_new] = '\0';
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (i < len_new)
		new[i++] = *s++;
	return (new);
}

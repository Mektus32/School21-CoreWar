/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:39:56 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/07 19:39:58 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*new;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	new[len] = '\0';
	if (!s)
		return (0);
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:48:44 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/07 19:48:46 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s2 || !s1)
		return (0);
	if (n == 0)
		return (1);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] &&
		s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:41:57 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/07 19:41:59 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (!s2 || !s1)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i] &&
		s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] == s2[i])
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:41:32 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/05 20:41:34 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s_1;
	const unsigned char	*s_2;

	i = 0;
	s_1 = s1;
	s_2 = s2;
	if (n == 0)
		return (0);
	while (*s_1 == *s_2 && i < n - 1)
	{
		i++;
		s_1++;
		s_2++;
	}
	return (*s_1 - *s_2);
}

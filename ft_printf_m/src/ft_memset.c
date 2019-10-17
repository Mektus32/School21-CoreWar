/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:04:51 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 15:15:13 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *memptr, int value, size_t num)
{
	unsigned char *str;

	str = memptr;
	while (num-- > 0)
		*str++ = value;
	return (memptr);
}

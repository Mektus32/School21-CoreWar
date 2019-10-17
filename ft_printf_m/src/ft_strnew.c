/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:04:09 by ojessi            #+#    #+#             */
/*   Updated: 2019/05/07 14:04:44 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = NULL;
	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (ptr)
		return ((char*)ft_memset(ptr, '\0', size + 1));
	else
		return (NULL);
}

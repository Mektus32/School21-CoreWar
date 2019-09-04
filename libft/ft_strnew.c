/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:41:58 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/09 23:20:40 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

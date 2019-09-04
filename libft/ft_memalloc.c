/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 17:32:43 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/09 22:07:29 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = NULL;
	ptr = (void*)malloc(sizeof(void) * size);
	if (ptr)
		return (ft_memset(ptr, 0, size));
	else
		return (NULL);
}

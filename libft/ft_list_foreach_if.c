/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:13:39 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/15 21:16:33 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_foreach_if(t_list *begin_list, int elem)
{
	while (begin_list)
	{
		if ((int)begin_list->content_size == elem)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (NULL);
}

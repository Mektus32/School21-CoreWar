/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 21:02:13 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/15 21:02:55 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_push_back(t_list **begin_list, void *str, int elem)
{
	t_list	*list;

	if (!begin_list)
		return (NULL);
	list = *begin_list;
	if (!list)
		list = ft_list_add(str, elem);
	else
	{
		while (list->next)
			list = list->next;
		list->next = ft_list_add(str, elem);
		list = list->next;
	}
	return (list);
}

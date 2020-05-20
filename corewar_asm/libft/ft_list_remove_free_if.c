/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_free_if.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:43:17 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/07 12:34:33 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_free(t_list *list)
{
	free(list->content);
	list->content = NULL;
	free(list);
	list = NULL;
}

void				ft_list_remove_free_if(t_list **begin_list, int elem)
{
	t_list			*list;
	t_list			*tmp;

	list = *begin_list;
	if ((int)list->content_size == elem)
	{
		*begin_list = list->next;
		ft_free(list);
		return ;
	}
	tmp = list;
	while (list)
	{
		if ((int)list->content_size == elem)
		{
			tmp->next = list->next;
			ft_free(list);
			return ;
		}
		tmp = list;
		list = list->next;
	}
}

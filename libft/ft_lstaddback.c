/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:40:19 by ojessi            #+#    #+#             */
/*   Updated: 2019/04/09 23:34:35 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *new)
{
	t_list *list;

	if (!alst)
		return ;
	list = *alst;
	if (*alst)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*alst = new;
}

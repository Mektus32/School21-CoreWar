/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:48:31 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/12 16:48:33 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*one_el;

	if (!lst)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	one_el = new;
	lst = lst->next;
	while (lst)
	{
		new->next = f(lst);
		if (!new->next)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (one_el);
}

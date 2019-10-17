/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:48:53 by qgilbert          #+#    #+#             */
/*   Updated: 2019/04/12 16:48:56 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	if (!content)
	{
		content_size = 0;
		tmp->content = NULL;
	}
	else
	{
		tmp->content = (void*)malloc(content_size);
		if (!(tmp->content))
		{
			free(tmp);
			return (NULL);
		}
		ft_memcpy(tmp->content, content, content_size);
	}
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}

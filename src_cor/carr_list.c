/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carr_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:30:44 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/06 20:30:45 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_carr *new_curr(int id_par, t_cor *cor)
{
	t_carr	*new;
	int		i;

	new = NULL;
	new = (t_carr *)ft_memalloc(sizeof(t_carr));
	if (!new)
		return (NULL);
	new->id_par = id_par;
	new->i = 0;
	new->carry = 0;
	new->num = ++cor->n_curr;
	i = 0;
	new->reg[i] = -id_par;
	while (++i <= REG_NUMBER)
		new->reg[i] = 0;
	new->next = NULL;
	return (new);
}

void	add_curr(t_carr **all_carr, t_carr *new)
{
	if (!all_carr || !*all_carr)
		return ;
	new->next = *all_carr;
	*all_carr = new;
}

int		len_curr(t_carr *list)
{
	int i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_carr	*remove_head(t_cor *cor, t_carr *curr)
{
	cor->carr = curr->next;
    if (cor->v_print[3] == 1)
        ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", curr->num, cor->live.cyc_to_die);
    free(curr);
    curr = cor->carr;
    return (curr);
}

t_carr *remove_elem(t_carr *curr, t_carr **prev, t_cor *cor)
{
	curr = curr->next;
	free((*prev)->next);
	(*prev)->next = curr;
    if (cor->v_print[3] == 1)
        ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n", curr->num, cor->live.cyc_to_die);

    return (curr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:13:41 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/06 20:13:43 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				ft_zjmp(t_cor *cor, t_carr *tmp)
{
	short	t_ind;
	short	a;

	if (tmp->carry == 1)
	{
		t_ind = read_byte_2(cor->code, tmp->cur + 1);
		a = idx_mod(t_ind);
		tmp->cur = mem_size(tmp->cur + a);
		tmp->i = 0;
	}
	else
		tmp->i = 3;
}

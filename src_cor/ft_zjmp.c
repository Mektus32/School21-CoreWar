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

	t_ind = read_byte_2(cor->code, tmp->cur + 1);
	a = idx_mod(t_ind);
	if (tmp->carry == 1)
	{
		tmp->cur = mem_size(tmp->cur + a);
		tmp->i = 0;
		if(cor->v_print[2] == 1)
		ft_printf("P    %d | zjmp %d OK\n", tmp->id_par, t_ind);
	}
	else
		tmp->i = 3;
	if ((cor->v_print[2] == 1) && !(tmp->carry))
		ft_printf("P    %d | zjmp %d FAILED\n", tmp->num, t_ind);
}

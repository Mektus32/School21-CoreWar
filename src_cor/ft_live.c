/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:46:07 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/23 21:46:09 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_live(t_cor *cor, t_carr *tmp)
{
	unsigned char	t_dir[DIR_SIZE];

	tmp->cycles_live = cor->live->cycles;
	ft_memcpy_all(t_dir, cor->code, 4, tmp->cur + 1);
	if (IFR16(t_dir) == (int)tmp->reg[0])
	{
		tmp->live = 1;
		cor->live->id_live = tmp->id_par;
	}
	else
		tmp->live = 0;
	tmp->i = 1 + DIR_SIZE;
}

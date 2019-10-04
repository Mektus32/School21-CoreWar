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
/*
** 	Если указанный в качестве аргумента операции live номер совпадает
**	 с номером игрока, то она засчитывает, что это игрок жив.
**	 Например, если значение аргумента равно -2, значит игрок с номером 2 жив.
** */



void	ft_live(t_cor *cor, t_carr *tmp)
{
	unsigned int	t_dir;
	int dit;
	int i;

	i = 0;
	tmp->cycles_live = cor->live->cycles;
	t_dir = read_byte_4(cor->code, tmp->cur + 1);
	while (i < cor->n)
	{
		dit = t_dir;
		if ((cor->m_ch[i]->id + 1) == -dit)
		{
			//cor->m_ch[i]->live = 1;
			cor->live->id_live = i + 1;
			//ft_printf("A process shows that player %s is alive\n", cor->m_ch[i]->prog_name);
		}
		i++;
	}
	tmp->cycles_live = cor->live->cycles;
	tmp->live = 1;
	cor->live->live_count++;
	tmp->i = 1 + DIR_SIZE;
}

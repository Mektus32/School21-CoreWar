/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:46:07 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/13 21:26:28 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** 	Если указанный в качестве аргумента операции live номер совпадает
**	 с номером игрока, то она засчитывает, что это игрок жив.
**	 Например, если значение аргумента равно -2, значит игрок с номером 2 жив.
**
** я не могу засчитать каретке которая в аргументе, что она жива
*/

void	ft_live(t_cor *cor, t_carr *tmp)
{
	unsigned int	t_dir;
	int				i;

	i = 0;
	tmp->cycles_live = cor->live->cyc;
	cor->live->live_count++;
	t_dir = read_byte_4(cor->code, tmp->cur + 1);
	while (i < cor->n)
	{
		if ((cor->m_ch[i]->id + 1) == -t_dir)
		{
			cor->live->id_live = i + 1;
			// if (!cor->visual.vis)
			// 	ft_printf("A process shows that player %s is alive\n",
			// 	cor->m_ch[i]->prog_name);
		}
		i++;
	}
	tmp->i = 5;
}
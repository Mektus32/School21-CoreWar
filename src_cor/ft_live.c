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
	t_carr			*arg_check;


	tmp->cycles_live = cor->live->cycles;
	ft_memcpy_all(&t_dir, cor->code, 4, tmp->cur + 1);
	//Если указанный в качестве аргумента операции live номер совпадает
	// с номером игрока, то она засчитывает, что это игрок жив.
	// Например, если значение аргумента равно -2, значит игрок с номером 2 жив.
//	if (-tmp->id_par == IFR16(t_dir))
//	{
//
//		cor->live->id_live = tmp->id_par;
//	}
	arg_check = cor->carr;
	while (arg_check)
	{
		if (-(arg_check->num) == IFR16(t_dir))
		{
			//arg_check->live = 1;
			//cor->live->id_live = arg_check->id_par;
			arg_check->cycles_live = cor->live->cycles;
			cor->live->id_live = arg_check->id_par;
		}
		arg_check = arg_check->next;
	}

	tmp->live = 1;
//	if (tmp->reg[0] == -tmp->id_par)
//	{
//		tmp->live = 1;
//		cor->live->id_live = tmp->id_par;
//	}
//	else
//		tmp->live = 0;
//	//cor->live->id_live = tmp->id_par;
//	if (IFR16(t_dir) <= cor->n)
//	{
//		arg_check = cor->carr;
//		while (arg_check)
//		{
//			if (-(arg_check->num) == IFR16(t_dir))
//			{
//				arg_check->live = 1;
//				//cor->live->id_live = arg_check->id_par;
//				arg_check->cycles_live = cor->live->cycles;
//				cor->live->id_live = arg_check->id_par;
//
//			}
//			arg_check = arg_check->next;
//		}
//	}
//	if (IFR16(t_dir) == (int)tmp->reg[0])
//	{
//
//		tmp->live = 1;
//		cor->live->id_live = tmp->id_par;
//	}
//	else
//		tmp->live = 0;
	cor->live->live_count++;
	tmp->i = 1 + DIR_SIZE;
}

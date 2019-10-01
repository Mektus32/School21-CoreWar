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
	int dit;


	tmp->cycles_live = cor->live->cycles;
	ft_memcpy_all(&t_dir, cor->code, 4, tmp->cur + 1, 0);
	//Если указанный в качестве аргумента операции live номер совпадает
	// с номером игрока, то она засчитывает, что это игрок жив.
	// Например, если значение аргумента равно -2, значит игрок с номером 2 жив.
	int i = 0;
	while (i < cor->n)
	{
		dit = IFR16(t_dir);
		if ((cor->m_ch[i]->id + 1) == -dit)
		{
			cor->m_ch[i]->live = 1;
			cor->live->id_live = i + 1;
		}
		i++;
	}
//	arg_check = cor->carr;
//	while (arg_check)
//	{
//		if (-(arg_check->num) == IFR16(t_dir))
//		{
//			//arg_check->live = 1;
//			//cor->live->id_live = arg_check->id_par;
//			cor->live->live_count++;
//			arg_check->cycles_live = cor->live->cycles;
//			cor->live->id_live = arg_check->id_par;
//		}
//		arg_check = arg_check->next;
//	}
	tmp->cycles_live = cor->live->cycles;
	tmp->live = 1;
	cor->live->live_count++;

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
	//cor->live->live_count++;
	tmp->i = 1 + DIR_SIZE;
}

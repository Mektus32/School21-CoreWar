/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_lfork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:48:39 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/06 19:48:41 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** Операция fork делает копию каретки. И эту копию размещает
** по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
** создадим копию каретки и вставим в начало
** lfork не усекает по IDX_MOD
*/

/*
** void	printList(t_carr *tmp)
** {
** 	t_carr	*car;
**
** 	car = tmp;
** 	while(car)
** 	{
** 		ft_printf("{%d %d} --> ", car->num, car->id_par);
** 		car = car->next;
** 	}
** 	ft_printf("LLL\n");
** }
*/

t_carr				*ft_fork(t_cor *cor, t_carr *tmp, int l)
{
	t_carr			*new;
	short			t_ind;
	int				k;

	new = new_curr(tmp->id_par, cor);
	new->carry = tmp->carry;
	new->cycles_live = tmp->cycles_live;
	//new->num = cor->n_curr++;
	k = -1;
	while (++k < REG_NUMBER)
		new->reg[k] = tmp->reg[k];
	t_ind = read_byte_2(cor->code, tmp->cur + 1);
	if (l == 0)
		new->cur = tmp->cur + idx_mod(t_ind);
	else
		new->cur = tmp->cur + t_ind;
	new->cur = mem_size(new->cur);
	add_curr(&(cor->carr), new);
	tmp->i = 3;
	if (cor->v_print[2] == 1)
		ft_printf("P    %d |%sfork %d (%d)\n", tmp->num, (l) ? " l" : " ",
			  t_ind, tmp->cur + t_ind % IDX_MOD);
	return (cor->carr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_cor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:31:25 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/06 20:31:26 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** ПРОВЕРКА
** Текущее количество проверок» включает и проводящуюся в
** данный момент проверку.
** Мертвой считается каретка, которая выполняла операцию live cyc_to_die
** циклов назад или более.
** Также мертвой считается любая каретка, если cyc_to_die <= 0.
**
** Если количество выполненных за cyc_to_die период
** операций live больше или равно NBR_LIVE, значение cyc_to_die
** уменьшается на CYCLE_DELTA.
** Если в течение MAX_CHECKS раз проверок Cycle_to_die не уменьшался //
** то cycle_to_die уменьшается на CYCLE_DELTA
** Если же количество выполненных операций live меньше установленного лимита,
** то виртуальная машина просто запоминает, что была выполнена проверка.
** Количество операций live обнуляется после каждой
** проверки вне зависимости от ее результатов.
** check_to_die - изменяет кол-во циклов до смерти
** check_live - удаляет каретки
*/

static void	check_to_die(t_cor *cor)
{
	t_carr		*carr;

	cor->live->counter++;
	if (cor->live->live_count >= NBR_LIVE)
	{
		cor->live->cyc_to_die = cor->live->cyc_to_die - CYCLE_DELTA;
		cor->live->counter = 0;
	}
	cor->live->live_count = 0;
	if (cor->live->counter == MAX_CHECKS)
	{
		cor->live->cyc_to_die = cor->live->cyc_to_die - CYCLE_DELTA;
		cor->live->counter = 0;
	}
	if (cor->live->cyc_to_die <= 0)
	{
		carr = cor->carr;
		while (carr)
			carr = remove_head(cor, carr);
	}
}

static void	check_live(t_cor *cor)
{
	t_carr *carr;
	t_carr *prev;

	carr = cor->carr;
	prev = NULL;
	while (carr)
	{
		if ((cor->live->cyc - carr->cycles_live) >= cor->live->cyc_to_die)
		{
			if (cor->carr == carr)
				carr = remove_head(cor, carr);
			else
				carr = remove_elem(carr, &prev);
		}
		else
		{
			prev = carr;
			carr = carr->next;
		}
	}
	check_to_die(cor);
}

/*
** основная ф игры
** print_dump_code - печатает код и выходит из игры, если есть dump
** do_op - переходит к оперециям 2 из них изменяют код(st и sti), и одна состояние лайв
** check_live - в т.ч. меняет время до смерти и
** делает проверку(удаляет лишние каретки)
*/

void	go_cor(t_cor *cor)
{
	t_carr	*tmp;

	while (cor->carr)
	{
		if (cor->carr && (cor->live->cyc++ == cor->nbr_cyc || cor->nbr_cyc == 0))
			print_dump_code(cor);
		tmp = cor->carr;
		while (tmp)
		{
			if (tmp->cycles_to == 0)
			{
 				tmp->cur = mem_size(tmp->cur + tmp->i);
				tmp->prog = read_byte_1(cor->code, tmp->cur);
				tmp->cycles_to = ft_cycles_to(tmp->prog);
				tmp->i = 0;
			}
			if (--tmp->cycles_to == 0)
					do_op(cor, tmp);
			tmp = tmp->next;
		}
		if ((cor->live->cyc - cor->live->cyc_tmp) >= cor->live->cyc_to_die)
		{
			cor->live->cyc_tmp = cor->live->cyc;
			check_live(cor);
		}
	}
}

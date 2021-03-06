/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_cor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 19:51:44 by qgilbert          #+#    #+#             */
/*   Updated: 2020/03/03 19:51:46 by qgilbert         ###   ########.fr       */
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
** cor->live->live_count - кол - во  операуий лайв
** cor->live->counter - счетчик проверок от последнего изменени cyc_to_die
*/

/*
** if (cor->live.cyc_to_die <= 0)
** {
** carr = cor->carr;
** while (carr)
** {
** carr = remove_head(cor, carr);
** 		}
**	}
*/

static t_carr	*check_to_die(t_cor *cor)
{
	(cor->live.counter)++;
	if (cor->live.live_count >= NBR_LIVE)
	{
		cor->live.cyc_to_die = cor->live.cyc_to_die - CYCLE_DELTA;
		if (cor->v_print[1] == 1)
			ft_printf("Cycle to die is now %d\n", cor->live.cyc_to_die);
		cor->live.counter = 0;
	}
	else if (cor->live.counter == MAX_CHECKS)
	{
		cor->live.cyc_to_die = cor->live.cyc_to_die - CYCLE_DELTA;
		cor->live.counter = 0;
		if (cor->v_print[1] == 1)
			ft_printf("Cycle to die is now %d\n", cor->live.cyc_to_die);
	}
	cor->live.live_count = 0;
	return (cor->carr);
}

static t_carr	*check_live(t_cor *cor)
{
	t_carr *carr;
	t_carr *prev;

	carr = cor->carr;
	prev = NULL;
	while (carr)
	{
		if ((cor->live.cyc - carr->cycles_live) >= cor->live.cyc_to_die)
		{
			if (cor->carr == carr)
				carr = remove_head(cor, carr);
			else
				carr = remove_elem(carr, &prev, cor);
		}
		else
		{
			prev = carr;
			carr = carr->next;
		}
	}
	return (cor->carr);
}

/*
** основная ф игры
** print_dump_code - печатает код и выходит из игры, если есть dump
** do_op - переходит к оперециям 2 из них изменяют код(st и sti),
** и одна состояние лайв
** check_live - в т.ч. меняет время до смерти и
** делает проверку(удаляет лишние каретки)
*/

static void		cycles_read(t_cor *cor, t_carr *tmp)
{
	if (tmp->cycles_to == 0)
	{
		tmp->cur = mem_size(tmp->cur + tmp->i);
		tmp->prog = read_byte_1(cor->code, tmp->cur);
		tmp->cycles_to = ft_cycles_to(tmp->prog);
		tmp->i = 0;
	}
}

/*
** основная ф игры
** print_dump_code - печатает код и выходит из игры, если есть dump
** do_op - переходит к оперециям 2 из них изменяют код(st и sti),
** и одна состояние лайв
** check_live - в т.ч. меняет время до смерти и
** делает проверку(удаляет лишние каретки)
*/

static	void	go_cor_2(t_cor *cor, t_carr *tmp)
{
	if (cor->carr && (cor->live.cyc == cor->nbr_cyc || cor->nbr_cyc == 0))
		print_dump_code(cor);
	tmp = cor->carr;
	cor->visual.vis ? visual(cor) : 0;
	if ((cor->live.cyc++ - cor->live.cyc_tmp) >= cor->live.cyc_to_die)
	{
		tmp = check_to_die(cor);
		cor->live.cyc_tmp = cor->live.cyc - 1;
	}
	if (cor->v_print[1] == 1)
		ft_printf("It is now cycle %d\n", cor->live.cyc);
	while (tmp)
	{
		cycles_read(cor, tmp);
		if (--tmp->cycles_to == 0)
		{
			do_op(cor, tmp);
			print_adv(cor, tmp);
		}
		tmp = tmp->next;
	}
	if ((cor->live.cyc - cor->live.cyc_tmp) >= cor->live.cyc_to_die ||
		cor->live.cyc_to_die <= 0)
		tmp = check_live(cor);
}

void			go_cor(t_cor *cor)
{
	while (cor->carr)
		go_cor_2(cor, NULL);
	cor->visual.vis ? stop_visual(cor) : 0;
}

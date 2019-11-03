#include "corewar.h"

void	zero_live(t_cor *cor)
{
	cor->live->cycles_temp = 0;
	cor->live->id_live = cor->n;
	cor->live->cycles = 0;
	cor->live->live_count = 0;
	cor->live->cycles_to_die = CYCLE_TO_DIE;
	cor->live->check_count = 0;
}

unsigned char *inttobyte(int a)
{
	unsigned char *bt;
	unsigned char c;

	bt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 4);
	bt[0] = (unsigned char)((a >> 24) & 0xff);
	c = bt[0];
	bt[1] = (unsigned char)((a >> 16) & 0xff);
	c = bt[1];
	bt[2] = (unsigned char)((a >> 8) & 0xff);
	c = bt[2];
	bt[3] = (unsigned char)((a >> 0) & 0xff);
	c = bt[3];
	return (bt);
}

/*
** ПРОВЕРКА
** Текущее количество проверок» включает и проводящуюся в данный момент проверку.
** Мертвой считается каретка, которая выполняла операцию live cycles_to_die циклов назад или более.
** Также мертвой считается любая каретка, если cycles_to_die <= 0.
**
** Если количество выполненных за cycles_to_die период
** операций live больше или равно NBR_LIVE, значение cycles_to_die уменьшается на CYCLE_DELTA.
** Если в течение MAX_CHECKS раз проверок Cycle_to_die не уменьшался //
** то cycle_to_die уменьшается на CYCLE_DELTA
** Если же количество выполненных операций live меньше установленного лимита,
** то виртуальная машина просто запоминает, что была выполнена проверка.
** Количество операций live обнуляется после каждой
** проверки вне зависимости от ее результатов.
*/

t_carr	*remove_head(t_cor *cor, t_carr *curr)
{
	cor->carr = curr->next;
	free(curr);
	curr = cor->carr;
	return (curr);
}


t_carr	*remove_elem(t_carr *curr, t_carr **prev)
{
	curr = curr->next;
	free((*prev)->next);
	(*prev)->next = curr;
	return (curr);
}

void	check_live(t_cor *cor)
{
	t_carr *carr;
	t_carr *prev;

	int i;
	int k;
	static int pre_cycles_to_die = CYCLE_TO_DIE;
	static int counter = 0;
	carr = cor->carr;
	prev = NULL;
	//i = len_curr(carr);
	if (cor->live->cycles == 22242 || cor->live->cycles == 21756)//
	{


		k = 0;
		i = 0;
	}
	//ft_printf("check cycle = %d, n_cur = %d\n", cor->live->cycles,cor->n_curr);
	//ft_printf("to die = %d\n",cor->live->cycles_to_die);
	while(carr)
	{

		if (((cor->live->cycles - carr->cycles_live) >= cor->live->cycles_to_die) || cor->live->cycles < 0)
		{
			if (cor->carr == carr)
				carr = remove_head(cor, carr);
			else
				carr = remove_elem(carr, &prev);
			//remove_curr_if(cor, carr->num);
//			i++;
//			remove_curr(cor, carr);
		}
		else
		{
			prev = carr;
			carr = carr->next;
		}

//			k++;
	}


	counter++;
	if (cor->live->live_count >= NBR_LIVE)
		cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
	cor->live->live_count = 0;
	if (cor->live->cycles_to_die == pre_cycles_to_die)
	{
		if (counter == MAX_CHECKS)
		{
			cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
			counter = 0;
			pre_cycles_to_die = cor->live->cycles_to_die;
		}
	}
	else
	{
		counter = 0;
		//pre_cycles_to_die = cor->live->cycles_to_die;
	}
	if (cor->live->cycles_to_die <= 0)
	{
		carr = cor->carr;
		while (carr)
			carr = remove_head(cor, carr);

	}


	//ft_printf("n_cur_after = %d\n", cor->n_curr);
}


void go_cor(t_cor *cor)
{
	int i;
	t_carr	*tmp;
	zero_live(cor);
	while (cor->carr)
	{
		if (cor->carr && (cor->live->cycles == cor->nbr_cycles || cor->nbr_cycles == 0))
		{
			print_dump_code(cor);
			exit_print("");
		}

		if (cor->live->cycles == 22242)
		{
			i++;
		}

		tmp = cor->carr;
		// для каждой каретки иначинаем исполнять код
		while (tmp)
		{
			if (tmp->cycles_to == 0)
			{
 				tmp->cur = (tmp->cur + tmp->i) % MEM_SIZE;
				tmp->cur = mem_size(tmp->cur);
				tmp->prog = read_byte_1(cor->code, tmp->cur);
				tmp->cycles_to = ft_cycles_to(tmp->prog);
				tmp->i = 0;
			}
//			tmp = tmp->next;
//		}
//		tmp = cor->carr;
//		while (tmp)
//		{
			if (--tmp->cycles_to == 0)
					do_op(cor, tmp);

			tmp = tmp->next;
		}

		//Проверка происходит через каждые cycles_to_die циклов пока значение cycles_to_die больше нуля.
		// А после того, как его значение станет меньше или равным нулю, проверка начинает проводиться после каждого цикла.
		//cor->live->cycles++;

		//cor->live->cycles_to_die <= 0 - игра закончилась -удяляем все каретки
		cor->live->cycles++;
		if ((cor->live->cycles - cor->live->cycles_temp) ==  cor->live->cycles_to_die)
		{
			cor->live->cycles_temp = cor->live->cycles;
			check_live(cor);
		}


	}
}




#include "corewar.h"

void	zero_live(t_cor *cor)
{
	cor->live->id_live = cor->n;
	cor->live->cycles = 0;//количество прошедших с начала игры циклов
	cor->live->live_count = 0;
	cor->live->cycles_to_die = CYCLE_TO_DIE;
	cor->live->check_count = 0;
}

unsigned char *inttobyte(int a)
{
	unsigned char *bt;

	bt = malloc(sizeof(unsigned char) * 5);
	bt[0] = (a >> 24);
	bt[1] = (a >> 16) ;
	bt[2] = (a >> 8);
	bt[3] = a;
	bt[4] = '\0';

	return (bt);
}


void	check_live(t_cor *cor)
{
	t_carr *carr;

	carr = cor->carr;
	//«Текущее количество проверок» включает и проводящуюся в
	// данный момент проверку.

	cor->live->check_count++;
	while(carr)
	{
		if ((cor->live->cycles - carr->cycles_live >= cor->live->cycles_to_die) ||//Мертвой считается каретка, которая выполняла операцию live cycles_to_die циклов назад или более.
		cor->live->cycles_to_die <= 0 || carr->live == 0 )//Также мертвой считается любая каретка, если cycles_to_die <= 0.
		//||carr->id_par != -carr->reg[0]
		{
			remove_curr_if(cor, carr->num);
			//cor->n_curr--;
		}
		else
			cor->live->id_live = carr->id_par;
 		//carr->cycles_live = cor->live->cycles;
		carr = carr->next;
	}
	//Если количество выполненных за cycles_to_die период
	// операций live больше или равно NBR_LIVE, значение cycles_to_die уменьшается на CYCLE_DELTA.
	if (cor->live->live_count >= NBR_LIVE)
	{
		cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
		cor->live->check_count = 0;
	}
	else
		cor->live->check_count = 0;

	//Если в течение MAX_CHECKS раз проверок Cycle_to_die не уменьшался //
	// то cycle_to_die уменьшается на CYCLE_DELTA
	if (cor->live->check_count == MAX_CHECKS)
	{
		cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
		cor->live->check_count = 0;
	}
	//Количество операций live обнуляется после каждой
	// проверки вне зависимости от ее результатов.
	cor->live->live_count = 0;


}

void go_cor(t_cor *cor)
{

	t_carr	*tmp;

	// обнулим live
	zero_live(cor);
	while (cor->carr && cor->live->cycles_to_die)
	{
		tmp = cor->carr;
		// для каждой каретки иначинаем исполнять код
		while (tmp)
		{
			if (tmp->cycles_to == 0)
			{
				tmp->cur = (tmp->cur + tmp->i) % MEM_SIZE;
				tmp->i = 0;
				ft_memcpy_all(&tmp->prog, cor->code, 1, tmp->cur);
				tmp->cycles_to = ft_cycles_to(tmp->prog);
			}
			// если не доступная операция - двигаем каретку
			if (--(tmp->cycles_to) == 0)
			{
				if	(tmp->prog == 1)
					ft_live(cor, tmp);
				else if (tmp->prog == 2)
					ft_ld(cor, tmp, 0);
				else if (tmp->prog == 3)
					ft_st(cor, tmp);
				else if (tmp->prog == 4)
					ft_add(cor, tmp);
				else if (tmp->prog == 5)
					ft_sub(cor, tmp);
				else if (tmp->prog == 6)
					ft_and(cor, tmp);
				else if (tmp->prog == 7)
					ft_or(cor, tmp);
				else if (tmp->prog == 8)
					ft_xor(cor, tmp);
				else if (tmp->prog == 9)
					ft_zjmp(cor, tmp);
				else if (tmp->prog == 10)
					ft_ldi(cor, tmp, 0);
				else if (tmp->prog == 11)
					ft_sti(cor, tmp);
				else if (tmp->prog == 12)
					ft_fork(cor, tmp, 0);
				else if (tmp->prog == 13)
					ft_ld(cor, tmp, 1);
				else if (tmp->prog == 14)
                	ft_ldi(cor, tmp, 1);
				else if (tmp->prog == 15)
                	ft_fork(cor, tmp, 1);
				else if (tmp->prog == 16)
					ft_aff(cor, tmp);
				else
					tmp->i = 1;
			}
			tmp = tmp->next;
		}

		//Проверка происходит через каждые cycles_to_die циклов пока значение cycles_to_die больше нуля.
		// А после того, как его значение станет меньше или равным нулю, проверка начинает проводиться после каждого цикла.
		if (++cor->live->cycles == cor->nbr_cycles)
		{
			print_dump_code(cor);
			exit_print("");
		}
		if (--(cor->live->cycles_to_die) <=0)// || (cor->live->cycles && (cor->live->cycles % cor->live->cycles_to_die == 0)))
			check_live(cor);
//я не понимаю -  всегда буду удалять каретку

	}
}

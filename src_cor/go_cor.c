#include "corewar.h"

void	zero_live(t_cor *cor)
{
	cor->live->id_live = cor->n;
	cor->live->cycles = 0;//количество прошедших с начала игры циклов
	cor->live->live_count = 0;
	cor->live->cycles_to_die = CYCLE_TO_DIE;
	cor->live->check_count = 0;
}

void	check_live(t_cor *cor)
{
	t_carr *carr;

	carr = cor->carr;
	cor->live->check_count++;
	while(carr)
	{
		if (cor->live->cycles - carr->cycles_live >= CYCLE_TO_DIE ||//Мертвой считается каретка, которая выполняла операцию live cycles_to_die циклов назад или более.
		cor->live->cycles_to_die)//Также мертвой считается любая каретка, если cycles_to_die <= 0.
		{
			remove_curr_if(&cor->carr, carr->num);
			cor->n_curr--;
		}
		else
			carr->cycles_live = cor->live->cycles;
		carr = carr->next;
	}
	//Если количество выполненных за cycles_to_die период
	// операций live больше или равно NBR_LIVE, значение cycles_to_die уменьшается на CYCLE_DELTA.
	if (cor->live->live_count >= NBR_LIVE)
	{
		cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
		cor->live->check_count = 0;
	}
	//Если в течение MAX_CHECKS раз проверок Cycle_to_die не уменьшался //
	// то cycle_to_die уменьшается на CYCLE_DELTA
	if (cor->live->check_count == MAX_CHECKS)
	{
		cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
		cor->live->check_count = 0;
	}
	cor->live->live_count = 0;


}

void go_cor(t_cor *cor)
{
	unsigned char	op[1];
	t_carr	*tmp;
	int i;

	// обнулим live
	i = 0;
	zero_live(cor);
	//
	while (cor->carr && cor->live->cycles_to_die && i < 5)
	{
		tmp = cor->carr;
		// для каждой каретки иначинаем исполнять код
		while (tmp)
		{
			
			//printf("c = %x\n", op[0]);

			// если не доступная операция - двигаем каретку
			if (tmp->prog < 1 || tmp->prog > 16)
			{
				tmp->cur = (tmp->cur + 1) % MEM_SIZE;
				ft_memcpy(&tmp->prog, cor->code + tmp->cur, 1);
				tmp->cycles_to = ft_cycles_to(tmp->prog);

			}
			if (tmp->cycles_to == 0  )
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
				ft_memcpy(&tmp->prog, (cor->code + tmp->cur % MEM_SIZE) , 1);
				tmp->cycles_to = ft_cycles_to(tmp->prog);
			}
			else
				tmp->cycles_to--;
			tmp = tmp->next;
		}
		//Проверка происходит через каждые cycles_to_die циклов пока значение cycles_to_die больше нуля.
		// А после того, как его значение станет меньше или равным нулю, проверка начинает проводиться после каждого цикла.
		if (cor->live->cycles_to_die <=0 || (cor->live->cycles && (cor->live->cycles % cor->live->cycles_to_die == 0)))
			check_live(cor);
		cor->live->cycles++;
	}
}
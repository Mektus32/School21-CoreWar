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
		}
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
			ft_memcpy(op, cor->code + cor->carr->cur, 1);
			printf("c = %x\n", op[0]);
			if	(op[0] == 0)
				ft_live(cor, 1);
//	else if (c[0] == 1)
//		f_ld(cor, i);
			else if (op[0] == 2)
				ft_ld(cor, 1);
		//	else
			tmp = tmp->next;
		}
		//Проверка происходит через каждые cycles_to_die циклов пока значение cycles_to_die больше нуля.
		// А после того, как его значение станет меньше или равным нулю, проверка начинает проводиться после каждого цикла.
		if (cor->live->cycles_to_die <=0 || (cor->live->cycles && (cor->live->cycles % cor->live->cycles_to_die == 0)))
			check_live(cor);
		//op = cor->code + 0;
		i++;


	}


}
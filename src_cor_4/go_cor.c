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

	bt = ft_memalloc(sizeof(unsigned char) * 4);
	bt[0] = (unsigned char)((a >> 24) & 0xff);
	bt[1] = (unsigned char)((a >> 16) & 0xff);
	bt[2] = (unsigned char)((a >> 8) & 0xff);
	bt[3] = (unsigned char)((a >> 0) & 0xff);
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
		//Мертвой считается каретка, которая выполняла операцию live cycles_to_die циклов назад или более.
		//Также мертвой считается любая каретка, если cycles_to_die <= 0.
		//
		if ((cor->live->cycles_to_die <= 0) || ((cor->live->cycles - carr->cycles_live) >= cor->live->cycles_to_die))
			remove_curr_if(cor, carr->num);
		carr = carr->next;
	}
	//Если количество выполненных за cycles_to_die период
	// операций live больше или равно NBR_LIVE, значение cycles_to_die уменьшается на CYCLE_DELTA.
	if (cor->live->live_count >= NBR_LIVE)// || (cor->live->check_count >= MAX_CHECKS))
	{
		cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
		cor->live->check_count = 0;
	}
	//Если же количество выполненных операций live меньше установленного лимита,
	// то виртуальная машина просто запоминает, что была выполнена проверка.

	//Если в течение MAX_CHECKS раз проверок Cycle_to_die не уменьшался //
	// то cycle_to_die уменьшается на CYCLE_DELTA
	if (cor->live->check_count >= MAX_CHECKS)
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


	zero_live(cor);
	while (cor->carr && cor->live->cycles_to_die)
	{

		if (cor->live->cycles == 2137)
			cor->live->cycles = 2137;
		tmp = cor->carr;
		// для каждой каретки иначинаем исполнять код
		while (tmp)
		{
			if (tmp->cycles_to == 0)
			{
				tmp->cur = (tmp->cur + tmp->i) % MEM_SIZE;
				tmp->i = 0;
				while (tmp->cur < 0)
					tmp->cur += MEM_SIZE;
				tmp->prog = read_byte_1(cor->code, tmp->cur);
				//ft_memcpy_all(&tmp->prog, cor->code, 1, tmp->cur, 0);
				tmp->cycles_to = ft_cycles_to(tmp->prog);
			}
			if (--tmp->cycles_to == 0)
				do_op(cor, tmp);
			tmp = tmp->next;
		}

		//Проверка происходит через каждые cycles_to_die циклов пока значение cycles_to_die больше нуля.
		// А после того, как его значение станет меньше или равным нулю, проверка начинает проводиться после каждого цикла.

		if (cor->carr)
		{
			if ((cor->live->cycles % cor->live->cycles_to_die == 0) || (cor->live->cycles_to_die <= 0))// || (cor->live->cycles && (cor->live->cycles % cor->live->cycles_to_die == 0)))
				check_live(cor);
		}
		if (++cor->live->cycles == cor->nbr_cycles || cor->nbr_cycles == 0)
		{
			print_dump_code(cor);
			exit_print("");
		}

//я не понимаю -  всегда буду удалять каретку

	}

}

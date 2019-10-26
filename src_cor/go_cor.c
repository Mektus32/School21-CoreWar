#include "corewar.h"

void	zero_live(t_cor *cor)
{
	cor->live->cycles_temp = 0;
	cor->live->id_live = cor->n;
	cor->live->cycles = 0;//количество прошедших с начала игры циклов
	cor->live->live_count = 0;
	//cor->live->cycle_new = 0;
	cor->live->cycles_to_die = CYCLE_TO_DIE;
	cor->live->check_count = 0;
}

unsigned char *inttobyte(int a)
{
	unsigned char *bt;

	bt = (unsigned char *)ft_memalloc(sizeof(unsigned char) * 4);
	bt[0] = (unsigned char)((a >> 24) & 0xff);
	bt[1] = (unsigned char)((a >> 16) & 0xff);
	bt[2] = (unsigned char)((a >> 8) & 0xff);
	bt[3] = (unsigned char)((a >> 0) & 0xff);
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

void	check_live(t_cor *cor)
{
	t_carr *carr;

	static int pre_cycles_to_die = CYCLE_TO_DIE;
	static int counter = 0;

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
		pre_cycles_to_die = cor->live->cycles_to_die;
	}
	carr = cor->carr;
	while(carr)
	{
		if (((cor->live->cycles - carr->cycles_live)) >= cor->live->cycles_to_die)
			remove_curr_if(cor, carr->num);
		carr = carr->next;
	}
	if (cor->live->cycles_to_die <= 0)
	{
		carr = cor->carr;
		while (carr)
		{
			remove_curr_if(cor, carr->num);
			carr = carr->next;
		}

	}
}


void go_cor(t_cor *cor)
{
	int i;
	t_carr	*tmp;
	zero_live(cor);
	while (cor->carr)
	{
		if (cor->live->cycles == 2977)
		{
			i++;
		}
		cor->live->cycles++;
		tmp = cor->carr;
		// для каждой каретки иначинаем исполнять код
		while (tmp)
		{
			if (tmp->cycles_to == 0) {
				tmp->cur = (tmp->cur + tmp->i) % MEM_SIZE;
				tmp->i = 0;
				while (tmp->cur < 0)
					tmp->cur += MEM_SIZE;
				tmp->prog = read_byte_1(cor->code, tmp->cur);
				tmp->cycles_to = ft_cycles_to(tmp->prog);
			}
			tmp = tmp->next;
		}
		tmp = cor->carr;
		while (tmp)
		{
			if (--tmp->cycles_to == 0)
			{
				//все таки надо продолжать обычную итерацию
				if (tmp->prog == 15 || tmp->prog == 12)
				{
					//ft_printf("p1 = %p\n", tmp->next);
//					do_op(cor, tmp);
//					tmp = cor->carr;
					//continue;
				}
//				else
					do_op(cor, tmp);
			}
			//ft_printf("p2 = %p\n", tmp->next);
			tmp = tmp->next;
		}

		//Проверка происходит через каждые cycles_to_die циклов пока значение cycles_to_die больше нуля.
		// А после того, как его значение станет меньше или равным нулю, проверка начинает проводиться после каждого цикла.
		//cor->live->cycles++;

		//cor->live->cycles_to_die <= 0 - игра закончилась -удяляем все каретки
		i = cor->live->cycles - cor->live->cycles_temp;
		if ((cor->live->cycles - cor->live->cycles_temp) ==  cor->live->cycles_to_die)
		{
			cor->live->cycles_temp = cor->live->cycles;
			check_live(cor);
		}
		//cor->live->cycles++;
		if (cor->carr && (cor->live->cycles == cor->nbr_cycles || cor->nbr_cycles == 0))
		{
			print_dump_code(cor);
			exit_print("");
		}
	}
}

//void	check_live(t_cor *cor) {
//	t_carr *carr;
//	static int counter = 0;
//	static int pre_cycles_to_die = CYCLE_TO_DIE;
//
//	carr = cor->carr;
//	//«Текущее количество проверок» включает и проводящуюся в
//	// данный момент проверку.
//
//	cor->live->check_count++;
//	while (carr) {
//		//Мертвой считается каретка, которая выполняла операцию live cycles_to_die циклов назад или более.
//		//Также мертвой считается любая каретка, если cycles_to_die <= 0.
//
//		//
//		//ft_printf("num_1 = ",cor->z)
//
////		if (((cor->live->cycles - carr->cycles_live) >= cor->live->cycles_to_die) || cor->live->cycles_to_die <= 0)
//		if (cor->live == 0 || cor->live->cycles_to_die <= 0) {
//
////		{
//			//по идее удаляет только одну каретку с номером carr->num (он уникален) carr->num)
//			remove_curr_if(cor, carr->num);
//			//carr = cor->carr;
//		}
//		else
//		{
//			cor->live = 0;
//			//carr->cycles_live = cor->live->cycles;// типо каретка сказала что жива в операции
//			carr = carr->next;
//
//
//		}
//		//Если количество выполненных за cycles_to_die период
//		// операций live больше или равно NBR_LIVE, значение cycles_to_die уменьшается на CYCLE_DELTA.
//
//		if (cor->live->live_count >= NBR_LIVE)
//			cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
//		if (cor->live->cycles_to_die == pre_cycles_to_die) {
//			counter++;
//			if (counter == MAX_CHECKS) {
//				cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
//				counter = 0;
//				pre_cycles_to_die = cor->live->cycles_to_die;
//			}
//		} else {
//			counter = 0;
//			pre_cycles_to_die = cor->live->cycles_to_die;
//		}
//
//		//	if (cor->live->live_count >= NBR_LIVE || (cor->live->check_count >= MAX_CHECKS))
////	{
////		cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
////		cor->live->check_count = 0;
////
////	}
//
//		//Если же количество выполненных операций live меньше установленного лимита,
//		// то виртуальная машина просто запоминает, что была выполнена проверка.
//
//		//Если в течение MAX_CHECKS раз проверок Cycle_to_die не уменьшался //
//		// то cycle_to_die уменьшается на CYCLE_DELTA
////	if (cor->live->check_count >= MAX_CHECKS)
////	{
////		cor->live->cycles_to_die = cor->live->cycles_to_die - CYCLE_DELTA;
////		cor->live->check_count = 0;
////	}
//		//Количество операций live обнуляется после каждой
//		// проверки вне зависимости от ее результатов.
//		cor->live->live_count = 0;
//	}
//}


//	void go_cor(t_cor *cor) {
//		t_carr *tmp;
//		zero_live(cor);
//		while (cor->carr)
//		{
//			//сначала проведем проверку
//			//Проверка происходит через каждые cycles_to_die циклов пока значение cycles_to_die больше нуля.
//			// А после того, как его значение станет меньше или равным нулю, проверка начинает проводиться после каждого цикла.
//			if (cor->live->cycles_to_die <= 0 ||
//				((cor->live->cycles - cor->live->cycles_temp) == cor->live->cycles_to_die))
//			{
//				check_live(cor);
//				cor->live->cycles_temp = cor->live->cycles;
//			}
////		if (((cor->live->cycle_new % cor->live->cycles_to_die) == 0) && cor->live->cycle_new != 0)
////			check_live(cor);
//			//сделали проверку - увеличили цикл, он понадобиться в live
//			//cor->live->cycle_new++;
//			cor->live->cycles++;
//			cor->live->cycles_temp++;
//			tmp = cor->carr;
//			// для каждой каретки иначинаем исполнять код
//			while (tmp) {
//				if (tmp->cycles_to == 0) {
//					tmp->cur = (tmp->cur + tmp->i) % MEM_SIZE;
//					tmp->i = 0;
//					while (tmp->cur < 0)
//						tmp->cur += MEM_SIZE;
//					tmp->prog = read_byte_1(cor->code, tmp->cur);
//					tmp->cycles_to = ft_cycles_to(tmp->prog);
//				}
//				if (--tmp->cycles_to == 0)
//					do_op(cor, tmp);
//				tmp = tmp->next;
//			}
//			// похоже не имеет значение когда делать
////		tmp = cor->carr;
////		while (tmp)
////		{
////			if (--tmp->cycles_to == 0)
////				do_op(cor, tmp);
////			tmp = tmp->next;
////		}
//			if (cor->live->cycles == cor->nbr_cycles || cor->nbr_cycles == 0) {
//				print_dump_code(cor);
//				exit_print("");
//			}
//		}
//		if (cor->carr) {
//			tmp = cor->carr;
//			while (tmp) {
//				remove_curr_if(cor, tmp->num);
//				tmp = cor->carr;
//			}
//		}
//	}



#include "corewar.h"

/*
**  Операция fork делает копию каретки. И эту копию размещает по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
** создадим копию каретки и вставим в начало
** lfork не усекает по IDX_MOD
**
**/


#include "corewar.h"

/*
**  Операция fork делает копию каретки. И эту копию размещает по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
** создадим копию каретки и вставим в начало
** lfork не усекает по IDX_MOD
**
**/

void	printList(t_carr *tmp)
{
	t_carr	*car;

	car = tmp;
	while(car)
	{
		ft_printf("{%d %d} --> ", car->num, car->id_par);
		car = car->next;
	}
	ft_printf("LLL\n");
}



t_carr				*ft_fork(t_cor *cor, t_carr *tmp, int l)
{
	t_carr			*new;
	short			t_ind;
	int				k;

	new = new_curr(tmp->id_par);
	new->carry = tmp->carry;
	new->cycles_live = tmp->cycles_live;
	new->num = cor->n_curr++;
	k = -1 ;
	while (++k < REG_NUMBER)
		new->reg[k] = tmp->reg[k];
	t_ind = read_byte_2(cor->code, tmp->cur + 1);
	if (l == 0)
		new->cur = tmp->cur + idx_mod(t_ind);
	else
		new->cur = tmp->cur + t_ind;
	new->cur = mem_size(new->cur);

	add_curr(&(cor->carr), new);
	//printList(cor->carr);

	tmp->i = 3;
	return(cor->carr);
}



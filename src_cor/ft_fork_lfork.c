#include "corewar.h"

/*
**  Операция fork делает копию каретки. И эту копию размещает по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
** создадим копию каретки и вставим в начало
** lfork не усекает по IDX_MOD
**
**/

//short read_byte_2_min(const char *src, int i)
//{
//	short	c_2;
//
//	while (i < 0)
//		i = MEM_SIZE + i;
//	c_2 = 0;
//	c_2 = (c_2 << 8);
//	c_2 = c_2 | (char)src[(i) % MEM_SIZE];
//	c_2 = (c_2 << 8);
//	c_2 = c_2 | (char)src[(i + 1) % MEM_SIZE];
//	return ((short)c_2);
//}


#include "corewar.h"

/*
**  Операция fork делает копию каретки. И эту копию размещает по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
** создадим копию каретки и вставим в начало
** lfork не усекает по IDX_MOD
**
**/

//short read_byte_2_min(const char *src, int i)
//{
//	short	c_2;
//
//	while (i < 0)
//		i = MEM_SIZE + i;
//	c_2 = 0;
//	c_2 = (c_2 << 8);
//	c_2 = c_2 | (char)src[(i) % MEM_SIZE];
//	c_2 = (c_2 << 8);
//	c_2 = c_2 | (char)src[(i + 1) % MEM_SIZE];
//	return ((short)c_2);
//}

void	printList(t_carr *tmp)
{
	t_carr *car;

	car = tmp;
	while(car)
	{
		ft_printf("{%d %d} --> ", car->num, car->id_par);
		car = car->next;
	}
	ft_printf("LLL\n");
}

short	idx_mod(short t_ind)
{
	if (t_ind < 0)
	{
		t_ind = t_ind * (-1);
		t_ind = t_ind % IDX_MOD;
		return (-1 * t_ind);
	}
	t_ind = t_ind % IDX_MOD;
	return (t_ind);
}

int mem_size(int cur)
{
	if (cur < 0)
	{
		while (cur < 0)
			cur += MEM_SIZE;
		//return (cur);
	}
	cur = cur % MEM_SIZE;
	return (cur);
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



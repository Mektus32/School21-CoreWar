#include "corewar.h"

void				ft_fork(t_cor *cor, t_carr *tmp, int l)
{
	t_carr			*new;
	unsigned char	t_dir[IND_SIZE];
	int k;
	unsigned char *p;
	k = -1;

	// создадим копию каретки и вставим в начало
	new = new_curr(tmp->id_par);
	new->carry = tmp->carry;
	new->cycles_live = tmp->cycles_live;
	new->num = (cor->n_curr)++;
	//возможно дб мемкопи, тк при удалении каретки тмп аозможно удалятся и нью значения
	while (++k < REG_NUMBER)
		new->reg[k] = tmp->reg[k];
	add_curr(&(cor->carr), new);
	ft_memcpy(&t_dir, cor->code + (tmp->cur) % MEM_SIZE, IND_SIZE);
	//Операция fork делает копию каретки. И эту копию размещает по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
	k = IFR8(t_dir);//t_dir[0] << 8 | t_dir[1];
	//надо ли брать со знаком -?
	p = inttobyte((new->reg[0]));
	ft_memcpy_all((cor->code) + k % (IDX_MOD - l * IDX_MOD + 1 * l), p, 4);
	tmp->i = 3;
}
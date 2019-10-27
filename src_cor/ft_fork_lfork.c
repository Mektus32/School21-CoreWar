#include "corewar.h"

/*
**  Операция fork делает копию каретки. И эту копию размещает по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
** создадим копию каретки и вставим в начало
** lfork не усекает по IDX_MOD
**
**/

short read_byte_2_min(const char *src, int i)
{
	short	c_2;

	while (i < 0)
		i = MEM_SIZE + i;
	c_2 = 0;
	c_2 = (c_2 << 8);
	c_2 = c_2 | (char)src[(i) % MEM_SIZE];
	c_2 = (c_2 << 8);
	c_2 = c_2 | (char)src[(i + 1) % MEM_SIZE];
	return ((short)c_2);
}

t_carr				*ft_fork(t_cor *cor, t_carr *tmp, int l)
{
	t_carr			*new;
	short			t_ind;
	int				k;

	new = new_curr(tmp->id_par);
	new->carry = tmp->carry;
	new->cycles_live = tmp->cycles_live;
	new->num = (cor->n_curr)++;
	k = 0;
	while (++k < REG_NUMBER)
		new->reg[k] = tmp->reg[k];
	t_ind = read_byte_2_min(cor->code, tmp->cur + 1);
//	while (t_dir < 0)
//		t_dir += MEM_SIZE;
	if (l == 0)
		new->cur = tmp->cur + t_ind % IDX_MOD;
	else
		new->cur = tmp->cur + t_ind;
//	while (new->cur < 0)
//		new->cur += MEM_SIZE;
	new->cur = new->cur % MEM_SIZE;
	new->i = 0;
	add_curr(&(cor->carr), new);
	//сделаю копию каретки и размещу ее
	//copy_p(cor->code, cor->code, new->cur, tmp->cur);
	tmp->i = 3;
	//tmp->cur = new->cur;
	return(cor->carr);


}

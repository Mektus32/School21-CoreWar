#include "corewar.h"

/*
**  Операция fork делает копию каретки. И эту копию размещает по адресу <ПЕРВЫЙ_АРГУМЕНТ> % IDX_MOD.
** создадим копию каретки и вставим в начало
** lfork не усекает по IDX_MOD
**
**/

t_carr				*ft_fork(t_cor *cor, t_carr *tmp, int l)
{
	t_carr			*new;
	short			t_dir;
	int				k;

	new = new_curr(tmp->id_par);
	new->carry = tmp->carry;
	new->cycles_live = tmp->cycles_live;
	new->num = (cor->n_curr)++;
	k = -1;
	while (++k < REG_NUMBER)
		new->reg[k] = tmp->reg[k];
	t_dir = read_byte_2(cor->code, tmp->cur + 1);
//	while (t_dir < 0)
//		t_dir += MEM_SIZE;
	if (l == 0)
		new->cur = tmp->cur + t_dir % IDX_MOD;
	else
		new->cur = tmp->cur + t_dir % (IDX_MOD - l * IDX_MOD + 1 * l);
	while (new->cur < 0)
		new->cur += MEM_SIZE;
	new->i = 0;
	add_curr(&(cor->carr), new);
	//сделаю копию каретки и размещу ее
	//copy_p(cor->code, cor->code, new->cur, tmp->cur);
	tmp->i = 3;
	//tmp->cur = new->cur;
	return(cor->carr);


}

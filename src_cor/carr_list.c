#include "corewar.h"

t_carr	*new_curr(int id_par)
{
	t_carr	*new;
	int		i;

	new = NULL;
	new = (t_carr *)ft_memalloc(sizeof(t_carr));
	if (!new)
		return (NULL);
	new->id_par = id_par;
	new->i = 0;
	new->carry = 0;
	i = 0;
	new->reg[i] = -id_par;
	while (++i <= REG_NUMBER)
		new->reg[i] = 0;
	new->next = NULL;
	return (new);
}

void	add_curr(t_carr **all_carr, t_carr *new)
{
	if (!all_carr || !*all_carr)
		return ;
	new->next = *all_carr;
	*all_carr = new;
}

int		len_curr(t_carr *list)
{
	int i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_carr	*remove_head(t_cor *cor, t_carr *curr)
{
	cor->carr = curr->next;
	free(curr);
	curr = cor->carr;
	return (curr);
}

t_carr	*remove_elem(t_carr *curr, t_carr **prev)
{
	curr = curr->next;
	free((*prev)->next);
	(*prev)->next = curr;
	return (curr);
}

t_carr	*carr_list(t_cor *cor)
{
	int		i;
	t_carr	*carr;
	t_carr	*carr_tmp;

	carr = new_curr(1);
	carr->cycles_to = 0;
	carr->i = 0;
	carr->cur = 0;
	carr->num = 0;
	cor->n_curr = 1;
	i = 2;
	while (i <= cor->n)
	{
		carr_tmp = new_curr(i);
		carr_tmp->cur = (i - 1) * (MEM_SIZE / cor->n);
		carr_tmp->cycles_to = 0;
		carr_tmp->i = 0;
		carr_tmp->num = (i - 1);
		add_curr(&carr, carr_tmp);
		cor->n_curr++;
		i++;
	}
	return (carr);
}

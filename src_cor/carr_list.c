#include "corewar.h"

t_carr *new_curr(int id_par)
{
	t_carr *new;
	int i;

	new = NULL;
	new = (t_carr*)malloc(sizeof(t_carr));
	if (!new)
		return (NULL);
	new->id_par = id_par;
	new->cur = 0;
	new->carry = 0;
	i = 0;
	new->reg[i] = -id_par;
	while (++i < REG_NUMBER)
		new->reg[i] = 0;
	new->live = 1;
	new->prog = 0;
	new->cycles_to = 0;
	new->next = NULL;
	return (new);
}

void add_curr(t_carr **all_carr, t_carr *new)
{
	if (!all_carr)
		return ;
	new->next = *all_carr;
	*all_carr = new;
}

void remove_curr_if(t_carr **all_carr, int num)
{
	t_carr *carr;
	t_carr	*tmp;

	carr = *all_carr;
	if (carr->num == num)
	{
		*all_carr = carr->next;
		free(carr);
		return ;
	}
	tmp = carr;
	while (carr)
	{
		if (carr->num == num)
		{
			tmp->next = carr->next;
			free(carr);
			return ;
		}
		tmp = carr;
		carr = carr->next;
	}
}

int	ft_cycles_to(char p)
{
	int cycles;

	cycles = -1;
	if (p == 1 || p == 4 || p == 5 || p == 13)
		cycles = 10;
	else if (p == 2 || p == 3)
		cycles = 5;
	else if (p == 6 || p == 7 || p == 8)
		cycles = 6;
	else if (p == 9)
		cycles = 20;
	else if (p == 10 || p == 11)
		cycles = 25;
	else if (p == 12)
		cycles = 800;
	else if (p == 14)
		cycles = 50;
	else if (p == 15)
		cycles = 1000;
	else if (p == 16)
		cycles = 2;
	return (cycles);
}

t_carr *carr_list(t_cor *cor)
{
	int	i;
	t_carr *carr;
	t_carr *carr_tmp;

	carr = new_curr(1);
	ft_memcpy(&carr->prog, cor->code + carr->cur, 1);
	carr->cycles_to = ft_cycles_to(carr->prog);
	carr->cur = 0;
	i = 2;
	while (i <= cor->n)
	{
		carr_tmp = new_curr(i);
		carr_tmp->cur = (i - 1) * (MEM_SIZE / cor->n);
		ft_memcpy(&carr_tmp->prog, cor->code + carr_tmp->cur, 1);
		carr_tmp->cycles_to = ft_cycles_to(carr_tmp->prog);
		add_curr(&carr, carr_tmp);
		i++;
	}
	return (carr);
}
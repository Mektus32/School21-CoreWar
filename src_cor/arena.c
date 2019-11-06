/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:30:26 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/06 20:30:27 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** После того, как на арене были размещены исполняемые коды чемпионов,
** на начало каждого из них устанавливается каретка.**
** надо создать список для всех кареток -
** добавляем сверху сверху начинаем заполнять
** cor->carr = carr_list(cor);
*/

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

void	memset_colormap(t_cor *cor, int i)
{
	int		k;

	k = i * (MEM_SIZE / cor->n);
	while (k < (i + 1) * (MEM_SIZE / cor->n))
	{
		cor->colormap[k] = i;
		k++;
	}
}

void	arena(t_cor *cor)
{
	int		i;
	char	*code_i;

	cor->code = (char *)ft_memalloc(sizeof(char) * MEM_SIZE);
	cor->live = (t_live *)ft_memalloc(sizeof(t_live));
	cor->colormap = (int *)ft_memalloc(sizeof(int) * MEM_SIZE);
	i = 0;
	while (i < cor->n)
	{
		code_i = cor->code + i * (MEM_SIZE / cor->n);
		ft_strncpy_all((code_i), cor->m_ch[i]->code, cor->m_ch[i]->prog_size);
		memset_colormap(cor, i);
		i++;
	}
//	i = 0;
//while (i < MEM_SIZE)
//{
//	ft_printf("%d",cor->colormap[i]);
//	i++;
//	if ((i % (MEM_SIZE / cor->n)) == 0)
//		ft_printf("\n");
//}
	cor->carr = carr_list(cor);
	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < cor->n)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
				(cor->m_ch[i])->prog_size, (cor->m_ch[i])->prog_name,
				(cor->m_ch[i])->comment);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 20:30:26 by qgilbert          #+#    #+#             */
/*   Updated: 2019/11/12 17:00:53 by ojessi           ###   ########.fr       */
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

	cor->n_curr = 0;
	carr = new_curr(1, cor);
	carr->cur = 0;
	i = 2;
	while (i <= cor->n)
	{
		carr_tmp = new_curr(i, cor);
		carr_tmp->cur = (i - 1) * (MEM_SIZE / cor->n);
		add_curr(&carr, carr_tmp);
		i++;
	}
	return (carr);
}

void	memset_colormap(t_cor *cor, int i)
{
	unsigned int		k;

	k = 0;
	while (k < cor->m_ch[i].prog_size)
	{
		cor->colormap[k + i * (MEM_SIZE / cor->n)] = i + 1;
		k++;
	}
}

void	arena(t_cor *cor)
{
	int				i;
	unsigned char	*code_i;

	i = 0;
	while (i < cor->n)
	{
		code_i = cor->code + i * (MEM_SIZE / cor->n);
		ft_strncpy_all((code_i), cor->m_ch[i].code, cor->m_ch[i].prog_size);
		memset_colormap(cor, i);
		i++;
	}
	cor->carr = carr_list(cor);
	i = 0;
	if (cor->n)
		ft_printf("Introducing contestants...\n");
	else
		exit_print(cor, "Usage: ./corewar [-dump <N> | -n --stealth"
		"| -viz --visual | -a <champion1.cor> --on_viz_aff | -v --debug]\n");
	while (i < cor->n)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", i + 1,
				cor->m_ch[i].prog_size, cor->m_ch[i].prog_name,
				cor->m_ch[i].comment);
		i++;
	}
}

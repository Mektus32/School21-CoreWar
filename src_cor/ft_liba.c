/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_liba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:24:41 by qgilbert          #+#    #+#             */
/*   Updated: 2019/10/16 21:27:04 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_cor(t_cor *cor)
{
	int	i;
	t_carr *carr;
	i = 0;
	free(cor->code);
	free(cor->colormap);
	free(cor->live);
	carr = cor->carr;
	while (carr)
		carr = remove_head(cor, carr);
	while (i < cor->n)
	{
		free(cor->m_ch[i]->code);
		free(cor->m_ch[i]);
		i++;
	}
	free(cor);
}

char	*ft_strncpy_all(char *dest, const char *source, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;

	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
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
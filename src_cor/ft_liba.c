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

void	exit_print(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	free_cor(t_cor *cor)
{
	int	i;

	i = 0;
	free(cor->code);
	free(cor->colormap);
	free(cor->live);
	while (cor->carr)
		remove_curr_if(cor, cor->carr->num);
	while (i < cor->n)
	{
		free(cor->m_2[i]->code);
		free(cor->m_2[i]);
		free(cor->m_ch[i]);
		free(cor->m_2[i]);
		if (cor->m_2[i]->code)
		{
			free(cor->m_2[i]->code);
			free(cor->m_2[i]);
		}
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

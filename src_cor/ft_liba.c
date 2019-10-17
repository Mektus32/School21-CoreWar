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
		//free(cor->m_ch[i]);
		//free(cor->m_2[i]);
//		if (cor->m_2[i]->code)
//		{
//			free(cor->m_2[i]->code);
//			free(cor->m_2[i]);
//		}
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

char *base16_2(unsigned c)
{
	char *b2;
	int		i;

	i = 7;
	b2 = (char *)malloc(sizeof(char) * 9);
	b2[8] = '\0';
	while (i >= 0)
	{
		b2[i] = c % 2;
		c = c/2;
		i--;
	}
	return  (b2);
}

char *base16_2_cor(t_cor *cor, t_carr *tmp)
{
	unsigned char	*k;

	k = malloc(sizeof(char));
	ft_memcpy(k, cor->code + (tmp->cur + 1) % MEM_SIZE, 1);
	free(k);
	return  (base16_2(k[0]));
}
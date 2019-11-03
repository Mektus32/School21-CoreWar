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
	//ft_putstr_fd(str, 2);
	ft_printf("%s\n", str);
	exit(0);
}

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

char		*base16_2_cor(t_cor *cor, t_carr *tmp)
{
	char		*b2;
	unsigned	char c;
	char	bb;
	int			i;

	b2 = (char *)ft_memalloc(sizeof(char) * 9);
	c = read_byte_1(cor->code, tmp->cur + 1);
	i = 7;
	while (i >= 0)
	{
		bb = c % 2;
		b2[i--] = c % 2;

		c = c / 2;
	}
	return  (b2);
}

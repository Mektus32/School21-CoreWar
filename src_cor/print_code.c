/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:31:23 by qgilbert          #+#    #+#             */
/*   Updated: 2019/10/16 21:31:24 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** ft_printf("%s\n", str);
*/

void	take_flag_v(t_cor *cor, int num, int *i)
{
	int k;

	if (num < 1)
		exit_print(cor, "-v <positive integer>\n");
	k = 0;
	while (k < 4)
	{
		cor->v_print[k++] = num % 2;
		num = num / 2;
	}
	*i += 2;
}

void	exit_print(t_cor *cor, char *str)
{
	free_cor(cor);
	ft_putstr_fd(str, 2);
	exit(0);
}

void	print_dump_code(t_cor *cor)
{
	int i;
	int k;

	k = 0;
	i = 0;
	ft_printf("%.4p : ", k);
	while (i < MEM_SIZE)
	{
		if (i % (64) == 0 && i != 0)
		{
			k++;
			ft_printf("\n");
			ft_printf("%.4p : ", k * 64);
		}
		ft_printf("%.2x ", cor->code[i]);
		i++;
	}
	ft_printf("\n");
	exit(0);
}

void	print_adv(t_cor *cor, t_carr *tmp)
{
	int		i;

	if (cor->v_print[2] == 1 && tmp->i > 1)
	{
		ft_printf("ADV %d (0x%04x -> 0x%04x) ",
				tmp->i, tmp->cur, tmp->cur + tmp->i);
		i = tmp->cur;
		while (i < (tmp->cur + tmp->i))
		{
			ft_printf("%02x ",
					cor->code[i % MEM_SIZE], cor->code[i % MEM_SIZE]);
			++i;
		}
		ft_printf("\n");
	}
}

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

void print_dump_code(t_cor *cor)
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
		if (cor->code[i] < 0)
			ft_printf("%.2x ", 256 - -1 * cor->code[i]);
		else
			ft_printf("%.2x ", cor->code[i]);
		i++;
	}
	exit_print("");
}

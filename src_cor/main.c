/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgilbert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 20:01:04 by qgilbert          #+#    #+#             */
/*   Updated: 2019/09/04 20:01:05 by qgilbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int main(int ac, char **av)
{
	t_cor *cor;

	if (ac > 1)
	{
		cor = parse_av(ac, av);
		arena(cor);
		go_cor(cor);
		ft_printf("Contestant %d, \"%s\", has won !\n", cor->live->id_live,
				(cor->m_ch[cor->live->id_live - 1])->prog_name);
		free_cor(cor);
	}
	else
		exit_print("no file");
	return (0);
}

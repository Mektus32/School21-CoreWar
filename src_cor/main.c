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

static void	zero_live(t_cor *cor)
{
	cor->live.cyc_tmp = 0;
	cor->live.id_live = cor->n;
	cor->live.cyc = 0;
	cor->live.live_count = 0;
	cor->live.cyc_to_die = CYCLE_TO_DIE;
}

/*
** parse_av - просматривает аргументы,
** инициальзирует главную структуру
** arena - если чемпионы валидны
** 	cor->code = (char *)ft_memalloc(sizeof(char) * MEM_SIZE);
**	cor->live = (t_live *)ft_memalloc(sizeof(t_live));
**	cor->colormap = (int *)ft_memalloc(sizeof(int) * MEM_SIZE);
** go_cor - ама игра
*/

int			main(int ac, char **av)
{
	t_cor cor;

	ft_bzero(&cor, sizeof(t_cor));
	if (ac > 1)
	{
		parse_av(ac, av, &cor);
		arena(&cor);
		zero_live(&cor);
		cor.visual.vis ? init_window(&cor) : 0;
		ft_printf("kek\n");
		go_cor(&cor);
		if (cor.n)
		    ft_printf("Contestant %d, \"%s\", has won !\n", cor.live.id_live,
				(cor.m_ch[cor.live.id_live - 1]).prog_name);
		free_cor(&cor);
	}
	else
		exit_print("Usage: ./corewar [-dump N | -n --stealth | -v visualizator]"
	" [-a] <champion1.cor>");
	endwin();
	return (0);
}

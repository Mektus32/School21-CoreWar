/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 14:11:07 by ojessi            #+#    #+#             */
/*   Updated: 2019/11/12 16:53:20 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
** if (cor->code[i * 64 + j] < 0)
** mvwprintw(main_win, line, col, "%.2x ", 256 - -1
** * cor->code[i * 64 + j]);
** else
*/

void	panel_help(t_cor *cor, WINDOW *main_win, int i, int line)
{
	int	col;
	int	j;

	col = 2;
	j = -1;
	while (++j < 64)
	{
		if (cor->bold[i * 64 + j] && (cor->bold[i * 64 + j] -= 1))
			wattron(main_win, A_BOLD);
		wattron(main_win, COLOR_PAIR(cor->colormap[i * 64 + j]));
		mvwprintw(main_win, line, col, "%.2x ", cor->code[i * 64 + j]);
		wattroff(main_win, COLOR_PAIR(cor->colormap[i * 64 + j]));
		if (cor->bold[i * 64 + j])
			wattroff(main_win, A_BOLD);
		col += 3;
	}
}

void	write_map_color(t_cor *cor, int pos, int len, t_carr *carg)
{
	int	i;

	if (cor->visual.vis)
	{
		i = -1;
		while (++i < len)
		{
			cor->colormap[MEM(pos + i)] = (unsigned char)(carg->id_par);
			cor->bold[MEM(pos + i)] = 70;
		}
	}
}

void	stop_visual(t_cor *cor)
{
	if (cor->visual.vis)
	{
		end_game(cor);
		while (1)
			if (getch() == 32)
			{
				delwin(cor->visual.main_win);
				delwin(cor->visual.side_win);
				endwin();
				exit(1);
			}
	}
}

void	end_game(t_cor *cor)
{
	wattron(cor->visual.side_win, COLOR_PAIR(4));
	mvwprintw(cor->visual.side_win, 1, 2, "** END OF THE GAME **");
	wattroff(cor->visual.side_win, COLOR_PAIR(4));
	wattron(cor->visual.side_win, COLOR_PAIR(1));
	mvwprintw(cor->visual.side_win, 32, 2, "Winner ->[%d] %s ",
			cor->live.id_live, (cor->m_ch[cor->live.id_live - 1]).prog_name);
	wattroff(cor->visual.side_win, COLOR_PAIR(1));
	wrefresh(cor->visual.side_win);
}

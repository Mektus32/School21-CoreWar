/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_cicle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:11:29 by ojessi            #+#    #+#             */
/*   Updated: 2019/11/12 16:57:30 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

WINDOW	*create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0, 0);
	wrefresh(local_win);
	return (local_win);
}

int		players(WINDOW *side_win, int line, t_cor *cor)
{
	int		i;
	int		j;
	t_carr	*tmp;

	i = -1;
	while (++i < cor->n)
	{
		wattron(side_win, COLOR_PAIR(cor->m_ch[i]->id + 1));
		mvwprintw(side_win, line++, 2, "Player %d : %s \n",
				cor->m_ch[i]->id + 1, cor->m_ch[i]->prog_name);
		wattroff(side_win, COLOR_PAIR(cor->m_ch[i]->id + 1));
		j = 0;
		tmp = cor->carr;
		while (tmp)
		{
			tmp->id_par == i + 1 ? ++j : 0;
			tmp = tmp->next;
		}
		mvwprintw(side_win, line++, 4, "Lives in current period :\t\t%d    ",
				j);
		line++;
	}
	return (line);
}

void	side_panel(WINDOW *side_win, t_cor *cor)
{
	int line;

	line = 7;
	if (cor->visual.pause == 0)
	{
		wattron(side_win, COLOR_PAIR(2));
		mvwprintw(side_win, 1, 2, "** PAUSED  **");
		wattroff(side_win, COLOR_PAIR(2));
	}
	else
	{
		wattron(side_win, COLOR_PAIR(1));
		mvwprintw(side_win, 1, 2, "** RUNNING **");
		wattroff(side_win, COLOR_PAIR(1));
	}
	mvwprintw(side_win, 3, 2, "Cycle : %d ", cor->live->cyc);
	mvwprintw(side_win, 5, 2, "Processes : %d ", cor->n);
	line = players(side_win, line, cor);
	mvwprintw(side_win, line, 2, "CYCLE_TO_DIE : %d ", cor->live->cyc_to_die);
	mvwprintw(side_win, line + 2, 2, "CYCLE_DELTA : %d ", CYCLE_DELTA);
}

void	paint_carg(t_cor *cor)
{
	t_carr		*carg;
	int			color;

	carg = cor->carr;
	while (carg)
	{
		carg->cur = MEM(carg->cur);
		color = cor->colormap[carg->cur] + 10;
		wattron(cor->visual.main_win, COLOR_PAIR(color));
		mvwprintw(cor->visual.main_win, carg->cur / 64 + 1,
				2 + (carg->cur % 64) * 3, "%.2x", cor->code[carg->cur]);
		wattroff(cor->visual.main_win, COLOR_PAIR(color));
		carg = carg->next;
	}
	wrefresh(cor->visual.main_win);
}

void	main_panel(WINDOW *main_win, t_cor *cor)
{
	int		i;
	int		j;
	int		line;
	int		col;

	line = 1;
	i = -1;
	while (++i < 64)
	{
		col = 2;
		j = -1;
		while (++j < 64)
		{
			if (cor->bold[i * 64 + j] && (cor->bold[i * 64 + j] -= 1))
				wattron(main_win, A_BOLD);
			wattron(main_win, COLOR_PAIR(cor->colormap[i * 64 + j]));
			if (cor->code[i * 64 + j] < 0)
				mvwprintw(main_win, line, col, "%.2x ", 256 - -1
						* cor->code[i * 64 + j]);
			else
				mvwprintw(main_win, line, col, "%.2x ", cor->code[i * 64 + j]);
			wattroff(main_win, COLOR_PAIR(cor->colormap[i * 64 + j]));
			if (cor->bold[i * 64 + j])
				wattroff(main_win, A_BOLD);
			col += 3;
		}
		line++;
	}
	paint_carg(cor);
}

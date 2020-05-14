/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:43:32 by ojessi            #+#    #+#             */
/*   Updated: 2019/11/12 16:52:44 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	create_field(t_cor *cor)
{
	cor->visual.main_win = create_newwin(66, 195, 1, 3);
	cor->visual.side_win = create_newwin(66, 56, 1, 200);
	nodelay(cor->visual.main_win, 1);
	nodelay(cor->visual.side_win, 1);
	draw(cor);
}

void	draw(t_cor *cor)
{
	curs_set(0);
	usleep(cor->visual.delay);
	side_panel(cor->visual.side_win, cor);
	main_panel(cor->visual.main_win, cor);
	box(cor->visual.side_win, 0, 0);
	box(cor->visual.main_win, 0, 0);
	wrefresh(cor->visual.main_win);
	wrefresh(cor->visual.side_win);
}

void	init_window(t_cor *cor)
{
	initscr();
	cor->visual.delay = DELAY;
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	create_field(cor);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_BLACK, COLOR_RED);
	init_pair(13, COLOR_BLACK, COLOR_BLUE);
	init_pair(14, COLOR_BLACK, COLOR_CYAN);
	refresh();
}

int		graph_cycle(t_cor *cor)
{
	int		ch;

	ch = getch();
	if (ch == 27)
		return (1);
	if (ch == ' ')
	{
		cor->visual.pause++;
		cor->visual.pause %= 2;
	}
	else if (ch == '+' && cor->visual.delay <= 50000)
		cor->visual.delay += 1000;
	else if (ch == '-' && cor->visual.delay > 1000)
		cor->visual.delay -= 1000;
	else if (ch == KEY_MOUSE)
	{
//		if (getmouse(&event) == OK)
//			;
	}
	return (0);
}

void	visual(t_cor *cor)
{
	draw(cor);
	graph_cycle(cor);
	while (cor->visual.pause == 0)
	{
		wattron(cor->visual.side_win, COLOR_PAIR(2));
		mvwprintw(cor->visual.side_win, 1, 2, "** PAUSED  **");
		wattroff(cor->visual.side_win, COLOR_PAIR(2));
		mvwprintw(cor->visual.side_win, 23, 2, "DELTA_TIME_PRINT : %d ",
				cor->visual.delay);
		wrefresh(cor->visual.side_win);
		if (graph_cycle(cor) == 1)
		{
			delwin(cor->visual.main_win);
			delwin(cor->visual.side_win);
			free_cor(cor);
			endwin();
			exit(1);
		}
	}
}

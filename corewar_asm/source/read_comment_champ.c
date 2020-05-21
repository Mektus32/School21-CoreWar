/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_comment_champ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 09:28:31 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/07 21:35:54 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"
#include <stdio.h> //<del

void	close_files(t_assm *assm)
{
	ft_printf("Writing output program to %s\n", assm->name_cor);
	ft_strdel(&assm->name_cor);
	close(assm->fd_cor);
	close(assm->fd_s);
}

void	error(const char *msg, t_assm *assm)
{
	if (assm->line)
		ft_strdel(&(assm->line));
	ft_printf("%s Line [%d].\n", msg, assm->counter_line);
	remove(assm->name_cor);
	exit(0);
}

void	read_name_champion(char *line, t_assm *assm)
{
	static int	i = -1;
	char		*temp;

	while (*line)
	{
		if (*line == '"')
			return ;
		if (i >= PROG_NAME_LENGTH - 1)
			error("length of name is invalid", assm);
		assm->head.prog_name[++i] = *line;
		line++;
	}
	assm->head.prog_name[++i] = '\n';
	get_next_line(assm->fd_s, &temp);
	assm->counter_line++;
	read_name_champion(temp, assm);
	ft_strdel(&temp);
}

void	working_name(char *line, t_assm *assm)
{
	while (*line)
	{
		if (!ft_isspace(*line) && *line != '"')
			error("Syntax error after .name", assm);
		if (*line == '"')
		{
			read_name_champion(line + 1, assm);
			return ;
		}
		line++;
	}
	error("Error name", assm);
}

void	read_comment_champion(char *line, t_assm *assm)
{
	static int	i = -1;
	char		*temp;

	while (*line)
	{
		if (*line == '"')
			return ;
		if (i >= COMMENT_LENGTH - 1)
			error("length of comment is invalid", assm);
		assm->head.comment[++i] = *line;
		line++;
	}
	assm->head.comment[++i] = '\n';
	get_next_line(assm->fd_s, &temp);
	assm->counter_line++;
	read_comment_champion(temp, assm);
	ft_strdel(&temp);
}

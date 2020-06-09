/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_name_comment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 09:31:24 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/09 19:11:57 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	parse_comment(char *line, t_assm *assm)
{
	while (*line)
	{
		if (!ft_isspace(*line) && *line != '"')
			error("Syntax error after .comment", assm);
		if (*line == '"')
		{
			read_comment_champion(line + 1, assm);
			return ;
		}
		line++;
	}
	error("Error comment", assm);
}

int		parse_dot(t_assm *assm, char *line, int *name, int *comment)
{
	if (!(ft_strncmp(line, NAME_CMD_STRING, 5)) && *name == 0)
	{
		parse_name(line + 5, assm);
		*name = 1;
		return (0);
	}
	else if (!(ft_strncmp(line, COMMENT_CMD_STRING, 8)) && *comment == 0)
	{
		parse_comment(line + 8, assm);
		*comment = 1;
		return (0);
	}
	else
		error("Lexical error.", assm);
	return (1);
}

int		search_char(t_assm *assm, int *name, int *comment)
{
	char	*line;

	line = assm->line;
	while (*line)
	{
		if (*line == COMMENT_CHAR || *line == ALT_COMMENT_CHAR)
			return (0);
		if (*line == '.')
			return (parse_dot(assm, line, name, comment));
		if (ft_isprint(*line))
			error("Syntax error at token", assm);
		line++;
	}
	return (0);
}

void	read_name_comment(t_assm *assm)
{
	int		name;
	int		comment;

	name = 0;
	comment = 0;
	while (get_next_line(assm->fd_s, &(assm->line)))
	{
		assm->counter_line++;
		search_char(assm, &name, &comment);
		if (name == 1 && comment == 1)
			break ;
		ft_strdel(&(assm->line));
	}
	ft_strdel(&(assm->line));
	if (!(name == 1 && comment == 1))
		error("Syntax error at token", assm);
}

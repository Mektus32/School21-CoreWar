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

void	working_comment(char *line, t_assm *assm)
{
	while (*line)
	{
		if (*line == '"')
		{
			read_comment_champion(line + 1, assm);
			return ;
		}
		line++;
	}
	error("Error name", assm);
}

int		working_dot(t_assm *assm, char *line, int *count)
{
	if (!(ft_strncmp(line, NAME_CMD_STRING, 5)))
	{
		working_name(line + 5, assm);
		*count += 1;
		return (0);
	}
	else if (!(ft_strncmp(line, COMMENT_CMD_STRING, 8)))
	{
		working_comment(line + 8, assm);
		*count += 1;
		return (0);
	}
	else
		error("Lexical error.", assm);
	return (1);
}

int		search_char(t_assm *assm, char *line, int *count)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR || *line == ALT_COMMENT_CHAR)
			return (0);
		if (*line == '.')
			return (working_dot(assm, line, count));
		if (ft_isprint(*line))
			error("Syntax error at token", assm);
		line++;
	}
	return (0);
}

void	create_file_cor(t_assm *assm, char *name)
{
	assm->name_cor = dot_cor(name);
	if ((assm->fd_cor = open(assm->name_cor,
			O_WRONLY | O_TRUNC | O_CREAT)) == -1)
		sys_err_rm(assm, "Error create file.\n");
}

void	read_name_comment(t_assm *assm)
{
	char	*line;
	int		count;

	line = NULL;
	count = 0;
	while (get_next_line(assm->fd_s, &line))
	{
		assm->counter_line++;
		search_char(assm, line, &count);
		if (count == 2)
		{
			ft_strdel(&line);
			break ;
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (count != 2)
		error("Syntax error at token", assm);
}

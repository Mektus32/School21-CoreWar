/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_agr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:28:02 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/13 12:12:47 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	working_instruction(t_assm *assm, char *line)
{
	while (*line)
	{
		if (*line == COMMENT_CHAR || *line == ALT_COMMENT_CHAR)
			return ;
		if (isprint_char(*line))
		{
			instruction(assm, line);
			return ;
		}
		line++;
	}
}

void	read_instruction(t_assm *assm)
{
	char	*line;

	line = NULL;
	while (get_next_line(assm->fd_s, &line))
	{
		assm->counter_line++;
		working_instruction(assm, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void	working_operation(t_assm *assm, char *start, char *line)
{
	size_t	len;

	len = line - start;
	if (len == 3)
		three_char_operator(assm, start);
	else if (len == 4)
		four_char_operator(assm, start);
	else if (len == 2)
		two_char_operator(assm, start);
	else if (len == 5)
		five_char_operator(assm, start);
	else
		error("Unknown instruction.", assm);
}

void	instruction(t_assm *assm, char *line)
{
	char *start;

	start = line;
	while (*line)
	{
		if (*line == LABEL_CHAR)
		{
			working_lable(assm, start, line);
			return ;
		}
		if (*line == DIRECT_CHAR || *line == ' ' || *line == '\t')
		{
			working_operation(assm, start, line);
			return ;
		}
		line++;
	}
	error("Unknown instruction.", assm);
}

int		isprint_char(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

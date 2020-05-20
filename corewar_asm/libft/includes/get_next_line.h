/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:54:44 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/07 11:40:37 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct		s_line
{
	char			*str;
	int				fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);
int					reading(int fd, char **line, t_line **head);
void				get_tail(const int fd, char *buf, t_line **head);
int					len(char *s, int c);

#endif

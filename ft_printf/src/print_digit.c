/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:58:05 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 15:30:02 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define AN ob->flag.prec
#define WN ob->flag.weight
#define NEG (ob->flag.negativ || ob->flag.plus)
#define LENA (AN - ft_strlen(ob->out))
#define LENW (WN - ft_strlen(ob->out))

static	void	digit_next(t_ob *ob)
{
	if (ob->flag.plus)
		ob->out = ft_free_strjoin_rev(ob->flag.negativ ? "-" : "+", ob->out);
	else if (!ob->flag.plus && ob->flag.negativ)
		ob->out = ft_free_strjoin_rev("-", ob->out);
	if (LENW > 0)
		ob->out = ft_free_strjoin_duo(ft_memset(ft_strnew(LENW), ' ', LENW),
		ob->out);
}

void			print_digit(t_ob *ob)
{
	if (ob->flag.dot && !ft_atoi(ob->out))
	{
		free(ob->out);
		ob->out = ft_strdup("");
	}
	if (LENA > 0)
		ob->out = ft_free_strjoin_duo(ft_memset(ft_strnew(LENA), '0', LENA),
		ob->out);
	if (ob->flag.space && !NEG)
		ob->out = ft_free_strjoin_rev(" ", ob->out);
	if (ob->flag.zero && LENW > 0)
		ob->out = ft_free_strjoin_duo(ft_memset(ft_strnew(NEG ? LENW - 1
		: LENW), '0', NEG ? LENW - 1 : LENW), ob->out);
	if (ob->flag.minus && (NEG ? LENW - 1 > 0 : LENW > 0))
		ob->out = ft_free_strjoin_duo(ob->out, ft_memset(ft_strnew(NEG ?
		LENW - 1
			: LENW), ' ', NEG ? LENW - 1 : LENW));
	digit_next(ob);
	ob->i++;
	ob->ret += write(ob->fd, ob->out, ft_strlen(ob->out));
	free(ob->out);
}

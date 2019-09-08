/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choise_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojessi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 14:39:25 by ojessi            #+#    #+#             */
/*   Updated: 2019/06/02 14:39:29 by ojessi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	choise_specs_etc(const char *restrict fmt, t_ob *ob)
{
	if (ft_strchr(BOX, fmt[ob->i]))
		print_base(ob, fmt[ob->i]);
	else if (fmt[ob->i] == 'p' || fmt[ob->i] == 'P')
		print_pointer(ob);
	else if (fmt[ob->i] == 'r')
		print_non_printabl(ob);
	else if (fmt[ob->i] != '\0')
		print_invalid(ob, fmt[ob->i]);
}

void			choise_specs(const char *restrict fmt, t_ob *ob)
{
	if (fmt[ob->i] == '%')
		print_percent(ob);
	else if ((fmt[ob->i] == 's' || fmt[ob->i] == 'c') &&
		ob->type != type_l)
		fmt[ob->i] == 'c' ? print_char(ob) : print_str(ob);
	else if (((fmt[ob->i] == 's' || fmt[ob->i] == 'c') && ob->type == type_l)
		|| fmt[ob->i] == 'S' || fmt[ob->i] == 'C')
		fmt[ob->i] == 'c' || fmt[ob->i] == 'C' ? print_char(ob) : print_str(ob);
	else if ((fmt[ob->i] == 'd' || fmt[ob->i] == 'i' || fmt[ob->i] == 'D')
	&& ob->type != type_z)
		print_int(ob, fmt);
	else if (fmt[ob->i] == 'u' || fmt[ob->i] == 'U' ||
		((fmt[ob->i] == 'd' || fmt[ob->i] == 'i') && ob->type == type_z))
		print_unsint(ob, fmt[ob->i]);
	else if (fmt[ob->i] == 'f' || fmt[ob->i] == 'F')
		print_double(ob);
	else
		choise_specs_etc(fmt, ob);
}

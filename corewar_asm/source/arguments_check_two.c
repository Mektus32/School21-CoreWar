/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_or_xor_and_arg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 11:21:19 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/14 19:43:19 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	check_op_ld_lld_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 2)
		error("Error arguments instruction.", assm);
	if (opr->args[0].code_dir == 0 && opr->args[0].code_ind == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].code_reg == C_REG)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].code_reg == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[1].code_ind == C_IND || opr->args[1].code_dir == C_DIR)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_dir == C_DIR || opr->args[2].code_ind == C_IND ||
			opr->args[2].code_reg == C_REG)
		error("Error three arguments instruction.", assm);
}

void	check_op_st_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 2)
		error("Error arguments instruction.", assm);
	if (opr->args[0].code_reg == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].code_ind == C_IND || opr->args[0].code_dir == C_DIR)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].code_reg == 0 && opr->args[1].code_ind == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[1].code_dir == C_DIR)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_dir == C_DIR || opr->args[2].code_ind == C_IND ||
			opr->args[2].code_reg == C_REG)
		error("Error three arguments instruction.", assm);
}

void	check_op_or_xor_and_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 3)
		error("Error arguments instruction.", assm);
	if (opr->args[0].code_reg == 0 && opr->args[0].code_ind == 0 &&
			opr->args[0].code_dir == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].code_reg == 0 && opr->args[1].code_ind == 0 &&
			opr->args[1].code_dir == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_reg == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[2].code_dir == C_DIR || opr->args[2].code_ind == C_IND)
		error("Error three arguments instruction.", assm);
}

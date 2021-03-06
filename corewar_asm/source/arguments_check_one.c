/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op_st_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonnie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:25:11 by pdonnie           #+#    #+#             */
/*   Updated: 2020/03/15 20:08:33 by pdonnie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
** The function cheacks the arguments of 2 instruction: ldi, lldi.
*/

void	check_op_ldi_lldi_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 3)
		error("Error arguments instruction.", assm);
	if (opr->args[0].code_reg == 0 && opr->args[0].code_ind == 0 &&
			opr->args[0].code_dir == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].code_reg == 0 && opr->args[1].code_dir == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_reg == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[1].code_ind == C_IND)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_dir == C_DIR || opr->args[2].code_ind == C_IND)
		error("Error three arguments instruction.", assm);
}

/*
** The function cheacks the arguments of 4 instruction: fork, lfork, zjmp, live.
*/

void	check_op_fork_lfork_zjmp_live_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 1)
		error("Error arguments instruction.", assm);
	if (opr->args[0].code_dir == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].code_ind == C_IND || opr->args[0].code_reg == C_REG)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].code_ind == C_IND || opr->args[1].code_dir == C_DIR ||
			opr->args[1].code_reg == C_REG)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_dir == C_DIR || opr->args[2].code_ind == C_IND ||
			opr->args[2].code_reg == C_REG)
		error("Error three arguments instruction.", assm);
}

void	check_op_aff_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 1)
		error("Error arguments instruction.", assm);
	if (opr->args[0].code_reg == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].code_ind == C_IND || opr->args[0].code_dir == C_DIR)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].code_ind == C_IND || opr->args[1].code_dir == C_DIR ||
			opr->args[1].code_reg == C_REG)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_dir == C_DIR || opr->args[2].code_ind == C_IND ||
			opr->args[2].code_reg == C_REG)
		error("Error three arguments instruction.", assm);
}

void	check_op_add_sub_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 3)
		error("Error arguments instruction.", assm);
	if (opr->args[0].code_reg == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].code_ind == C_IND || opr->args[0].code_dir == C_DIR)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].code_reg == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[1].code_ind == C_IND || opr->args[1].code_dir == C_DIR)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_reg == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[2].code_ind == C_IND || opr->args[2].code_dir == C_DIR)
		error("Error three arguments instruction.", assm);
}

void	check_op_sti_arg(t_assm *assm, t_opr *opr)
{
	if (opr->count_args != 3)
		error("Error arguments instruction.", assm);
	if (opr->args[0].code_reg == 0)
		error("Error first arguments instruction.", assm);
	if (opr->args[0].code_ind == C_IND || opr->args[0].code_dir == C_DIR)
		error("Error first arguments instruction.", assm);
	if (opr->args[1].code_reg == 0 && opr->args[1].code_dir == 0 &&
			opr->args[1].code_ind == 0)
		error("Error second arguments instruction.", assm);
	if (opr->args[2].code_reg == 0 && opr->args[2].code_dir == 0)
		error("Error three arguments instruction.", assm);
	if (opr->args[2].code_ind == C_IND)
		error("Error three arguments instruction.", assm);
}

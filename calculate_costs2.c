/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:35:43 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/01 16:41:34 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	ft_calculate(t_stack *a, t_stack *b, t_num *num)
{
	t_moves	moves;

	moves = ft_intializemoves();
	moves = ft_calculatecosta(a, num, moves);
	moves = ft_calculatecostb(b, num, moves);
	moves = ft_calculatecosts(moves);
	moves.total = moves.ra + moves.rb + moves.rr
		+ moves.rra + moves.rrb + moves.rrr + 1;
	return (moves);
}

t_moves	ft_checkmoves(t_stack *a, t_stack *b)
{
	t_num	*num;
	t_moves	moves;
	t_moves	lastmoves;

	num = a->topnum;
	lastmoves = ft_calculate(a, b, num);
	while (num)
	{
		moves = ft_calculate(a, b, num);
		if (moves.total < lastmoves.total)
			lastmoves = moves;
		num = num->next;
	}
	return (lastmoves);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:05:59 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/01 16:23:27 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getrelativesize(t_stack *stack)
{
	int	size;

	size = 0;
	if (stack->size % 2 != 0)
		size = 1;
	return ((stack->size / 2) + size);
}

void	ft_debug_moves(t_moves moves, t_num *num)
{
	printf("num: %d", num->value);
	printf("ra: %d, rb: %d, rr: %d\n", moves.ra, moves.rb, moves.rr);
	printf("rra: %d, rrb: %d, rrr: %d\n", moves.rra, moves.rrb, moves.rrr);
	printf("Total: %d\n", moves.total);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:05:59 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/11 12:44:09 by fbanzo-s         ###   ########.fr       */
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

int	ft_sqrt(int num)
{
	double	x;
	double	epsilon;

	if (num < 0)
		return (-1);
	x = num;
	epsilon = 0.0001;
	while ((x * x - num) > epsilon || (num - x * x) > epsilon)
	{
		x = (x + num / x) / 2;
	}
	return ((int)x);
}

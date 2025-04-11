/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:08:18 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/11 17:24:09 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_executemoves2(t_stack *a, t_stack *b, t_moves moves)
{
	while (moves.ra > 0)
	{
		ft_rotate(a, 'a', 0);
		moves.ra--;
	}
	while (moves.rb > 0)
	{
		ft_rotate(b, 'b', 0);
		moves.rb--;
	}
	while (moves.rra > 0)
	{
		ft_reverserotate(a, 'a', 0);
		moves.rra--;
	}
	while (moves.rrb > 0)
	{
		ft_reverserotate(b, 'b', 0);
		moves.rrb--;
	}
	ft_push(a, b, 'b', 0);
}

void	ft_executemoves(t_stack *a, t_stack *b, t_moves moves)
{
	while (moves.rr > 0)
	{
		ft_rr(a, b, 0);
		moves.rr--;
	}
	while (moves.rrr > 0)
	{
		ft_rrr(a, b, 0);
		moves.rrr--;
	}
}

void	ft_sortb(t_stack *b)
{
	t_num	*topnum;

	topnum = ft_max(b);
	if (ft_getpos(topnum, b) > ft_getrelativesize(b) && b->size != 2)
		while (b->topnum != topnum)
			ft_reverserotate(b, 'b', 0);
	else
		while (b->topnum != topnum)
			ft_rotate(b, 'b', 0);
}

void	ft_sortall(t_stack *a, t_stack *b)
{
	t_moves	moves;
	int		original_size;
	int		i;

	if (!a || !b)
		return ;
	original_size = a->size;
	ft_push(a, b, 'b', 0);
	ft_push(a, b, 'b', 0);
	i = 0;
	while (i < original_size - 2)
	{
		moves = ft_checkmoves(a, b);
		ft_executemoves(a, b, moves);
		ft_executemoves2(a, b, moves);
		i++;
	}
	ft_sortb(b);
	original_size = b->size;
	i = 0;
	while (i < original_size)
	{
		ft_push(b, a, 'a', 0);
		i++;
	}
}

void	ft_sort(t_stack *a, t_stack *b)
{
	ft_sortindex(a);
	if (a->size == 2)
		ft_swap(a, 'a', 0);
	else if (a->size == 3)
		ft_sortthree(a);
	else if (a->size == 4)
		ft_sortfour(a, b);
	else if (a->size == 5)
		ft_sortfive(a, b);
	else
		ft_sortall(a, b);
}

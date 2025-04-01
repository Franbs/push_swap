/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:08:18 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/01 17:06:30 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_executemoves2(t_stack *a, t_stack *b, t_moves moves)
{
	while (moves.ra > 0)
	{
		ft_rotate(a, 'a');
		moves.ra--;
	}
	while (moves.rb > 0)
	{
		ft_rotate(b, 'b');
		moves.rb--;
	}
	while (moves.rra > 0)
	{
		ft_reverserotate(a, 'a');
		moves.rra--;
	}
	while (moves.rrb > 0)
	{
		ft_reverserotate(b, 'b');
		moves.rrb--;
	}
	ft_push(a, b, 'b');
}

void	ft_executemoves(t_stack *a, t_stack *b, t_moves moves)
{
	while (moves.rr > 0)
	{
		ft_rr(a, b);
		moves.rr--;
	}
	while (moves.rrr > 0)
	{
		ft_rrr(a, b);
		moves.rrr--;
	}
}

void	ft_sortb(t_stack *b)
{
	t_num	*topnum;

	topnum = ft_max(b);
	if (ft_getpos(topnum, b) > ft_getrelativesize(b) && b->size != 2)
		while (b->topnum != topnum)
			ft_reverserotate(b, 'b');
	else
		while (b->topnum != topnum)
			ft_rotate(b, 'b');
}

void	ft_sortall(t_stack *a, t_stack *b)
{
	t_moves	moves;
	int		original_size;
	int		i;

	if (!a || !b)
		return ;
	original_size = a->size;
	ft_push(a, b, 'b');
	ft_push(a, b, 'b');
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
		ft_push(b, a, 'a');
		i++;
	}
}

void	ft_sort(t_stack *a, t_stack *b)
{
	ft_sortindex(a);
	if (a->size == 2)
		ft_swap(a, 'a');
	else if (a->size == 3)
		ft_sortthree(a);
	else if (a->size == 4)
		ft_sortfour(a, b);
	else if (a->size == 5)
		ft_sortfive(a, b);
	else
		ft_sortall(a, b);
}

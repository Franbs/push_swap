/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 14:25:26 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/01 16:09:31 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	ft_intializemoves(void)
{
	t_moves	moves;

	moves.ra = 0;
	moves.rb = 0;
	moves.rr = 0;
	moves.rra = 0;
	moves.rrb = 0;
	moves.rrr = 0;
	moves.total = 0;
	return (moves);
}

t_moves	ft_calculatecosta(t_stack *a, t_num *num, t_moves moves)
{
	if (a->topnum == num)
		return (moves);
	if (ft_getpos(num, a) > ft_getrelativesize(a))
		moves.rra = a->size - ft_getpos(num, a) + 1;
	else
		moves.ra = ft_getpos(num, a) - 1;
	return (moves);
}

t_num	*ft_findtarget(t_stack *b, t_num *num)
{
	t_num	*current;
	t_num	*target;
	int		diff;
	int		mindiff;

	if (num->index > ft_max(b)->index || num->index < ft_min(b)->index)
		return (ft_max(b));
	current = b->topnum;
	target = ft_max(b);
	mindiff = INT_MAX;
	while (current)
	{
		if (current->value < num->value)
		{
			diff = num->index - current->index;
			if (diff < mindiff)
			{
				mindiff = diff;
				target = current;
			}
		}
		current = current->next;
	}
	return (target);
}

t_moves	ft_calculatecostb(t_stack *b, t_num *num, t_moves moves)
{
	t_num	*target;

	target = ft_findtarget(b, num);
	if (!target)
		return (moves);
	if (ft_getpos(target, b) > ft_getrelativesize(b) && b->size != 2)
		moves.rrb = b->size - ft_getpos(target, b) + 1;
	else
		moves.rb = ft_getpos(target, b) - 1;
	return (moves);
}

t_moves	ft_calculatecosts(t_moves moves)
{
	int	min_rr;
	int	min_rrr;

	if (moves.ra < moves.rb)
		min_rr = moves.ra;
	else
		min_rr = moves.rb;
	moves.rr = min_rr;
	moves.ra -= min_rr;
	moves.rb -= min_rr;
	if (moves.rra < moves.rrb)
		min_rrr = moves.rra;
	else
		min_rrr = moves.rrb;
	moves.rrr = min_rrr;
	moves.rra -= min_rrr;
	moves.rrb -= min_rrr;
	return (moves);
}

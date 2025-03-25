/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 13:34:21 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/25 17:39:49 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortindex(t_stack *stacka)
{
	t_num	*num1;
	t_num	*num2;
	int		index;

	num1 = stacka->topnum;
	while (num1)
	{
		index = 0;
		num2 = stacka->topnum;
		while (num2)
		{
			if (num1->value > num2->value)
				index++;
			num2 = num2->next;
		}
		num1->index = index;
		num1 = num1->next;
	}
}

int	ft_checksorted(t_stack *a)
{
	int		tmp;
	t_num	*node;

	node = a->topnum;
	while (node->next)
	{
		tmp = node->value;
		if (node->next != NULL && tmp > node->next->value)
			return (1);
		node = node->next;
	}
	return (0);
}

void	ft_sortthree(t_stack *stacka)
{
	if (stacka->topnum == ft_min(stacka))
	{
		ft_swap(stacka);
		ft_rotate(stacka);
	}
	else if (stacka->topnum == ft_max(stacka))
	{
		ft_rotate(stacka);
		if (ft_checksorted(stacka) == 1)
			ft_swap(stacka);
	}
	else
	{
		if (stacka->topnum->next == ft_min(stacka))
			ft_swap(stacka);
		else
			ft_reverserotate(stacka);
	}
}

void	ft_sortfour(t_stack *stacka, t_stack *stackb)
{
	t_num	*min;

	min = ft_min(stacka);
	if (ft_getpos(min, stacka) >= stacka->size / 2)
	{
		while (stacka->topnum != min)
			ft_reverserotate(stacka);
	}
	else
	{
		while (stacka->topnum != min)
			ft_rotate(stacka);
	}
	ft_push(stacka, stackb);
	ft_sortthree(stacka);
	ft_push(stackb, stacka);
}

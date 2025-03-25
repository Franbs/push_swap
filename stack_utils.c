/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:54:31 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/25 17:31:30 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*ft_getlastnum(t_stack *stack)
{
	t_num	*botnum;

	if (!stack || !stack->topnum)
		return (NULL);
	botnum = stack->topnum;
	while (botnum->next)
	{
		botnum = botnum->next;
	}
	return (botnum);
}

t_num	*ft_min(t_stack *stack)
{
	t_num	*num;
	t_num	*min;

	num = stack->topnum;
	min = num;
	while (num)
	{
		if (min->value >= num->value)
			min = num;
		num = num->next;
	}
	return (min);
}

t_num	*ft_max(t_stack *stack)
{
	t_num	*num;
	t_num	*max;

	num = stack->topnum;
	max = num;
	while (num)
	{
		if (max->value < num->value)
			max = num;
		num = num->next;
	}
	return (max);
}

int	ft_getpos(t_num *num, t_stack *stack)
{
	int		pos;
	t_num	*topnum;

	pos = 0;
	topnum = stack->topnum;
	while (topnum)
	{
		if (num == topnum)
			return (pos);
		pos++;
		topnum = topnum->next;
	}
	return (-1);
}

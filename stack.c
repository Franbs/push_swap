/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:08:48 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/17 15:18:37 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_createstack(void)
{
	t_stack	*newstack;

	newstack = (t_stack *)malloc(sizeof(t_stack));
	newstack->size = 0;
	newstack->topnum = NULL;
	return (newstack);
}

void	ft_pushtostack(t_stack *stack, int val)
{
	t_num	*newnode;
	t_num	*currenttop;

	newnode = ft_createnode(val);
	if (!newnode)
		return ;
	if (!stack->topnum)
		stack->topnum = newnode;
	else
	{
		currenttop = stack->topnum;
		while (currenttop->next)
			currenttop = currenttop->next;
		currenttop->next = newnode;
	}
	stack->size++;
}

void	ft_freestack(t_stack *stack)
{
	t_num	*topnode;
	t_num	*tmpnext;

	topnode = stack->topnum;
	while (topnode->next)
	{
		tmpnext = topnode->next;
		ft_freenode(topnode);
		topnode = tmpnext;
	}
	free(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:58:52 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/22 13:07:52 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	t_num	*firstnode;
	t_num	*secondnode;

	if (!stack || !stack->topnum || !stack->topnum->next)
		return ;
	firstnode = stack->topnum;
	secondnode = firstnode->next;
	firstnode->next = secondnode->next;
	secondnode->next = firstnode;
	stack->topnum = secondnode;
}

void	ft_rotate(t_stack *stack)
{
	t_num	*firstnode;
	t_num	*lastnode;

	if (!stack || !stack->topnum || !stack->topnum->next)
		return ;
	firstnode = stack->topnum;
	lastnode = ft_getlastnum(stack);
	stack->topnum = firstnode->next;
	firstnode->next = NULL;
	lastnode->next = firstnode;
}

void	ft_reverserotate(t_stack *stack)
{
	t_num	*botnum;
	t_num	*tmp;

	if (!stack || !stack->topnum || !stack->topnum->next)
		return ;

	botnum = stack->topnum;
	tmp = NULL;
	while (botnum->next)
	{
		tmp = botnum;
		botnum = botnum->next;
	}
	if (tmp)
		tmp->next = NULL;
	botnum->next = stack->topnum;
	stack->topnum = botnum;
}

void	ft_push(t_stack *stacktoget, t_stack *stacktopush)
{
	t_num	*nodetopush;

	if (!stacktoget || !stacktoget->topnum || !stacktopush)
		return ;

	nodetopush = stacktoget->topnum;
	stacktoget->topnum = nodetopush->next;
	nodetopush->next = stacktopush->topnum;
	stacktopush->topnum = nodetopush;
	stacktoget->size--;
	stacktopush->size++;
}

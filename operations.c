/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:58:52 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/11 17:35:12 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack, char name, int print)
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
	if (print == 0)
	{
		if (name == 'a')
			ft_putstr_fd("sa\n", 1);
		else if (name == 'b')
			ft_putstr_fd("sb\n", 1);
	}
}

void	ft_rotate(t_stack *stack, char name, int print)
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
	if (print == 0)
	{
		if (name == 'a')
			ft_putstr_fd("ra\n", 1);
		else if (name == 'b')
			ft_putstr_fd("rb\n", 1);
	}
}

void	ft_reverserotate(t_stack *stack, char name, int print)
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
	if (print == 0)
	{
		if (name == 'a')
			ft_putstr_fd("rra\n", 1);
		else if (name == 'b')
			ft_putstr_fd("rrb\n", 1);
	}
}

void	ft_push(t_stack *stacktoget, t_stack *stacktopush, char name, int print)
{
	t_num	*node_topush;

	if (!stacktoget || !stacktoget->topnum || !stacktopush)
		return ;
	node_topush = stacktoget->topnum;
	stacktoget->topnum = node_topush->next;
	node_topush->next = stacktopush->topnum;
	stacktopush->topnum = node_topush;
	stacktoget->size--;
	stacktopush->size++;
	if (print == 0)
	{
		if (name == 'a')
			ft_putstr_fd("pa\n", 1);
		else if (name == 'b')
			ft_putstr_fd("pb\n", 1);
	}
}

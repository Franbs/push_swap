/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:58:52 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/25 16:38:27 by fbanzo-s         ###   ########.fr       */
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
	ft_putstr_fd("s\n", 1);
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
	ft_putstr_fd("r\n", 1);
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
	ft_putstr_fd("rr\n", 1);
}

void	ft_push(t_stack *stack_toget, t_stack *stack_topush)
{
	t_num	*node_topush;

	if (!stack_toget || !stack_toget->topnum || !stack_topush)
		return ;
	node_topush = stack_toget->topnum;
	stack_toget->topnum = node_topush->next;
	node_topush->next = stack_topush->topnum;
	stack_topush->topnum = node_topush;
	stack_toget->size--;
	stack_topush->size++;
	ft_putstr_fd("p\n", 1);
}

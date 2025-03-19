/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:58:52 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/19 19:51:16 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stack)
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

void	ft_ra(t_stack *stack)
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

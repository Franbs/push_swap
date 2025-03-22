/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:34:24 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/22 14:11:38 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printparams(char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		ft_putstr_fd(av[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	ft_printstack(t_stack *stack)
{
	t_num	*topnode;

	topnode = stack->topnum;
	while (topnode)
	{
		ft_putnbr_fd(topnode->value, 1);
		ft_putchar_fd('\n', 1);
		topnode = topnode->next;
	}
}

void	ft_printstacks(t_stack *stacka, t_stack *stackb)
{
	ft_putstr_fd("stack A:\n", 1);
	ft_printstack(stacka);
	ft_putstr_fd("stack B:\n", 1);
	ft_printstack(stackb);
}

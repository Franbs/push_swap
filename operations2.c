/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:13:14 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/11 17:30:25 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack *stacka, t_stack *stackb, int print)
{
	ft_swap(stacka, '\0', 1);
	ft_swap(stackb, '\0', 1);
	if (print == 0)
		ft_putstr_fd("ss\n", 1);
}

void	ft_rr(t_stack *stacka, t_stack *stackb, int print)
{
	ft_rotate(stacka, '\0', 1);
	ft_rotate(stackb, '\0', 1);
	if (print == 0)
		ft_putstr_fd("rr\n", 1);
}

void	ft_rrr(t_stack *stacka, t_stack *stackb, int print)
{
	ft_reverserotate(stacka, '\0', 1);
	ft_reverserotate(stackb, '\0', 1);
	if (print == 0)
		ft_putstr_fd("rrr\n", 1);
}

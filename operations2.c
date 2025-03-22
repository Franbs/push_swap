/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:13:14 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/22 13:30:29 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack *stacka, t_stack *stackb)
{
	ft_swap(stacka);
	ft_swap(stackb);
}

void	ft_rr(t_stack *stacka, t_stack *stackb)
{
	ft_rotate(stacka);
	ft_rotate(stackb);
}

void	ft_rrr(t_stack *stacka, t_stack *stackb)
{
	ft_reverserotate(stacka);
	ft_reverserotate(stackb);
}

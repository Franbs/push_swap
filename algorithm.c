/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:08:18 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/25 15:46:25 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *a, t_stack *b)
{
	ft_sortindex(a);
	if (a->size == 2)
		ft_swap(a);
	else if (a->size == 3)
	{
		ft_sortthree(a);
	}
	else if (a->size == 4)
	{
		ft_sortfour(a, b);
	}
	ft_printstacks(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:08:18 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/26 14:20:58 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortall(t_stack *a, t_stack *b)
{
	t_num	*n;
	int		nmoves;

	ft_push(a, b, 'b');
	ft_push(a, b, 'b');
	n = a->topnum;
	if (ft_getpos(n, a) >= a->size / 2)
	{
		while (a->topnum != n)
			ft_reverserotate(a, 'a');
	}
	else
	{
		while (a->topnum != n)
			ft_rotate(a, 'a');
	}
	
}

void	ft_sort(t_stack *a, t_stack *b)
{
	ft_sortindex(a);
	if (a->size == 2)
		ft_swap(a, 'a');
	else if (a->size == 3)
		ft_sortthree(a);
	else if (a->size == 4)
		ft_sortfour(a, b);
	else if (a->size == 5)
		ft_sortfive(a, b);
	else
		ft_sortall(a, b);
	ft_printstacks(a, b);
}

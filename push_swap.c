/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:03:37 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/17 16:03:04 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		error;
	t_stack	*stacka;
	t_stack	*stackb;

	if (ac < 2)
		return (0);
	error = ft_checkstack(av);
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stacka = ft_createstack();
	stackb = ft_createstack();
	ft_fillstack(stacka, av);
	ft_printstack(stacka);
	ft_freestack(stacka);
	return (0);
}

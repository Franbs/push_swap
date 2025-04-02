/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:21:01 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/02 18:20:36 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isempty(t_stack *stack)
{
	if (stack->size > 0)
		return (1);
	else
		return (0);
}

int	main(int ac, char **av)
{
	int		error;
	t_stack	*stacka;
	t_stack	*stackb;
	char	**av2;

	if (ac < 2)
		return (0);
	av2 = ft_handleav(av, ac);
	error = ft_checkstack(av2);
	ft_error(error);
	stacka = ft_createstack();
	stackb = ft_createstack();
	ft_fillstack(stacka, av2);
	if (ft_checksorted(stacka) == 1)
		ft_sort(stacka, stackb);
	if (ft_checksorted(stacka) == 0 && ft_isempty(stackb) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free(ac, av2, stacka, stackb);
	return (0);
}

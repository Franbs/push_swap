/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:03:37 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/25 15:39:21 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_free(ac, av2, stacka, stackb);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:03 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/22 13:35:15 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int error)
{
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

char	**ft_handleav(char **av, int ac)
{
	char	**av2;

	if (ac == 2)
		av2 = ft_split(av[1], ' ');
	else
	{
		av++;
		av2 = av;
	}
	return (av2);
}

void	ft_freearray(char **av2)
{
	size_t	i;

	i = 0;
	while (av2[i])
	{
		free(av2[i]);
		i++;
	}
	free(av2);
}

void	ft_free(int ac, char **av2, t_stack *stacka, t_stack *stackb)
{
	if (ac == 2)
		ft_freearray(av2);
	ft_freestack(stacka);
	ft_freestack(stackb);
}

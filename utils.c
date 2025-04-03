/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:03 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/03 15:40:49 by fbanzo-s         ###   ########.fr       */
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
	int		i;

	if (ac == 2)
		av2 = ft_split(av[1], ' ');
	else
	{
		av++;
		av2 = av;
	}
	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 11)
			ft_error(1);
		i++;
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

int	ft_sqrt(int num)
{
	double	x;
	double	epsilon;

	if (num < 0)
		return (-1);
	x = num;
	epsilon = 0.0001;
	while ((x * x - num) > epsilon || (num - x * x) > epsilon)
	{
		x = (x + num / x) / 2;
	}
	return ((int)x);
}

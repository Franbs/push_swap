/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:03:37 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/16 22:20:51 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	error;
	size_t	i;

	if (ac < 2)
		return (0);
	i = 1;
	while (av[i])
	{
		ft_putstr_fd(av[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	error = ft_checkstack(av);
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	return (0);
}

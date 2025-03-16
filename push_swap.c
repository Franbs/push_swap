/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:03:37 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/16 15:29:56 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkstack(char **list)
{
	size_t	i;
	size_t	j;
	
	i = 1;
	while (list[i])
	{
		j = 0;
		while(list[i][j])
		{
			if (!ft_isdigit(list[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	error;

	if (ac < 2)
		return (0);
	error = ft_checkstack(av);
	ft_putnbr_fd(error, 1);
	return (0);
}

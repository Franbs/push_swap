/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 22:20:34 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/16 22:20:34 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checknum(char *num)
{
	if (num[0] == '+' || num[0] == '-')
		num++;
	if (!*num)
		return (1);
	while (*num)
	{
		if (!ft_isdigit(*num))
			return (1);
		num++;
	}
	return (0);
}

int	ft_checkdup(char **list)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (list[i])
	{
		j = i + 1;
		while (list[j])
		{
			if (ft_strncmp(list[i], list[j], 11) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_checkstack(char **list)
{
	size_t	i;

	i = 0;
	while (list[i])
	{
		if (ft_checknum(list[i]) == 1)
			return (1);
		i++;
	}
	if (ft_checkdup(list) == 1)
		return (1);
	return (0);
}

void	ft_fillstack(t_stack *stack, char **av)
{
	size_t	i;

	i = 0;
	while (av[i])
	{
		ft_pushtostack(stack, ft_atoi(av[i]));
		i++;
	}
}

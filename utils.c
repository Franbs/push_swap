/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:59:03 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/19 19:40:33 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_printparams(char **av)
{
	size_t	i;

	i = 1;
	while (av[i])
	{
		ft_putstr_fd(av[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}
*/
void	ft_printstack(t_stack *stack)
{
	t_num	*topnode;

	topnode = stack->topnum;
	while (topnode)
	{
		ft_putnbr_fd(topnode->value, 1);
		ft_putchar_fd('\n', 1);
		topnode = topnode->next;
	}
}

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

void	ft_free(int ac, char **av2, t_stack *stacka)
{
	if (ac == 2)
		ft_freearray(av2);
	ft_freestack(stacka);
}

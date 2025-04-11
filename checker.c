/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:21:01 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/11 22:17:33 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rmnewline(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			line[i] = '\0';
			return ;
		}
		i++;
	}
}

int	ft_execmoves(t_stack *a, t_stack *b, char *line)
{
	if (ft_strncmp(line, "sa", ft_strlen(line)) == 0)
		return (ft_swap(a, 'a', 1), 1);
	else if (ft_strncmp(line, "sb", ft_strlen(line)) == 0)
		return (ft_swap(b, 'b', 1), 1);
	else if (ft_strncmp(line, "pa", ft_strlen(line)) == 0)
		return (ft_push(b, a, 'a', 1), 1);
	else if (ft_strncmp(line, "pb", ft_strlen(line)) == 0)
		return (ft_push(a, b, 'b', 1), 1);
	else if (ft_strncmp(line, "ra", ft_strlen(line)) == 0)
		return (ft_rotate(a, 'a', 1), 1);
	else if (ft_strncmp(line, "rb", ft_strlen(line)) == 0)
		return (ft_rotate(b, 'b', 1), 1);
	else if (ft_strncmp(line, "rra", ft_strlen(line)) == 0)
		return (ft_reverserotate(a, 'a', 1), 1);
	else if (ft_strncmp(line, "rrb", ft_strlen(line)) == 0)
		return (ft_reverserotate(b, 'b', 1), 1);
	return (0);
}

int	ft_execmoves2(t_stack *a, t_stack *b, char *line)
{
	if (ft_strncmp(line, "rrr", ft_strlen(line)) == 0)
		return (ft_rrr(a, b, 1), 1);
	else if (ft_strncmp(line, "rr", ft_strlen(line)) == 0)
		return (ft_rr(a, b, 1), 1);
	else if (ft_strncmp(line, "ss", ft_strlen(line)) == 0)
		return (ft_ss(a, b, 1), 1);
	return (0);
}

void	ft_checkersort(t_stack *a, t_stack *b)
{
	char	*line;
	int		order;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		ft_rmnewline(line);
		if (!ft_execmoves(a, b, line) && !ft_execmoves2(a, b, line))
		{
			free(line);
			ft_error(1);
		}
		free(line);
	}
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
	ft_checkersort(stacka, stackb);
	if (ft_checksorted(stacka) == 0 && ft_isempty(stackb) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_free(ac, av2, stacka, stackb);
	return (0);
}

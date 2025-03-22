/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:03:46 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/22 14:11:19 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_num
{
	int				value;
	int				index;
	struct s_num	*next;
}	t_num;

typedef struct s_stack
{
	int		size;
	t_num	*topnum;
}	t_stack;

// parser.c
int		ft_checkstack(char **list);
void	ft_fillstack(t_stack *stack, char **av);

// utils.c
void	ft_error(int error);
char	**ft_handleav(char **av, int ac);
void	ft_free(int ac, char **av2, t_stack *stacka, t_stack *stackb);
void	ft_freearray(char **av2);

// print.c
void	ft_printparams(char **av);
void	ft_printstack(t_stack *stack);
void	ft_printstacks(t_stack *stacka, t_stack *stackb);

// node.c
t_num	*ft_createnode(int val);
void	ft_freenode(t_num *node);

// stack.c
t_stack	*ft_createstack(void);
void	ft_pushtostack(t_stack *stack, int val);
void	ft_freestack(t_stack *stack);
t_num	*ft_getlastnum(t_stack *stack);

// algorithm.c
void	ft_sort(t_stack *stacka, t_stack *stackb);

// operations.c
void	ft_swap(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_reverserotate(t_stack *stack);
void	ft_push(t_stack *stacktoget, t_stack *stacktopush);

// operations2.c
void	ft_ss(t_stack *stacka, t_stack *stackb);
void	ft_rr(t_stack *stacka, t_stack *stackb);
void	ft_rrr(t_stack *stacka, t_stack *stackb);

#endif
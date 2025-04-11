/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:03:46 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/04/11 12:44:29 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	total;
}	t_moves;

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
// utils2.c
int		ft_getrelativesize(t_stack *stack);
void	ft_debug_moves(t_moves moves, t_num *num);
int		ft_sqrt(int num);
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
// stack_utils.c
t_num	*ft_getlastnum(t_stack *stack);
t_num	*ft_min(t_stack *stack);
t_num	*ft_max(t_stack *stack);
int		ft_getpos(t_num *num, t_stack *stack);
t_num	*ft_getbyindex(t_stack *a, int index);
// utils_sorted.c
void	ft_sortindex(t_stack *stacka);
int		ft_checksorted(t_stack *a);
void	ft_sortthree(t_stack *stacka);
void	ft_sortfour(t_stack *stacka, t_stack *stackb);
void	ft_sortfive(t_stack *stacka, t_stack *stackb);
// algorithm.c
void	ft_sort(t_stack *stacka, t_stack *stackb);
// operations.c
void	ft_swap(t_stack *stack, char name);
void	ft_rotate(t_stack *stack, char name);
void	ft_reverserotate(t_stack *stack, char name);
void	ft_push(t_stack *stacktoget, t_stack *stacktopush, char name);
// operations2.c
void	ft_ss(t_stack *stacka, t_stack *stackb);
void	ft_rr(t_stack *stacka, t_stack *stackb);
void	ft_rrr(t_stack *stacka, t_stack *stackb);
// calculate_costs.c
t_moves	ft_calculatecosts(t_moves moves);
t_moves	ft_calculatecostb(t_stack *b, t_num *num, t_moves moves);
t_num	*ft_findtarget(t_stack *b, t_num *num);
t_moves	ft_calculatecosta(t_stack *a, t_num *num, t_moves moves);
t_moves	ft_intializemoves(void);
// calculate_costs.c
t_moves	ft_calculate(t_stack *a, t_stack *b, t_num *num);
t_moves	ft_checkmoves(t_stack *a, t_stack *b);

#endif
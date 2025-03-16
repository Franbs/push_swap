/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 14:03:46 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/16 14:58:01 by fbanzo-s         ###   ########.fr       */
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

#endif
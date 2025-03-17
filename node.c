/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:08:37 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/17 14:28:22 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_num	*ft_createnode(int val)
{
	t_num	*newnum;

	newnum = malloc(sizeof(t_num));
	if (!newnum)
		return (NULL);
	newnum->value = val;
	newnum->index = -1;
	newnum->next = NULL;
	return (newnum);
}

void	ft_freenode(t_num *node)
{
	if (node)
		free(node);
}

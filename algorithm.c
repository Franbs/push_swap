/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:08:18 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/26 16:10:46 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

void	ft_sortall(t_stack *a, t_stack *b) {
    int chunk_size;
    int range[2];
    int pushed;

    ft_sortindex(a); // Índices de 0 a N-1
    
    // 1. PUSH A -> B EN CHUNKS ORDENADOS
    chunk_size = (a->size <= 100) ? 20 : 45; // Chunks más pequeños = menos rotaciones
    for (int i = 0; i <= a->size / chunk_size; i++) {
        range[0] = i * chunk_size;
        range[1] = (i + 1) * chunk_size;
        pushed = 0;
        
        while (pushed < chunk_size && a->size > 0) {
            if (a->topnum->index >= range[0] && a->topnum->index < range[1]) {
                ft_push(a, b, 'b');
                if (b->topnum->index < range[0] + (chunk_size / 2)) // Optimización: rotar B si está en la mitad inferior del chunk
                    ft_rotate(b, 'b');
                pushed++;
            } else
                ft_rotate(a, 'a');
        }
    }

    // 2. PUSH B -> A EN ORDEN DESCENDENTE (siempre el mayor primero)
    while (b->size > 0) {
        t_num *max = ft_max(b);
        int pos = ft_getpos(max, b);
        
        if (pos < b->size / 2) {
            while (b->topnum != max)
                ft_rotate(b, 'b');
        } else {
            while (b->topnum != max)
                ft_reverserotate(b, 'b');
        }
        ft_push(b, a, 'a');
    }
}

void	ft_sort(t_stack *a, t_stack *b)
{
	ft_sortindex(a);
	if (a->size == 2)
		ft_swap(a, 'a');
	else if (a->size == 3)
		ft_sortthree(a);
	else if (a->size == 4)
		ft_sortfour(a, b);
	else if (a->size == 5)
		ft_sortfive(a, b);
	else
		ft_sortall(a, b);
	ft_printstacks(a, b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbanzo-s <fbanzo-s@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:08:18 by fbanzo-s          #+#    #+#             */
/*   Updated: 2025/03/29 19:12:21 by fbanzo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	ft_calculatecosta(t_stack *a, t_num *num)
{
	int	cost;

	if (a->topnum == num)
		return (0);
	if (ft_getpos(num, a) > a->size / 2)
		cost = a->size - ft_getpos(num, a) + 1;
	else
		cost = ft_getpos(num, a) - 1;
	return (cost);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	ft_calculatecostb(t_stack *b, t_num *num)
{
	int		cost;
	t_num	*min;
	t_num	*max;
	t_num	*prev;
	t_num	*tmp;

	cost = 1;
	max = ft_max(b);
	min = ft_min(b);
	if (num->index > max->index || num->index < min->index)
	{
		if (b->topnum == max)
			return (cost);
		if (ft_getpos(max, b) > b->size / 2)
			cost += b->size - ft_getpos(max, b) + 1;
	}
	else
	{
		prev = b->topnum;
		tmp = prev;
		while (prev)
		{
			if ((prev->value < num->value) && (ft_abs(prev->index - num->index) < ft_abs(tmp->index - num->index)))
				tmp = prev;
			prev = prev->next;
		}
		if (ft_getpos(tmp, b) > b->size / 2)
			cost += b->size - ft_getpos(tmp, b) + 1;
	}
	return (cost);
}

void	ft_sortall(t_stack *a, t_stack *b)
{
	int		cost;
	t_num	*num;

	ft_push(a, b, 'b');
	ft_push(a, b, 'b');
	//ft_printstacks(a, b);
	//ft_putnbr_fd(ft_getpos(ft_min(a), a), 1);
	cost = 0;
	num = a->topnum;
	while (num)
	{
		cost = ft_calculatecosta(a, num);
		cost += ft_calculatecostb(b, num);
		ft_putstr_fd("num: ", 1);
		ft_putnbr_fd(num->value, 1);
		ft_putstr_fd(" coste: ", 1);
		ft_putnbr_fd(cost, 1);
		ft_putstr_fd("\n", 1);
		num = num->next;
	}
}*/

int ft_abs(int num)
{
    if (num < 0)
        return -num;
    return num;
}

int ft_get_target_pos(t_stack *b, t_num *num)
{
    t_num *max;
    t_num *min;
    t_num *target;
    t_num *current;

    max = ft_max(b);
    min = ft_min(b);
    target = max;
    current = b->topnum;

    if (b->size == 0)
        return 0;
    if (num->index > max->index || num->index < min->index)
        return ft_getpos(max, b);

    target = current;
    while (current)
    {
        if ((current->index < num->index) && 
            (target->index < current->index || target->index > num->index))
            target = current;
        current = current->next;
    }
    return ft_getpos(target, b);
}

void ft_calculate_best_move(t_stack *a, t_stack *b, int *best_a, int *best_b)
{
    t_num *current;
    int pos_a;
    int min_cost;
    int cost_a;
    int cost_b;
    int pos_b;
    int total_cost;
    int moves;

    current = a->topnum;
    pos_a = 0;
    min_cost = INT_MAX;
    while (current)
    {
        pos_a++;
        if (pos_a <= a->size / 2)
            cost_a = pos_a - 1;
        else
            cost_a = a->size - pos_a + 1;
        
        pos_b = ft_get_target_pos(b, current);
        
        if (pos_b <= b->size / 2)
            cost_b = pos_b - 1;
        else
            cost_b = b->size - pos_b + 1;
        
        if ((pos_a <= a->size / 2) == (pos_b <= b->size / 2))
        {
            if (cost_a < cost_b)
                moves = cost_a;
            else
                moves = cost_b;
            total_cost = cost_a + cost_b - moves;
        }
        else
        {
            total_cost = cost_a + cost_b;
        }

        if (total_cost < min_cost)
        {
            min_cost = total_cost;
            *best_a = pos_a;
            *best_b = pos_b;
        }
        current = current->next;
    }
}

void ft_execute_moves(t_stack *a, t_stack *b, int best_a, int best_b)
{
    int ra_moves;
    int rra_moves;
    int rb_moves;
    int rrb_moves;

    if (best_a <= a->size / 2)
        ra_moves = best_a - 1;
    else
        ra_moves = 0;
    
    if (best_a > a->size / 2)
        rra_moves = a->size - best_a + 1;
    else
        rra_moves = 0;
    
    if (best_b <= b->size / 2)
        rb_moves = best_b - 1;
    else
        rb_moves = 0;
    
    if (best_b > b->size / 2)
        rrb_moves = b->size - best_b + 1;
    else
        rrb_moves = 0;

    while (ra_moves > 0 && rb_moves > 0)
    {
        ft_rr(a, b);
        ra_moves--;
        rb_moves--;
    }
    while (rra_moves > 0 && rrb_moves > 0)
    {
        ft_rrr(a, b);
        rra_moves--;
        rrb_moves--;
    }
    while (ra_moves > 0)
    {
        ft_rotate(a, 'a');
        ra_moves--;
    }
    while (rra_moves > 0)
    {
        ft_reverserotate(a, 'a');
        rra_moves--;
    }
    while (rb_moves > 0)
    {
        ft_rotate(b, 'b');
        rb_moves--;
    }
    while (rrb_moves > 0)
    {
        ft_reverserotate(b, 'b');
        rrb_moves--;
    }
    
    ft_push(a, b, 'b');
}

int ft_find_insert_pos(t_stack *a, t_num *num)
{
    t_num *current;
    t_num *prev;
    int pos;

    current = a->topnum;
    prev = ft_getlastnum(a);
    pos = 1;

    if (!a->topnum)
        return 1;

    while (current)
    {
        if (prev->index < num->index && num->index < current->index)
            return pos;
        prev = current;
        current = current->next;
        pos++;
    }
    if (num->index < a->topnum->index && num->index < ft_getlastnum(a)->index)
        return ft_getpos(ft_min(a), a);
    return ft_getpos(ft_max(a), a) + 1;
}

void ft_execute_push_back(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
    int ra_moves;
    int rra_moves;
    int rb_moves;
    int rrb_moves;

    if (pos_a <= a->size / 2)
        ra_moves = pos_a - 1;
    else
        ra_moves = 0;
    
    if (pos_a > a->size / 2)
        rra_moves = a->size - pos_a + 1;
    else
        rra_moves = 0;
    
    if (pos_b <= b->size / 2)
        rb_moves = pos_b - 1;
    else
        rb_moves = 0;
    
    if (pos_b > b->size / 2)
        rrb_moves = b->size - pos_b + 1;
    else
        rrb_moves = 0;

    while (ra_moves > 0 && rb_moves > 0)
    {
        ft_rr(a, b);
        ra_moves--;
        rb_moves--;
    }
    while (rra_moves > 0 && rrb_moves > 0)
    {
        ft_rrr(a, b);
        rra_moves--;
        rrb_moves--;
    }
    while (ra_moves > 0)
    {
        ft_rotate(a, 'a');
        ra_moves--;
    }
    while (rra_moves > 0)
    {
        ft_reverserotate(a, 'a');
        rra_moves--;
    }
    while (rb_moves > 0)
    {
        ft_rotate(b, 'b');
        rb_moves--;
    }
    while (rrb_moves > 0)
    {
        ft_reverserotate(b, 'b');
        rrb_moves--;
    }
    
    ft_push(b, a, 'a');
}

void ft_final_rotate(t_stack *a)
{
    t_num *min;
    int pos;

    min = ft_min(a);
    pos = ft_getpos(min, a);

    if (pos <= a->size / 2)
    {
        while (a->topnum != min)
        {
            ft_rotate(a, 'a');
        }
    }
    else
    {
        while (a->topnum != min)
        {
            ft_reverserotate(a, 'a');
        }
    }
}

void ft_sortall(t_stack *a, t_stack *b)
{
    int best_a;
    int best_b;
    t_num *current;
    t_num *best;
    int min_cost;
    int best_pos_a;
    int best_pos_b;
    int pos_b;
    int pos_a;
    int cost_a;
    int cost_b;
    int total_cost;

    while (a->size > 3)
    {
        ft_calculate_best_move(a, b, &best_a, &best_b);
        ft_execute_moves(a, b, best_a, best_b);
    }
    ft_sortthree(a);

    while (b->topnum)
    {
        current = b->topnum;
        best = current;
        min_cost = INT_MAX;
        best_pos_a = 0;
        best_pos_b = 0;
        pos_b = 0;

        while (current)
        {
            pos_b++;
            pos_a = ft_find_insert_pos(a, current);
            
            if (pos_a <= a->size / 2)
                cost_a = pos_a - 1;
            else
                cost_a = a->size - pos_a + 1;
            
            if (pos_b <= b->size / 2)
                cost_b = pos_b - 1;
            else
                cost_b = b->size - pos_b + 1;
            
            total_cost = cost_a + cost_b;

            if (total_cost < min_cost)
            {
                min_cost = total_cost;
                best = current;
                best_pos_a = pos_a;
                best_pos_b = pos_b;
            }
            current = current->next;
        }
        ft_execute_push_back(a, b, best_pos_a, best_pos_b);
    }
    ft_final_rotate(a);
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

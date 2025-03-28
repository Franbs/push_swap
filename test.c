
// Helper function to safely find rotation target
static int find_rotation_target(t_stack *s, int low, int high)
{
    t_num *current = s->topnum;
    int pos = 0;
    int best_pos = -1;
    int best_distance = INT_MAX;
    int iterations = 0;
    const int max_iterations = s->size * 2; // Prevent infinite searching

    while (current && iterations++ < max_iterations) {
        if (current->index >= low && current->index < high) {
            int distance = (pos <= s->size / 2) ? pos : s->size - pos;
            if (distance < best_distance) {
                best_distance = distance;
                best_pos = pos;
            }
        }
        current = current->next;
        pos++;
    }
    return best_pos;
}

// Improved push candidate selection
static t_num *select_push_candidate(t_stack *b)
{
    t_num *current = b->topnum;
    t_num *best = NULL;
    int best_index = -1;
    int pos = 0;

    while (current) {
        if (current->index > best_index) {
            best_index = current->index;
            best = current;
        }
        current = current->next;
        pos++;
    }
    return best;
}

void ft_sort_large(t_stack *a, t_stack *b)
{
    int chunk_size;
    int range[2];
    int op_count = 0;
    const int max_operations = a->size * 15; // Generous limit
    
    ft_sortindex(a);
    
    // Phase 1: Push to B in dynamic chunks
    chunk_size = (a->size <= 100) ? 20 : 35;
    for (int i = 0; a->size > 0 && op_count < max_operations; i++) {
        range[0] = i * chunk_size;
        range[1] = (i + 1) * chunk_size;
        int pushed_in_chunk = 0;
        int attempts = 0;
        const int max_attempts = a->size * 2;

        while (pushed_in_chunk < chunk_size && a->size > 0 && 
               op_count < max_operations && attempts++ < max_attempts) {
            
            if (a->topnum->index >= range[0] && a->topnum->index < range[1]) {
                ft_push(a, b, 'b');
                op_count++;
                pushed_in_chunk++;
                attempts = 0; // Reset attempts counter on successful push
                
                // Small optimization for B's order
                if (b->size > 1 && b->topnum->index < b->topnum->next->index) {
                    ft_swap(b, 'b');
                    op_count++;
                }
            } else {
                int rotations = find_rotation_target(a, range[0], range[1]);
                if (rotations == -1) {
                    break; // No more numbers in this range
                }
                
                if (rotations <= a->size / 2) {
                    while (rotations-- > 0 && op_count++ < max_operations) {
                        ft_rotate(a, 'a');
                    }
                } else {
                    rotations = a->size - rotations;
                    while (rotations-- > 0 && op_count++ < max_operations) {
                        ft_reverserotate(a, 'a');
                    }
                }
            }
        }
    }

    // Phase 2: Push back to A in order
    while (b->size > 0 && op_count < max_operations) {
        t_num *target = select_push_candidate(b);
        if (!target) break;
        
        int pos = ft_getpos(target, b);
        if (pos < b->size / 2) {
            while (b->topnum != target && op_count++ < max_operations) {
                ft_rotate(b, 'b');
            }
        } else {
            while (b->topnum != target && op_count++ < max_operations) {
                ft_reverserotate(b, 'b');
            }
        }
        ft_push(b, a, 'a');
        op_count++;
    }

    if (a->size > 0) {
        t_num *min = ft_min(a);
        int pos = ft_getpos(min, a);
        if (pos <= a->size / 2) {
            while (a->topnum != min && op_count++ < max_operations) {
                ft_rotate(a, 'a');
            }
        } else {
            while (a->topnum != min && op_count++ < max_operations) {
                ft_reverserotate(a, 'a');
            }
        }
    }

    if (op_count >= max_operations) {
        ft_putstr_fd("Error: Operation limit exceeded\n", 2);
    }
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

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

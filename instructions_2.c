/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:40:41 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/19 15:10:06 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, '\0');
	swap(stack_b, 'k');
	write(1, "ss\n", 3);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 0 || stack_b->size <= 0)
		return ;
	rotate(stack_a, stack_b, 'k');
	rotate(stack_b, stack_a, 'k');
	write(1, "rr\n", 3);
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a, stack_b, 'k');
	reverse_rotate(stack_b, stack_a, 'k');
	write(1, "rrr\n", 4);
}

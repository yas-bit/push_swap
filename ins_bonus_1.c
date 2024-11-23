/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins_bonus_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 07:11:13 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/19 22:45:53 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a_bonus(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 0)
		return ;
	push(stack_a, pop(stack_b));
}

void	push_to_b_bonus(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 0)
		return ;
	push(stack_b, pop(stack_a));
}

void	swap_bonus(t_stack *stack)
{
	int	temp[2];

	if (stack->size < 1)
		return ;
	temp[0] = pop(stack);
	temp[1] = pop(stack);
	push(stack, temp[0]);
	push(stack, temp[1]);
}

void	rotate_bonus(t_stack *stack_a, t_stack *stack_b)
{
	int	size_b;
	int	size_again;
	int	temp;
	int	i;

	size_b = stack_b->size;
	i = stack_a->size;
	temp = pop(stack_a);
	while (--i >= 0)
		push(stack_b, pop(stack_a));
	push(stack_a, temp);
	size_again = stack_b->size + 1;
	while (--size_again > size_b)
		push(stack_a, pop(stack_b));
}

void	reverse_rotate_bonus(t_stack *stack_a, t_stack *stack_b)
{
	int	size_b;
	int	size_again;
	int	temp;
	int	i;

	size_b = stack_b->size;
	i = stack_a->size;
	while (i >= 1)
	{
		push(stack_b, pop(stack_a));
		i--;
	}
	temp = pop(stack_a);
	size_again = stack_b->size + 1;
	while (--size_again > size_b)
		push(stack_a, pop(stack_b));
	push(stack_a, temp);
}

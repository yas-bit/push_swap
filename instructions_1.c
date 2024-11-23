/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 23:40:41 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/19 23:29:07 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, pop(stack_b));
	write(1, "pa\n", 3);
}

void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, pop(stack_a));
	write(1, "pb\n", 3);
}

void	swap(t_stack *stack, char flag)
{
	int	temp[2];

	if (stack->size < 1)
		return ;
	temp[0] = pop(stack);
	temp[1] = pop(stack);
	push(stack, temp[0]);
	push(stack, temp[1]);
	if (flag == 'a')
		write(1, "sa\n", 3);
	else if (flag == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_stack *stack_a, t_stack *stack_b, char flag)
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
	if (flag == 'a')
		write(1, "ra\n", 3);
	else if (flag == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack *stack_a, t_stack *stack_b, char flag)
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
	if (flag == 'a')
		write(1, "rra\n", 4);
	else if (flag == 'b')
		write(1, "rrb\n", 4);
}

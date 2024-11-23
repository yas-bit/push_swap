/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:38:39 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/22 15:15:23 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack_a, int min)
{
	int	i;

	i = 0;
	while (i <= stack_a->size)
	{
		if (stack_a->top[i] == min)
			break ;
		i++;
	}
	return (stack_a->size - i);
}

void	get_max_min(t_stack *stack, int	*i_max)
{
	int	max;

	if (stack->top[0] > stack->top[1])
	{
		max = stack->top[0];
		(*i_max) = 0;
	}
	else
	{
		max = stack->top[1];
		(*i_max) = 1;
	}
	if (stack->top[2] > max)
	{
		max = stack->top[2];
		(*i_max) = 2;
	}
}

void	case_3(t_stack *stack_a, t_stack *stack_b)
{
	int	i_max;

	get_max_min(stack_a, &i_max);
	if (i_max == 2)
		rotate(stack_a, stack_b, 'a');
	else if (i_max == 1)
		reverse_rotate(stack_a, stack_b, 'a');
	if (stack_a->top[2] > stack_a->top[1])
		swap(stack_a, 'a');
}

void	case_5(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	min;
	int	rrb;
	int	j;

	j = 2;
	i = 1;
	while (j--)
	{
		min = get_min(stack_a, i++);
		rrb = stack_a->size + 1 - min;
		if (min <= stack_a->size / 2)
		{
			while (min-- > 0)
				rotate(stack_a, stack_b, 'a');
		}
		else
		{
			while (rrb-- > 0)
				reverse_rotate(stack_a, stack_b, 'a');
		}
		push_to_b(stack_a, stack_b);
	}
	case_3(stack_a, stack_b);
	to_a(stack_a, stack_b);
}

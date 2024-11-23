/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:29:30 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/20 00:27:51 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_numbers(t_stack *stack_a)
{
	int	s;
	int	*pos;
	int	i;

	s = 0;
	pos = ft_calloc(stack_a->size + 1, sizeof(int));
	if (!pos)
		exit(EXIT_FAILURE);
	while (s <= stack_a->size)
	{
		i = s;
		while (i <= stack_a->size)
		{
			if (stack_a->top[s] >= stack_a->top[i])
				pos[s]++;
			else
				pos[i]++;
			i++;
		}
		s++;
	}
	free(stack_a->top);
	stack_a->top = pos;
}

int	get_max(t_stack *stack_a)
{
	int	i;
	int	result;

	i = 0;
	result = stack_a->size + 1;
	while (i <= stack_a->size)
	{
		if (stack_a->top[i] == result)
			break ;
		i++;
	}
	return (stack_a->size - i);
}

void	rotate_stack(t_stack *a, t_stack *b, int rb_rrb, int i)
{
	if (i)
	{
		while (rb_rrb > 0)
		{
			rotate(b, a, 'b');
			rb_rrb--;
		}
	}
	else
	{
		while (rb_rrb > 0)
		{
			reverse_rotate(b, a, 'b');
			rb_rrb--;
		}
	}
}

void	back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	max;
	int	rb;
	int	rrb;

	i = stack_b->size;
	while (i-- >= 0)
	{
		max = get_max(stack_b);
		if (max < 0)
			exit(1);
		rb = max;
		rrb = stack_b->size - max + 1;
		if (max != 0)
		{
			if (max <= stack_b->size / 2)
				rotate_stack(stack_a, stack_b, rb, 1);
			else
				rotate_stack(stack_a, stack_b, rrb, 0);
		}
		push_to_a(stack_a, stack_b);
	}
}

void	sort_stack(t_stack *stack_a, t_stack *stack_b, int range)
{
	int	range_beg;
	int	i;

	range_beg = 1;
	i = stack_a->size;
	while (i >= 0)
	{
		if (stack_a->top[i] >= range_beg && stack_a->top[i] < range + range_beg)
		{
			push_to_b(stack_a, stack_b);
			range_beg++;
			i--;
		}
		else if (stack_a->top[i] < range_beg)
		{
			push_to_b(stack_a, stack_b);
			rotate(stack_b, stack_a, 'b');
			range_beg++;
			i--;
		}
		else if (stack_a->top[i] > range)
			rotate(stack_a, stack_b, 'a');
	}
	back_to_a(stack_a, stack_b);
}

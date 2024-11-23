/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:58:02 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/20 00:29:34 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	my_free(char **mynums)
{
	int	i;

	i = 0;
	while (mynums[i])
	{
		free(mynums[i]);
		i++;
	}
	free(mynums);
}

void	sort_cases(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 1)
		swap(stack_a, 'a');
	else if (stack_a->size == 2)
		case_3(stack_a, stack_b);
	else if (stack_a->size == 4)
		case_5(stack_a, stack_b);
	else if (stack_a->size == 99)
		sort_stack(stack_a, stack_b, 14);
	else if (stack_a->size == 499)
		sort_stack(stack_a, stack_b, 36);
	else
		sort_stack(stack_a, stack_b, (stack_a->size * 100) / 14);
}

void	to_a(t_stack *stack_a, t_stack *stack_b)
{
	push_to_a(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}

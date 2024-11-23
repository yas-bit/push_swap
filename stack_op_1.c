/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:58:02 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/22 16:48:55 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, long num)
{
	stack->size++;
	stack->top[stack->size] = num;
}

int	pop(t_stack	*stack)
{	
	int	poped_num;

	poped_num = stack->top[stack->size];
	stack->size--;
	return (poped_num);
}

long	ft_new_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' && ft_isdigit(str[i + 1]))
		i++;
	else if (str[i] == '-' && ft_isdigit(str[i + 1]))
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (sign * res);
}

void	print_error(t_stack *stack_a)
{
	write(2, "Error\n", 6);
	free(stack_a->top);
	exit(0);
}

int	already_sorted(t_stack stack_a)
{
	int	i;

	i = stack_a.size;
	while (i > 0)
	{
		if (stack_a.top[i] > stack_a.top[i - 1])
			return (0);
		i--;
	}
	return (1);
}

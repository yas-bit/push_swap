/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 07:11:13 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/22 17:16:44 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_sorted(t_stack a, t_stack b)
{
	if (already_sorted(a) && b.size == -1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	print_error_bonus(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	free(a->top);
	free(b->top);
	exit(1);
}

void	checker(t_stack *stack_a, t_stack *stack_b, char *s)
{
	if (!ft_strncmp(s, "sa\n", 4))
		swap_bonus(stack_a);
	else if (!ft_strncmp(s, "sb\n", 4))
		swap_bonus(stack_b);
	else if (!ft_strncmp(s, "ss\n", 4))
		swap_both(stack_a, stack_b);
	else if (!ft_strncmp(s, "pa\n", 4))
		push_to_a_bonus(stack_a, stack_b);
	else if (!ft_strncmp(s, "pb\n", 4))
		push_to_b_bonus(stack_a, stack_b);
	else if (!ft_strncmp(s, "ra\n", 4))
		rotate_bonus(stack_a, stack_b);
	else if (!ft_strncmp(s, "rb\n", 4))
		rotate_bonus(stack_b, stack_a);
	else if (!ft_strncmp(s, "rr\n", 4))
		rotate_both(stack_a, stack_b);
	else if (!ft_strncmp(s, "rra\n", 5))
		reverse_rotate_bonus(stack_a, stack_b);
	else if (!ft_strncmp(s, "rrb\n", 5))
		reverse_rotate_bonus(stack_b, stack_a);
	else if (!ft_strncmp(s, "rrr\n", 5))
		reverse_rotate_both(stack_a, stack_b);
	else
		print_error_bonus(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	char		*s;

	if (argc < 2)
		return (0);
	stack_a.size = -1;
	stack_b.size = -1;
	check_args(argc - 1, argv, &stack_a);
	index_numbers(&stack_a);
	stack_b.top = malloc((stack_a.size + 1) * sizeof(int));
	if (stack_b.top == NULL)
		return (free(stack_a.top), 1);
	while (1)
	{
		s = get_next_line(0);
		if (s == NULL)
			break ;
		checker(&stack_a, &stack_b, s);
		free(s);
	}
	check_if_sorted(stack_a, stack_b);
	free(stack_a.top);
	free(stack_b.top);
}

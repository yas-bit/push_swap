/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:22:22 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/22 17:02:31 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			range;

	if (argc < 2)
		return (0);
	stack_a.size = -1;
	stack_b.size = -1;
	check_args(argc - 1, argv, &stack_a);
	index_numbers(&stack_a);
	if (already_sorted(stack_a))
		return (free(stack_a.top), 0);
	stack_b.top = malloc((stack_a.size + 1) * sizeof(int));
	if (stack_b.top == NULL)
		return (free(stack_a.top), 1);
	sort_cases(&stack_a, &stack_b);
	free(stack_a.top);
	free(stack_b.top);
	return (0);
}

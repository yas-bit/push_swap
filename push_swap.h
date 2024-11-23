/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:17:43 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/22 16:48:28 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "get_next_line.h"
# include <limits.h>

typedef struct s_stack
{
	int	size;
	int	*top;
}	t_stack;

//basic cases funcs//////////////////
void	case_2(t_stack *stack);
void	case_3(t_stack *stack_a, t_stack *stack_b);
void	case_5(t_stack *stack_a, t_stack *stack_b);
//functions ////////////////////////
void	check_args(int size, char **argv, t_stack *a);
//bonus ins ////////////////////////
void	push_to_a_bonus(t_stack *stack_a, t_stack *stack_b);
void	push_to_b_bonus(t_stack *stack_a, t_stack *stack_b);
void	swap_bonus(t_stack *stack);
void	rotate_bonus(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_bonus(t_stack *stack_a, t_stack *stack_b);
//instructions ////////////////////
void	push_to_a(t_stack *stack_a, t_stack *stack_b);
void	push_to_b(t_stack *stack_a, t_stack *stack_b);
void	swap(t_stack *stack, char flag);
void	rotate(t_stack *stack_a, t_stack *stack_b, char flag);
void	reverse_rotate(t_stack *stack_a, t_stack *stack_b, char flag);
void	swap_both(t_stack *stack_a, t_stack *stack_b);
void	rotate_both(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
//sort /////////////////////////////
void	index_numbers(t_stack *stack_a);
void	sort_stack(t_stack *stack_a, t_stack *stack_b, int range);
//stack_operations
void	push(t_stack *stack, long num);
int		pop(t_stack	*stack);
long	ft_new_atoi(const char *str);
void	print_error(t_stack *stack_a);
int		already_sorted(t_stack stack_a);
void	to_a(t_stack *stack_a, t_stack *stack_b);
void	my_free(char **mynums);
void	sort_cases(t_stack *stack_a, t_stack *stack_b);
#endif
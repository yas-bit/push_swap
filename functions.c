/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:35:27 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/22 16:36:57 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_if_duplicated(t_stack *a)
{
	int	i;
	int	j;

	i = a->size;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			if (a->top[j] == a->top[i])
				print_error(a);
			j--;
		}
		i--;
	}
}

int	check_if_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	if (ft_strlen(str + i) < 1 || (ft_strlen(str + i) > 10
			&& ft_atoi(str) > INT_MAX))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	num_words(char *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

void	args(char **argv, t_stack *a, int i)
{
	char	**mynums;
	int		size_arg;
	long	num;

	while (--i > 0)
	{
		mynums = ft_split(argv[i], ' ');
		if (*mynums[0] == '\0')
			print_error(a);
		size_arg = num_words(argv[i], ' ') - 1;
		while (mynums[size_arg] && size_arg >= 0)
		{
			num = ft_new_atoi(mynums[size_arg]);
			if (num > INT_MAX || num < INT_MIN
				|| !check_if_num(mynums[size_arg]))
				print_error(a);
			push(a, num);
			size_arg--;
		}
		my_free(mynums);
	}
}

void	check_args(int size, char **argv, t_stack *a)
{
	int		i;
	int		a_size;

	i = 1;
	a_size = 0;
	while (i <= size)
		a_size += num_words(argv[i++], ' ');
	a->top = malloc(a_size * sizeof(int));
	if (!a->top)
		return ;
	args(argv, a, i);
	check_if_duplicated(a);
}

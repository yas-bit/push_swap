/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:03:41 by yraiss            #+#    #+#             */
/*   Updated: 2022/12/06 12:11:06 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_nl(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*fill(char *new_line, char *line, int *i)
{
	while (line[(*i)] != '\n' && line[(*i)])
	{
		new_line[(*i)] = line[(*i)];
		(*i)++;
	}
	if (line[(*i)] == '\n')
		new_line[(*i)++] = '\n';
	new_line[(*i)] = 0;
	return (new_line);
}

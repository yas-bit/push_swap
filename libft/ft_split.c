/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 09:58:16 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/19 21:57:20 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordnum(char *s, char c);
static void	ft_fill(char **tables, char *s, char c);
static int	wordlen(char *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**tables;

	if (!s)
		return (0);
	tables = ft_calloc((ft_wordnum((char *)s, c) + 1), sizeof(char *));
	if (!tables)
		return (NULL);
	ft_fill(tables, (char *)s, c);
	return (tables);
}

static int	ft_wordnum(char *s, char c)
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

static void	ft_fill(char **tables, char *s, char c)
{
	int	i;
	int	welen;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			welen = wordlen(s, c);
			tables[i] = ft_calloc(welen + 1, sizeof(char));
			if (tables[i] == NULL)
				return ;
			ft_memmove(tables[i], s, welen);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
}

static int	wordlen(char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

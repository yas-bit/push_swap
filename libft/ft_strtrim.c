/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:49:21 by yraiss            #+#    #+#             */
/*   Updated: 2022/10/21 17:35:02 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search(char const *s1, char c)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*cpy(int lens1, int cntr1, const char *s1)
{
	int		c;
	char	*trimed;

	c = 0;
	trimed = (char *)ft_calloc(lens1 - cntr1 + 1, sizeof(char));
	if (!trimed)
		return (0);
	while (cntr1 < lens1)
	{
		trimed[c] = s1[cntr1];
		cntr1++;
		c++;
	}
	return (trimed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		cntr1;
	int		len_s1;
	char	*trimed;

	if (!s1 || !set)
		return (0);
	cntr1 = 0;
	len_s1 = ft_strlen(s1);
	while (search(set, s1[cntr1]))
		cntr1++;
	if (s1[cntr1] == '\0')
	{
		trimed = (char *)ft_calloc(1, sizeof(char));
		return (trimed);
	}
	while (search(set, s1[len_s1 - 1]))
		len_s1--;
	trimed = cpy(len_s1, cntr1, s1);
	return (trimed);
}

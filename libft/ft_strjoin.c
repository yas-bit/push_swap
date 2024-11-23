/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 18:51:09 by yraiss            #+#    #+#             */
/*   Updated: 2023/03/19 23:17:42 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	fill(char *newstr, const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*new_str;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	new_str = (char *)ft_calloc(s1len + s2len + 1, 1);
	if (!new_str)
		return (NULL);
	fill(new_str, s1, s2);
	free((void *)s1);
	free((void *)s2);
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:24:05 by yraiss            #+#    #+#             */
/*   Updated: 2022/10/21 17:29:37 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*subs;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start > ft_strlen(s))
		return (subs = (char *)ft_calloc(1, sizeof(char)));
	subs = (char *)ft_calloc((len + 1), sizeof(char));
	if (!subs)
		return (NULL);
	while (i != start && start != 0)
		i++;
	while (j < len)
	{
		subs[j] = s[i];
		i++;
		j++;
	}
	subs[j] = '\0';
	return (subs);
}

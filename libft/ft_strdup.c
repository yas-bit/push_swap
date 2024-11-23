/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 11:49:33 by yraiss            #+#    #+#             */
/*   Updated: 2022/10/21 15:30:08 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*cpy;

	i = 0;
	len = ft_strlen(s1);
	cpy = (char *)malloc(len + 1);
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = ((char *)s1)[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

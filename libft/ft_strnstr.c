/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:33:13 by yraiss            #+#    #+#             */
/*   Updated: 2022/10/21 15:51:01 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (tofind[0] == '\0')
		return ((char *)str);
	if ((int)len == -1)
		len = ft_strlen(str);
	while ((int)len > i && str[i])
	{
		j = 0;
		while ((tofind[j]) && (str[i + j] == tofind[j]) && (int)len > i + j)
			j++;
		if (j == (int)ft_strlen(tofind))
			return ((char *)str + i);
		i++;
	}
	return (0);
}

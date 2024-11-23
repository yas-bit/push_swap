/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 13:30:58 by yraiss            #+#    #+#             */
/*   Updated: 2022/10/08 11:31:12 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int ch, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (str);
	while (i < len)
	{
		((char *)str)[i] = (char)ch;
		i++;
	}
	return (str);
}

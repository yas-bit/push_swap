/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yraiss <yraiss@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 16:47:18 by yraiss            #+#    #+#             */
/*   Updated: 2022/10/21 17:42:53 by yraiss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numofdigits(long long num)
{
	int	i;

	i = 0;
	if (num <= 0)
	{
		num = -num;
		i++;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char	*fill(long long num, int numofdig, int negornot)
{
	char	*str;

	str = ft_calloc(numofdig + 1, sizeof(char));
	if (!str)
		return (0);
	if (negornot)
	{
		num = -num;
		str[0] = '-';
	}
	while (numofdig > negornot)
	{
		str[numofdig - 1] = num % 10 + '0';
		num = num / 10;
		numofdig--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			numofdig;
	char		*str;

	num = (long long) n;
	numofdig = numofdigits(num);
	if (n < 0)
		str = fill(num, numofdig, 1);
	else
		str = fill(num, numofdig, 0);
	return (str);
}

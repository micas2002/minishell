/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:40:48 by fialexan          #+#    #+#             */
/*   Updated: 2022/10/28 12:00:59 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	numsize(int n)
{
	if (-10 < n && n < 0)
		return (2);
	if (n < 0)
		return (2 + numsize(-(n / 10)));
	if (n > 9)
		return (1 + numsize(n / 10));
	return (1);
}

static void	num_to_char(char *str, int n, int index)
{
	if (index == -1)
		return ;
	if (n < 0)
	{
		str[0] = '-';
		str[index] = -(n % 10) + '0';
		if (n < -9)
			num_to_char(str, -(n / 10), index - 1);
		return ;
	}
	if (n > 9)
	{
		str[index] = n % 10 + '0';
		num_to_char(str, n / 10, index - 1);
		return ;
	}
	str[index] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = numsize(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	num_to_char(str, n, size - 1);
	str[size] = '\0';
	return (str);
}

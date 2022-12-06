/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:48:14 by fialexan          #+#    #+#             */
/*   Updated: 2022/10/28 12:00:59 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	format_u(va_list args)
{
	unsigned int	num;
	int				arg;

	arg = va_arg(args, int);
	if (arg < 0)
		num = 4294967296 + arg;
	else
		num = arg;
	ft_uitoa(num);
	arg = ft_get_int_size(num);
	return (arg);
}

int	ft_get_int_size(unsigned int num)
{
	int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

int	ft_uitoa(unsigned int num)
{
	if (num > 9)
		ft_uitoa(num / 10);
	ft_putchar_fd(num % 10 + '0', 1);
	return (1);
}

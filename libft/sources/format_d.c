/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:44:22 by fialexan          #+#    #+#             */
/*   Updated: 2022/10/28 12:00:59 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	format_d(va_list args)
{
	char	*num;
	int		n;

	n = va_arg(args, int);
	num = ft_itoa(n);
	ft_putstr_fd(num, 1);
	n = ft_strlen(num);
	free(num);
	return (n);
}

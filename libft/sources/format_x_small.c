/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:10:59 by fialexan          #+#    #+#             */
/*   Updated: 2022/10/28 12:00:59 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	format_x_small(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_convert_hex((unsigned long)num, 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:47:17 by filipe            #+#    #+#             */
/*   Updated: 2022/10/28 12:00:58 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	format_x_big(va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	return (ft_convert_hex((unsigned long)num, 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:04:26 by mibernar          #+#    #+#             */
/*   Updated: 2023/04/01 13:58:04 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_token_chars(char *arg)
{
	int	x;

	x = 0;
	if (arg[x] == '=')
		return (0);
	while (arg[x] != '\0' && arg[x] != '=')
	{
		if (ft_isalnum(arg[x]) == 0)
			return (0);
		x++;
	}
	if (arg[x] == '\0')
		return (0);
	return (1);
}

int	get_var_size(char *arg)
{
	int	len;

	len = 0;
	while (arg[len] && arg[len] != '=')
		len++;
	return (len);
}

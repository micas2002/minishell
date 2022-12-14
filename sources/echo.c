/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:10 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/14 18:08:36 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_sh *sh, int i)
{
	int	x;

	x = i + 1;
	if (ft_strcmp(sh->tokens[++i], "-n") == 1)
		i++;
	while (sh->tokens[i] && ft_strcmp(sh->tokens[i], "|") == 0)
		printf("%s", sh->tokens[i++]);
	if (ft_strcmp(sh->tokens[x], "-n") == 1)
		return ;
	printf("\n");
}

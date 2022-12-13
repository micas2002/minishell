/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:10 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/13 11:56:43 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(t_sh *sh, int i)
{
	while (sh->tokens[++i] && ft_strcmp(sh->tokens[i], "|") == 0)
		printf("%s ", sh->tokens[i]);
	printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:14 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/16 13:21:47 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_program(t_sh *sh, int i)
{
	char	**input;
	int		x;
	int		y;

	x = i;
	while (sh->tokens[i] && ft_strcmp(sh->tokens[i], "|") == 0)
		i++;
	input = malloc(sizeof(char *) * i - x);
	y = -1;
	while (x != i)
	{
		input[++y] = malloc(sizeof(char) * ft_strlen(sh->tokens[x]));
		input[y] = sh->tokens[++x];
	}
	input[++y] = NULL;
//	execve(ft_substr(sh->tokens[i], 1, ft_strlen(sh->tokens[i] - 1)), args,);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:14 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/15 17:06:37 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_program(t_sh *sh, int i)
{
	int		x;
	int		y;
	int		z;
	char	**args;

	x = i;
	while (sh->tokens[++x] && ft_strcmp(sh->tokens[x], "|") == 0)
		;
	i++;
	args = malloc(sizeof(char *) * x - i + 1);
	y = -1;
	while (i != x)
		args[++y] = sh->tokens[i++];
	z = -1;
	while (args[++z])
		printf("%s", args[z]);
//	execve(ft_substr(sh->tokens[i], 1, ft_strlen(sh->tokens[i] - 1)), args,);
}

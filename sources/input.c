/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/13 15:54:46 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft.h"

void	commands(t_sh *sh, int i)
{
	if (ft_strcmp(sh->tokens[i], "echo") == 1)
		echo(sh, i);
	else if (ft_strcmp(sh->tokens[i], "cd") == 1)
		cd(sh, i);
	else if (ft_strcmp(sh->tokens[i], "pwd") == 1)
		pwd(sh);
	else if (ft_strcmp(sh->tokens[i], "export") == 1)
		printf("command foud\n");
	else if (ft_strcmp(sh->tokens[i], "unset") == 1)
		printf("command foud\n");
	else if (ft_strcmp(sh->tokens[i], "env") == 1)
		printf("command foud\n");
	else if (ft_strcmp(sh->tokens[i], "exit") == 1)
		printf("command foud\n");
	else
		printf("command not found\n");
}

void	parser(char *str, t_sh *sh)
{
	int	i = -1;

	lexer(str, sh);
	//while (sh->tokens[++i])
	//	printf("token:%s\n", sh->tokens[i]);
	i = -1;
	while (sh->tokens[++i])
	{
		if (i == 0 || sh->tokens[i - 1][ft_strlen(sh->tokens[i - 1]) - 1] == '|')
			commands(sh, i);
	}
}

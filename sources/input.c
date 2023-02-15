/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/15 16:11:28 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft.h"

//Checks if command is valid. If yes, gives paramaters to the respetcitve
//function and executes the command funciton. If not found, prints a message
void	commands(t_sh *sh, int i, char **env)
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
	else if (ft_strcmp(sh->tokens[i], "exit") == 1 && i == 0)
		exit (0);
	else if (sh->tokens[i][0] == '.' && sh->tokens[i][1] == '/')
		execute_program(sh, i, env);
	else
		printf("command not found\n");
}

//Parser that devides the input into tokens using lexer and then check if the
//command given is valid or not. If valid, calls command function
void	parser(char *str, t_sh *sh, char **env)
{
	int	i;

	lexer(str, sh, env);
	//i = -1;
	//printf("%d\n", sh->nb_tokens);
	//while (sh->tokens[++i])
	//	printf("token:%s", sh->tokens[i]);
	i = -1;
	while (sh->tokens[++i])
	{
		if (i == 0 || sh->tokens[i - 1][ft_strlen(sh->tokens[i - 1]) - 1] == '|')
			commands(sh, i, env);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/15 18:21:20 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft.h"

//Checks if command is valid. If yes, gives paramaters to the respetcitve
//function and executes the command funciton. If not found, prints a message
void	commands(t_shell *shell, int i, char **env)
{
	if (ft_strcmp(shell->tokens[i], "echo") == 1)
		echo(shell, i);
	else if (ft_strcmp(shell->tokens[i], "cd") == 1)
		cd(shell, i);
	else if (ft_strcmp(shell->tokens[i], "pwd") == 1)
		pwd(shell);
	else if (ft_strcmp(shell->tokens[i], "export") == 1)
		printf("command foud\n");
	else if (ft_strcmp(shell->tokens[i], "unset") == 1)
		printf("command foud\n");
	else if (ft_strcmp(shell->tokens[i], "env") == 1)
		enviroment(env);
	else if (ft_strcmp(shell->tokens[i], "exit") == 1 && i == 0)
		exit (0);
	else if (shell->tokens[i][0] == '.' && shell->tokens[i][1] == '/')
		execute_program(shell, i, env);
	else
		printf("command not found\n");
}

//Parser that devides the input into tokens using lexer and then check if the
//command given is valid or not. If valid, calls command function
void	parser(char *str, t_shell *shell, char **env)
{
	int	i;

	lexer(str, shell, env);
	//i = -1;
	//printf("%d\n", shell->nb_tokens);
	//while (shell->tokens[++i])
	//	printf("token:%s", shell->tokens[i]);
	i = -1;
	while (shell->tokens[++i])
	{
		if (i == 0 || shell->tokens[i - 1][ft_strlen(shell->tokens[i - 1]) - 1] == '|')
			commands(shell, i, env);
	}
}

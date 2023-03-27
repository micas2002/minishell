/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexn <fialexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/15 16:16:31 by fialexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft.h"

//Checks if command is valid. If yes, gives paramaters to the respetcitve
//function and executes the command funciton. If not found, prints a message
void	commands(t_shell *shell, int i)
{
	if (ft_strcmp(shell->tokens[i]->args[0], "echo") == 0)
		echo(shell->tokens[i]);
	else if (ft_strcmp(shell->tokens[i]->args[0], "cd") == 0)
		cd(shell->tokens[i]);
	else if (ft_strcmp(shell->tokens[i]->args[0], "pwd") == 0)
		pwd();
	else if (ft_strcmp(shell->tokens[i]->args[i], "export") == 0)
		export(shell, shell->tokens[i], 0, 0);
	else if (ft_strcmp(shell->tokens[i]->args[0], "unset") == 0)
		unset(shell, shell->tokens[i], 1);
	else if (ft_strcmp(shell->tokens[i]->args[0], "env") == 0)
		enviroment(shell);
	else if (ft_strcmp(shell->tokens[i]->args[0], "exit") == 0 && i == 0)
		exit (0);
	else if (ft_strcmp(shell->tokens[i]->args[0], "$?") == 0 && i != 0)
		exit_status();
	else
		execute_program(shell, i);
}

//Parser that devides the input into tokens using lexer and then check if the
//command given is valid or not. If valid, calls command function
void	parser(char *str, t_shell *shell)
{
	char	**cmds;
	int		pid;

	cmds = ft_split(str, '|');
	shell->nb_tokens = get_array_size(cmds);
	shell->tokens = divide_tokens(cmds);
	if (g_exit_value == EXIT_FAILURE)
	{
		free_double_array(cmds);
		g_exit_value = error_handler(ERR_UNCLOSED_QUOTES, 0, "");
		return ;
	}
	shell->tokens = handle_dollar(shell, shell->tokens);
	free_double_array(cmds);
	(void)pid;
	// if (check_redirections(shell->tokens[0]) != 0)
	// {
	// 	pid = fork();
	// 	// if (pid == 0)
	// 	// 	handle_redirections(shell);
	// 	waitpid(pid, &g_exit_value, 0);
	// }
	// else
		commands(shell, 0);
	free_tokens(shell);
}

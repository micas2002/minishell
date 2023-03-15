/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/15 15:13:26 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft.h"

//Checks if command is valid. If yes, gives paramaters to the respetcitve
//function and executes the command funciton. If not found, prints a message
void	commands(t_shell *shell, int i)
{
	if (ft_strcmp(shell->tokens[i]->program_name, "echo") == 0)
		echo(shell, i, 0);
	else if (ft_strcmp(shell->tokens[i]->program_name, "cd") == 0)
		cd(shell, i, 0);
	else if (ft_strcmp(shell->tokens[i]->program_name, "pwd") == 0)
		pwd(shell);
	else if (ft_strcmp(shell->tokens[i]->program_name, "export") == 0)
		export(shell, i, 0);
	else if (ft_strcmp(shell->tokens[i]->program_name, "unset") == 0)
		unset(shell, i, 0);
	else if (ft_strcmp(shell->tokens[i]->program_name, "env") == 0)
		enviroment(shell);
	else if (ft_strcmp(shell->tokens[i]->program_name, "exit") == 0 && i == 0)
		exit (0);
	// else if (ft_strcmp(shell->tokens[i]->program_name, "$?") == 0 && i != 0)
	// 	exit_status();
	// else
	// 	execute_program(shell, i, shell->env);
}

//Parser that devides the input into tokens using lexer and then check if the
//command given is valid or not. If valid, calls command function

int	parser(char *input, t_shell *shell)
{
	char	**commands;

	if (quote_checker(input) == 0)
		return (error_handler(ERR_UNCLOSED_QUOTES, 1));
	commands = ft_split(input, '|');
	shell->num_tokens = get_double_array_size(commands);
	shell->tokens = divide_tokens(&commands);
	return (0);
}

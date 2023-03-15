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
	if (ft_strcmp(shell->tokens[i], "echo") == 0)
		echo(shell, i);
	else if (ft_strcmp(shell->tokens[i], "cd") == 0)
		cd(shell, i);
	else if (ft_strcmp(shell->tokens[i], "pwd") == 0)
		pwd(shell);
	else if (ft_strcmp(shell->tokens[i], "export") == 0)
		export(shell, i);
	else if (ft_strcmp(shell->tokens[i], "unset") == 0)
		unset(shell, i);
	else if (ft_strcmp(shell->tokens[i], "env") == 0)
		enviroment(shell);
	else if (ft_strcmp(shell->tokens[i], "exit") == 0 && i == 0)
		exit (0);
	else if (ft_strcmp(shell->tokens[i], "$?") == 0 && i != 0)
		exit_status();
	else
		execute_program(shell, i, shell->env);
}

//Parser that devides the input into tokens using lexer and then check if the
//command given is valid or not. If valid, calls command function
void	parser(char *str, t_shell *shell)
{
	int		i;
	char	**cmds;
	
	cmds = ft_split(str, '|');
	shell->nb_tokens = get_size_of_array(cmds);
	shell->tokens = divide_tokens(cmds);
	free_double_array(cmds);
	if (shell->nb_tokens != 1)
	{
	}
	else if (shell->nb_tokens == 1/*check redirections*/)
	{
	}
	else
		commands(shell->tokens[0], 0);

}

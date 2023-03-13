/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/13 15:32:11 by fialexan         ###   ########.fr       */
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

void	parser(char *input, t_shell *shell)
{
	char	**commands;

	commands = divide_in_tokens(input);
	shell->tokens = divide_tokens(commands);
}

char	**divide_in_tokens(char *input)
{
	return (ft_split(input, '|'));
}

t_token	*divide_tokens(char **array)
{
	int		iter;
	t_token	*tokens;

	iter = 0;
	while (array[iter] != NULL)
		iter++;
	tokens = malloc(sizeof(t_token) * (iter + 1));
	iter = 0;
	while (array[iter] != NULL)
	{
		tokens[iter] = create_token(array[iter]);
		iter++;
	}
}

t_token	create_token(char *str)
{
	int	redir_count;
	int	iter;

	redir_count = 0;
	iter = 0;
	while (str[iter])
	{		
	}
}

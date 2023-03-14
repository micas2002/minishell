/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/14 16:19:14 by mibernar         ###   ########.fr       */
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
	shell->tokens = divide_tokens(&commands);
	return (0);
}

t_token	*create_token(char **str)
{
	t_token	*token;
	int		iter;
	int		command;

	token = get_redirection(str, 0, -1);
	iter = 0;
	command = 0;
	while (str[iter] != NULL)
		iter++;
	token->arguments = malloc(sizeof(char *)
			* (iter - (token->num_files * 2) + 1));
	iter = 0;
	while (str[iter] != NULL)
	{
		if (is_redir(str[iter]) == 1 && str[iter + 1] != NULL)
			iter += 2;
		else if (is_redir(str[iter]) == 1 && str[iter + 1] == NULL)
			return (NULL);
		else
		{
			if (command == 0)
				token->program_name = ft_strdup(str[iter]);
			token->arguments[command] = ft_strdup(str[iter]);
			command++;
			iter++;
		}
	}
	return (token);
}

t_token	*get_redirection(char **str, int count, int iter)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	while (str[++iter] != NULL)
	{
		if (is_redir(str[iter]) == 1)
			count++;
	}
	token->redirections = malloc(sizeof(char *) * (count + 1));
	token->files = malloc(sizeof(char *) * (count + 1));
	token->num_redirections = count;
	token->num_files = count;
	count = 0;
	iter = -1;
	while (str[++iter] != NULL)
	{
		if (is_redir(str[iter]) == 1)
		{
			token->redirections[count] = str[iter];
			token->files[count] = str[iter + 1];
			count++;
		}
	}
	token->redirections[count] = NULL;
	token->files[count] = NULL;
	return (token);
}

t_token	**divide_tokens(char ***array)
{
	int		iter;
	t_token	**tokens;

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
	tokens[iter] = NULL;
	return (tokens);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:20:51 by filipe            #+#    #+#             */
/*   Updated: 2023/03/27 21:57:30 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirections(t_shell *shell, int i)
{
	int		fd;
	t_token	*token;

	token = shell->tokens[i];
	if (check_redirections(token) == 1)
	{
		fd = handle_output_redirections(token);
		dup2(fd, STDIN_FILENO);
	}
	if (check_redirections(token) == 2)
	{
		fd = handle_input_redirections(token, -1, 0);
		dup2(fd, STDOUT_FILENO);
	}
	shell->tokens[i] = clean_redirections(token);
	commands(shell, i);
	exit(EXIT_SUCCESS);
}

int	handle_output_redirections(t_token *token)
{
	int	fd;
	int	iter;

	iter = 0;
	while (token->args[iter] != NULL)
	{
		if (ft_strcmp(token->args[iter], ">") == 0)
		{
			if (token->args[iter + 1] == NULL)
				exit(error_handler(ERR_SYNTAX, EXIT_FAILURE, ""));
			fd = open(token->args[iter + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
		}
		else if (ft_strcmp(token->args[iter], ">>") == 0)
		{
			if (token->args[iter + 1] == NULL)
				exit(error_handler(ERR_SYNTAX, EXIT_FAILURE, ""));
			fd = open(token->args[iter + 1], O_RDWR | O_CREAT | O_APPEND, 0666);
		}
		iter++;
	}
	return (fd);
}

int	handle_input_redirections(t_token *token, int iter, int error)
{
	int	fd;

	while (token->args[++iter] != NULL)
	{
		if (ft_strcmp(token->args[iter], "<") == 0)
		{
			if (token->args[iter + 1] == NULL)
				exit(error_handler(ERR_SYNTAX, EXIT_FAILURE, ""));
			fd = open(token->args[iter + 1], O_RDONLY);
			if (fd == -1 && error == 0)
				error = iter + 1;
		}
		else if (ft_strcmp(token->args[iter], "<<") == 0)
		{
			if (token->args[iter + 1] == NULL)
				exit(error_handler(ERR_SYNTAX, EXIT_FAILURE, ""));
			fd = here_doc(token->args[iter + 1]);
			if (fd == -1 && error == 0)
				error = iter + 1;
		}
	}
	if (error != 0)
		exit(error_handler(ERR_NO_SUCH_FILE_OR_DIR, EXIT_FAILURE,
				token->args[error]));
	return (fd);
}

int	here_doc(char *delim)
{
	char	*line;
	char	*promt;
	int		fd;

	fd = open(".tmp.txt", O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (fd == -1)
		return (fd);
	promt = ft_strjoin(delim, "> ");
	line = readline(promt);
	while (1)
	{
		if (ft_strncmp(line, delim, ft_strlen(line) - 1) == 0
			&& ft_strlen(line) > 1)
			break ;
		ft_putstr_fd(line, fd);
		free(line);
		line = readline(promt);
	}
	free(promt);
	free(line);
	return (fd);
}

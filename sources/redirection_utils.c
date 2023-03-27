/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:02:47 by filipe            #+#    #+#             */
/*   Updated: 2023/03/27 17:35:56 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirections(t_token *token)
{
	int	iter;

	iter = 0;
	while (token->args[iter])
	{
		if (ft_strcmp(token->args[iter], ">") == 0
			|| ft_strcmp(token->args[iter], ">>") == 0)
			return (1);
		else if (ft_strcmp(token->args[iter], "<") == 0
			|| ft_strcmp(token->args[iter], "<<") == 0)
			return (2);
		iter++;
	}
	return (0);
}

int	input_redirection(char *redirection, char *filename, int num_redirection)
{
	int	fd;

	if (ft_strcmp(redirection, "<") == 0)
	{
		fd = open(filename, O_RDONLY);
		if (fd == -1)
			exit(error_handler(ERR_NO_SUCH_FILE_OR_DIR,
					EXIT_FAILURE, filename));
	}
	else
	{
		fd = here_doc(filename);
		if (fd == -1)
			exit(error_handler(ERR_NO_SUCH_FILE_OR_DIR,
					EXIT_FAILURE, filename));
	}
	if (num_redirection == 0)
		return (fd);
	return (-1);
}

t_token	*clean_redirections(t_token *token)
{
	int		iter;
	int		count;
	t_token	*new_token;

	iter = 0;
	count = 0;
	while (token->args[iter] != NULL)
	{
		if (ft_strcmp(token->args[iter], ">") == 0
			|| ft_strcmp(token->args[iter], ">>") == 0
			|| ft_strcmp(token->args[iter], "<") == 0
			|| ft_strcmp(token->args[iter], "<<") == 0)
			count += 2;
		iter++;
	}
	new_token = malloc(sizeof(t_token));
	new_token->args = malloc(sizeof(char *) * (iter - count + 1));
	new_token = clean_redirections_loop(new_token, token);
	return (new_token);
}

t_token	*clean_redirections_loop(t_token *new_token, t_token *token)
{
	int	iter;
	int	count;

	while (token->args[iter] != NULL)
	{
		if (ft_strcmp(token->args[iter], ">") == 0
			|| ft_strcmp(token->args[iter], ">>") == 0
			|| ft_strcmp(token->args[iter], "<") == 0
			|| ft_strcmp(token->args[iter], "<<") == 0)
			iter += 2;
		else
		{
			new_token->ars[count] = ft_strdup(token->args[iter]);
			iter++;
			count++;
		}
	}
	new_token->args[count] = NULL;
	return (new_token);
}

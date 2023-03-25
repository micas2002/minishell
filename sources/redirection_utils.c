/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:02:47 by filipe            #+#    #+#             */
/*   Updated: 2023/03/25 13:56:24 by mibernar         ###   ########.fr       */
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

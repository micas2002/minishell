/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:20:51 by filipe            #+#    #+#             */
/*   Updated: 2023/03/21 23:19:30 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirections(t_token *token)
{
	if (check_redirections(token) == 1)
		handle_output_redirections(token);
	else if (check_redirections(token) == 2)
		handle_input_redirections(token);
}

int	here_doc(char *delim)
{
	char	*line;
	char	*promt;
	int		fd;
	
	fd = open(".tmp.txt", O_TRUNC | O_CREAT | O_RDWR, 0666);
	promt = ft_strjoin(delim, "> ");
	line = readline(promt);
	while (1)
	{
		if (ft_strncmp(line, delim, ft_strlen(line) - 1) == 0 && ft_strlen(line) > 1)
			break ;
		ft_putstr_fd(line, fd);
		free(line);
		line = readline(promt);
	}
	free(promt);
	free(line);
	return (fd);
}

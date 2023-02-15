/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:14 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/15 19:36:11 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of the search and execute the right executable. Checks the
//number of arguments given to the executable and allocates an array with that
//input. Gives the arguments to execve function
void	execute_program(t_shell *shell, int i, char **env)
{
	char	**paths;
	char	*command;

	if (ft_strncmp("./", shell->tokens[i], 2) == 0)
	{
		command = getcwd(command, FILENAME_MAX);
		command = ft_strjoin(command, "/");
		command = ft_strjoing(command, shell->tokens[i] + 2);
	}
	else
	{
	}
}

char	**get_command_paths(char **envp)
{
	char	**paths;
	int		index;

	index = 0;
	while (envp[index] != NULL)
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			paths = ft_split(envp[index] + 5, ':');
			return (paths);
		}
		index++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:14 by mibernar          #+#    #+#             */
/*   Updated: 2023/04/24 20:31:31 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of the search and execute the right executable. Checks the
//number of arguments given to the executable and allocates an array with that
//input. Gives the arguments to execve function
void	execute_program(t_shell *shell, int i)
{
	int	process;
	int	value;

	process = fork();
	value = 0;
	if (process == 0)
		run_program(shell, i, NULL, NULL);
	waitpid(process, &value, 0);
	g_exit_value = (value & 0xff00) >> 8;
}

void	run_program(t_shell *shell, int i, char *command, char **args)
{
	char	*tmp;

	if (ft_strncmp("./", shell->tokens[i]->args[0], 2) == 0)
	{
		command = getcwd(command, FILENAME_MAX);
		tmp = ft_strjoin(command, "/");
		free(command);
		command = ft_strjoin(tmp, shell->tokens[i]->args[0] + 2);
		free(tmp);
	}
	else if (shell->tokens[i]->args[0][0] != '/')
	{
		args = get_command_paths(shell->env);
		command = get_command(args, shell->tokens[i]->args[0]);
		if (command == NULL)
			exit(error_handler(ERR_CMD, 127, ""));
	}
	else
		command = shell->tokens[i]->args[0];
	free_double_array(args);
	execute_command(shell, i, command);
}

void	execute_command(t_shell *shell, int i, char *command)
{
	free(shell->tokens[i]->args[0]);
	shell->tokens[i]->args[0] = ft_strdup(command);
	if (execve(command, shell->tokens[i]->args, shell->env) == -1)
	{
		free(command);
		exit(error_handler(ERR_NO_SUCH_FILE_OR_DIR, 127,
				shell->tokens[i]->args[0]));
	}
	free(command);
	exit(EXIT_SUCCESS);
}

char	*get_command(char **paths, char *command_name)
{
	int		index;
	char	*temporary;
	char	*command;

	index = 0;
	if (paths == NULL)
		return (NULL);
	while (paths[index] != NULL)
	{
		temporary = ft_strjoin(paths[index], "/");
		command = ft_strjoin(temporary, command_name);
		free(temporary);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		index++;
	}
	return (NULL);
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

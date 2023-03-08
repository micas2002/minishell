/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:14 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/28 17:06:19 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of the search and execute the right executable. Checks the
//number of arguments given to the executable and allocates an array with that
//input. Gives the arguments to execve function
void	execute_program(t_shell *shell, int i, char **env)
{
	int	process;
	int	value;

	process = fork();
	value = 0;
	if (process == 0)
		run_program(shell, i, env);
	waitpid(process, &value, 0);
	g_exit_value = value;
}

void	run_program(t_shell *shell, int i, char **env)
{
	char	*command;
	char	**args;
	int		iq;

	args = NULL;
	command = NULL;
	args = NULL;
	if (ft_strncmp("./", shell->tokens[i], 2) == 0)
		command = get_command_path(shell->tokens[i] + 2);
	else if (shell->tokens[i][0] != '/')
	{
		args = get_paths(env);
		command = get_command(args, shell->tokens[i]);
		if (command == NULL)
			exit(error_handler(ERR_CMD_N_FOUND, EXIT_FAILURE));
	}
	free_double_array(args);
	args = get_arguments(shell, i);
	if (args == NULL)
		printf("NULL\n");
	iq = execve(command, args, env);
	if (iq == -1)
		exit(error_handler(ERR_CMD, EXIT_FAILURE));
	exit(EXIT_SUCCESS);
}

char	*get_command(char **paths, char *command_name)
{
	int		index;
	char	*temporary;
	char	*command;

	index = 0;
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

char	**get_paths(char **envp)
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

char	**get_arguments(t_shell *shell, int i)
{
	char	**args;
	int		iter;

	iter = i;
	while (shell->tokens[iter] != NULL)
	{
		if (is_operator(shell->tokens[iter][0]) == 0)
			iter++;
	}
	args = malloc(sizeof(char *) * (iter - i + 1));
	if (args == NULL)
		return (NULL);
	iter = i;
	while (shell->tokens[iter] != NULL)
	{
		if (is_operator(shell->tokens[iter][0]) == 0)
		{
			args[iter - i] = ft_strdup(shell->tokens[iter]);
			iter++;
		}
	}
	args[iter] = NULL;
	return (args);
}

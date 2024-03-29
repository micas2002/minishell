/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:23:06 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/20 17:22:35 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipes(t_shell *shell, int iter)
{
	t_pipe	*info;

	info = malloc(sizeof(t_pipe));
	info->pid = malloc(sizeof(pid_t) * shell->nb_tokens);
	while (shell->tokens[iter] != NULL)
	{
		if (is_special_function(shell, iter) == 1)
			info->pid[iter] = 1;
		else
		{
			if (pipe(info->pipe) == -1)
				return ;
			info->pid[iter] = fork();
			if (info->pid[iter] == -1)
				return ;
			if (info->pid[iter] == 0)
				child_function(shell, info, iter);
			close(info->pipe[1]);
			info->fd = info->pipe[0];
		}
		iter++;
	}
	wait_all_forks(shell, info);
}

void	child_function(t_shell *shell, t_pipe *pipe, int iter)
{
	child_input(shell, pipe, iter);
	child_output(shell, pipe, iter);
	shell->tokens[iter] = clean_redirections(shell->tokens[iter]);
	commands(shell, iter);
	exit(g_exit_value);
}

void	child_input(t_shell *shell, t_pipe *pipe, int iter)
{
	int	input_fd;

	input_fd = handle_input_redirections(shell->tokens[iter], -1, 0, -1);
	if (iter == 0)
		close(pipe->pipe[0]);
	if (input_fd == -1 && iter > 0)
	{
		dup2(pipe->fd, STDIN_FILENO);
		close(pipe->fd);
	}
	else if (input_fd != -1)
	{
		if (iter > 0)
			close(pipe->fd);
		dup2(input_fd, STDIN_FILENO);
		close(input_fd);
	}
}

void	child_output(t_shell *shell, t_pipe *pipe, int iter)
{
	int	output_fd;

	output_fd = handle_output_redirections(shell->tokens[iter]);
	if (output_fd == -1 && iter < (shell->nb_tokens - 1))
		dup2(pipe->pipe[1], STDOUT_FILENO);
	else if (output_fd != -1)
	{
		dup2(output_fd, STDOUT_FILENO);
		close(output_fd);
	}
}

void	wait_all_forks(t_shell *shell, t_pipe *pipe)
{
	int	iter;

	iter = 0;
	while (iter < shell->nb_tokens)
	{
		waitpid(pipe->pid[iter], &g_exit_value, 0);
		g_exit_value = (g_exit_value & 0xff00) >> 8;
		iter++;
	}
	free(pipe->pid);
	free(pipe);
}

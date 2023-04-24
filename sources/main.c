/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:43:32 by mibernar          #+#    #+#             */
/*   Updated: 2023/04/24 18:13:29 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

// Main function. While true, uses readline to get input and prompt a message
// into the shell. Signal is handling SIGINT to write a newline and ignores
// SIGQUIT. Adds the commands to the history using add_history and parses
// the input using parser

int		g_exit_value;

char	**dup_env(char **env)
{
	char	**new_env;
	int		i;

	new_env = malloc(sizeof(char *) *(get_env_size(env) + 1));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

void	terminal(t_shell shell)
{
	char	*str;

	receive_signal_i();
	while (1)
	{
		shell.nb_tokens = 0;
		str = readline("myshell:$ ");
		if (!str)
		{
			write (1, "\n", 1);
			break ;
		}
		receive_signal();
		add_history(str);
		parser(str, &shell);
		free (str);
		receive_signal_i();
	}
	rl_clear_history();
	free_double_array(shell.env);
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	shell.env = dup_env(env);
	shell.tokens = NULL;
	(void) argc;
	(void) argv;
	terminal(shell);
	return (g_exit_value);
}

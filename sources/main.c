/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:43:32 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/20 15:55:36 by mibernar         ###   ########.fr       */
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

void	terminal(t_shell shell)
{
	char	*str;

	receive_signal_i();
	while (1)
	{
		shell.nb_tokens = 0;
		str = readline("myshell:$ ");
		receive_signal();
		add_history(str);
		parser(str, &shell);
		free (str);
		receive_signal_i();
	}
	rl_clear_history();
}

int	main(int argc, char **argv, char **env)
{
	t_shell	shell;

	shell.env = env;
	shell.tokens = NULL;
	(void) argc;
	(void) argv;
	terminal(shell);
	return (g_exit_value);
}

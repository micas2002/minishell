/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:43:32 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/16 15:18:05 by fialexan         ###   ########.fr       */
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

void	terminal(char **env)
{
	char	*str;
	t_shell	shell;

	shell.tokens = NULL;
	while (1)
	{
		signal(SIGINT, handle_signals);
		signal(SIGQUIT, SIG_IGN);
		shell.nb_tokens = 0;
		str = readline("myshell:$ ");
		//str = "ls";
		add_history(str);
		parser(str, &shell, env);
		//free (str);
	}
	rl_clear_history();
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	terminal(env);
	return (g_exit_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:43:32 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/15 16:10:38 by mibernar         ###   ########.fr       */
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
void	terminal(char **env)
{
	char	*str;
	t_sh	sh;

	while (1)
	{
		signal(SIGINT, handle_signals);
		signal(SIGQUIT, SIG_IGN);
		sh.nb_tokens = 0;
		str = readline("myshell:$ ");
		//str = "./minishell aa aaa";
		add_history(str);
		parser(str, &sh, env);
		free (str);
	}
	rl_clear_history();
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	terminal(env);
	return (0);
}

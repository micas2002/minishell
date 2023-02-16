/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:42:26 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/16 18:55:42 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//When signal received is SIGINT, prints a newline
void	handle_signals(int signum)
{
	if (signum == SIGINT)
	{
		write(0, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_exit_value = 130;
		exit(1);
	}
	if (signum == SIGQUIT)
	{
		write(0, "Quit (core dumped)\n", 20);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	handle_signals_i(int signum)
{
	if (signum == SIGINT)
	{
		write(0, "\n", 1);
		g_exit_value = 130;
	}
}

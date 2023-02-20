/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:42:26 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/20 13:04:53 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signals(int sig)
{
	if (sig == SIGINT)
	{
		write(0, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		g_exit_value = 130;
	}
	if (sig == SIGQUIT)
	{
		write(0, "Quit (core dumped)\n", 20);
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	receive_signal(void)
{
	signal(SIGQUIT, handle_signals);
	signal(SIGINT, handle_signals);
}

void	handle_signals_i(int sig)
{
	if (sig == SIGINT)
	{
		write(0, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_value = 130;
	}
}

void	receive_signal_i(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signals_i);
}

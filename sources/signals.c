/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:42:26 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/19 13:59:45 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//When signal received is SIGINT, prints a newline
void	handle_signals(int signum)
{
	(void) signum;
	printf("\nmyshell:$ ");
}

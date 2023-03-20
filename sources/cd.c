/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:48:53 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/20 17:49:23 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of cd command. If there's no arguments after command, prompts
//a message; if the argument after the command is "..", it returns to previous
//directory; last if there's other argument after command, moves to that
//directory if chrdir == 0, if not, prompts a message
void	cd(t_token *token)
{
	int	iter;

	iter = 0;
	if (!token->args[iter + 1])
	{
		g_exit_value = error_handler(ERR_NO_PATH, EXIT_FAILURE, "");
		return ;
	}
	if (ft_strcmp(token->args[iter + 1], "..") == 0)
		chdir("..");
	else
	{
		if (chdir(token->args[iter + 1]) != 0)
		{
			g_exit_value = error_handler(ERR_NO_FILE, EXIT_FAILURE, "");
			return ;
		}
	}
	g_exit_value = EXIT_SUCCESS;
}

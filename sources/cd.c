/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:48:53 by mibernar          #+#    #+#             */
/*   Updated: 2023/04/18 16:43:28 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of cd command. If there's no arguments after command, prompts
//a message; if the argument after the command is "..", it returns to previous
//directory; last if there's other argument after command, moves to that
//directory if chrdir == 0, if not, prompts a message
void	cd_has_path(t_shell *shell, t_token *token, int iter)
{
	char	*home_path;

	home_path = NULL;
	if (ft_strcmp(token->args[iter + 1], "..") == 0)
		chdir("..");
	else if (ft_strcmp(token->args[iter + 1], "~") == 0)
	{
		home_path = get_env_variable(shell, "HOME", 4);
		if (chdir(home_path) != 0)
		{
			free (home_path);
			g_exit_value = error_handler(ERR_NO_FILE, 1, "");
			return ;
		}
	}
	else
	{
		if (chdir(token->args[iter + 1]) != 0)
		{
			g_exit_value = error_handler(ERR_NO_FILE, 1, "");
			return ;
		}
	}
	if (home_path != NULL)
		free (home_path);
	g_exit_value = EXIT_SUCCESS;
}

void	cd(t_shell *shell, t_token *token)
{
	int		iter;

	iter = 0;
	if (!token->args[iter + 1])
	{
		g_exit_value = error_handler(ERR_NO_PATH, 1, "");
		return ;
	}
	cd_has_path(shell, token, iter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:48:53 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/20 13:39:30 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of cd command. If there's no arguments after command, prompts
//a message; if the argument after the command is "..", it returns to previous
//directory; last if there's other argument after command, moves to that
//directory if chrdir == 0, if not, prompts a message
void	cd(t_shell *shell, int i)
{
	if (!shell->tokens[i + 1])
	{
		printf("relative or absolute path needed\n");
		return ;
	}
	if (ft_strcmp(shell->tokens[i + 1], "..") == 0)
		chdir("..");
	else
	{
		if (chdir(shell->tokens[i + 1]) != 0)
			printf("No such file or directory\n");
	}
}

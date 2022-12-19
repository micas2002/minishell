/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:48:53 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/19 13:36:32 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//Implementation of cd command. If there's no arguments after command, prompts
//a message; if the argument after the command is "..", it returns to previous
//directory; last if there's other argument after command, moves to that
//directory if chrdir == 0, if not, prompts a message
void	cd(t_sh *sh, int i)
{
	if (!sh->tokens[i + 1])
	{
		printf("relative or absolute path needed\n");
		return ;
	}
	if (ft_strcmp(sh->tokens[i + 1], "..") == 1)
		chdir("..");
	else
	{
		if (chdir(sh->tokens[i + 1]) != 0)
			printf("No such file or directory\n");
	}
}

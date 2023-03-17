/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:48:53 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/17 17:28:54 by mibernar         ###   ########.fr       */
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
		printf("relative or absolute path needed\n");
		return ;
	}
	if (ft_strcmp(token->args[iter + 1], "..") == 0)
		chdir("..");
	else
	{
		if (chdir(token->args[iter + 1]) != 0)
			printf("No such file or directory\n");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:10 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/14 16:21:11 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of echo command. If the argument after command is the flag -n
//(which removes the newline), moves to the next argument. While there is valid
//input, it prints the message. If the -n flag exists, it doesn't print the
//newline

void	echo(t_shell *shell, int i, int x)
{
	char	*str;

	if (!shell->tokens[i]->arguments[0])
	{
		printf("\n");
		return ;
	}
	x = 0;
	if (ft_strcmp(shell->tokens[i]->arguments[x], "-n") == 0)
		x++;
	while (shell->tokens[i]->arguments[x])
	{
		if (shell->tokens[i]->arguments[x][0] == '\"')
			str = ft_strtrim(shell->tokens[i]->arguments[x], "\"");
		else
			str = ft_strtrim(shell->tokens[i]->arguments[x], "\'");
		printf("%s", str);
		// if (shell->tokens[i]->arguments[x]
		// 	&& is_operator(shell->tokens[i]->arguments[x][0]) == 0)
		// 	printf(" ");
		x++;
		if (str)
			free(str);
	}
	if (ft_strcmp(shell->tokens[i]->arguments[0], "-n") == 0)
		return ;
	printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:10 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/15 18:26:10 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of echo command. If the argument after command is the flag -n
//(which removes the newline), moves to the next argument. While there is valid
//input, it prints the message. If the -n flag exists, it doesn't print the
//newline

void	echo(t_shell *shell, int i)
{
	char	*str;
	int		x;

	if (!shell->tokens[i + 1])
	{
		printf("\n");
		return ;
	}
	x = i + 1;
	if (ft_strcmp(shell->tokens[++i], "-n") == 0)
		i++;
	while (shell->tokens[i] && ft_strcmp(shell->tokens[i], "|") != 0)
	{
		if (shell->tokens[i][0] == '\"')
			str = ft_strtrim(shell->tokens[i], "\"");
		else
			str = ft_strtrim(shell->tokens[i], "\'");
		printf("%s", str);
		if (shell->tokens[i + 1] && is_operator(shell->tokens[i + 1][0]) == 0)
			printf(" ");
		i++;
		if (str)
			free(str);
	}
	if (ft_strcmp(shell->tokens[x], "-n") == 0)
		return ;
	printf("\n");
}


void	echo(t_token *token)
{
	char	*str;
	int		iter;
	
	if (token->args[1] == NULL)
	{
		printf("\n");
		return ;
	}
}
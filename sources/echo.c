/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:10 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/16 11:48:15 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of echo command. If the argument after command is the flag -n
//(which removes the newline), moves to the next argument. While there is valid
//input, it prints the message. If the -n flag exists, it doesn't print the
//newline
void	echo(t_shell *shell, int i)
{
	int	x;

	x = i + 1;
	if (ft_strcmp(shell->tokens[++i], "-n") == 0)
		i++;
	while (shell->tokens[i] && ft_strcmp(shell->tokens[i], "|") != 0)
		printf("%s", shell->tokens[i++]);
	if (ft_strcmp(shell->tokens[x], "-n") == 0)
		return ;
	printf("\n");
}

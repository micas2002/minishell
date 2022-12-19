/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:10 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/19 13:40:52 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of echo command. If the argument after command is the flag -n
//(which removes the newline), moves to the next argument. While there is valid
//input, it prints the message. If the -n flag exists, it doesn't print the
//newline
void	echo(t_sh *sh, int i)
{
	int	x;

	x = i + 1;
	if (ft_strcmp(sh->tokens[++i], "-n") == 1)
		i++;
	while (sh->tokens[i] && ft_strcmp(sh->tokens[i], "|") == 0)
		printf("%s", sh->tokens[i++]);
	if (ft_strcmp(sh->tokens[x], "-n") == 1)
		return ;
	printf("\n");
}

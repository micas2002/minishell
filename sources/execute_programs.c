/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:14 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/19 13:44:59 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of the search and execute the right executable. Checks the
//number of arguments given to the executable and allocates an array with that
//input. Gives the arguments to execve function
void	execute_program(t_sh *sh, int i)
{
	char	**input;
	int		x;
	int		y;

	x = i;
	while (sh->tokens[i] && ft_strcmp(sh->tokens[i], "|") == 0)
		i++;
	input = malloc(sizeof(char *) * i - x);
	y = -1;
	while (x != i)
	{
		input[++y] = malloc(sizeof(char) * ft_strlen(sh->tokens[x]));
		input[y] = sh->tokens[x];
		x++;
	}
	input[++y] = NULL;
//	execve(ft_substr(sh->tokens[i], 1, ft_strlen(sh->tokens[i] - 1)), input, NULL);
}

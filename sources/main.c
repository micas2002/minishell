/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:43:32 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/13 11:26:32 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	terminal(void)
{
	char	*str;
	t_sh	sh;

	while (1)
	{
		sh.nb_tokens = 0;
		str = readline("myshell:$ ");
		// str = "a | a";
		parser(str, &sh);
	}
}

int	main(void)
{
	terminal();
	return (0);
}

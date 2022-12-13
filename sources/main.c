/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:43:32 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/13 15:11:23 by mibernar         ###   ########.fr       */
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
		add_history(str);
		// str = "a | a";
		parser(str, &sh);
		free (str);
	}
	rl_clear_history();
}

int	main(void)
{
	terminal();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/12 13:56:38 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft.h"

void	commands(t_minish *minish)
{
	if ()
}

void	parser(char *str, t_minish *minish)
{
	int	i = -1;

	lexer(str, minish);
	while (minish->tokens[++i])
		printf("token:%s\n", minish->tokens[i]);
	i = -1;
	while (minish->tokens[++i])
	{
		if (i == 0 || (is_operator(minish->tokens[i]) == 0 || minish->tokens))
	}
}

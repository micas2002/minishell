/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/09 12:31:53 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	other_input(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '	')
			break ;
	}
	return (i);
}

int	d_quotes(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] == '\"')
			break ;
	}
	return (i);
}

int	s_quotes(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] == '\'')
			break ;
	}
	return (i);
}

int	is_operator(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' || c == ')' || c == '<'
		|| c == '>')
		return (1);
	return (0);
}

void	lexer(char *str, t_minish minish)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	')
			i++;
		else
		{
			if (str[i] == '\"')
				i = d_quotes(str, i);
			if (str[i] == '\'')
				i = s_quotes(str, i);
			else
				i = other_input(str, i);
			minish.nb_tokens++;
		}
	}
	printf("number of tokens:%d\n", minish.nb_tokens);
}

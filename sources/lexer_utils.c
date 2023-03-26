/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:18:32 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/26 12:08:38 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char c)
{
	if (c == '&' || c == ';' || c == '(' || c == ')' || c == '<'
		|| c == '>')
		return (1);
	return (0);
}

int	operators(char *str, int i)
{
	while (str[++i])
	{
		if (is_operator(str[i]) == 0)
			return (i);
	}
	return (i);
}

int	other_input(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	' || is_operator(str[i]) == 1)
			break ;
		i++;
	}
	return (i);
}

int	quote_handler(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (str[i] == '\0')
		i = -2;
	return (i);
}

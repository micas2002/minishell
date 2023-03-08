/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:18:32 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/08 18:33:19 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' || c == ')' || c == '<'
		|| c == '>')
		return (1);
	return (0);
}

int	operators(char *str, int i)
{
	while (str[++i])
	{
		if (is_operator(str[i]) == 0)
			break ;
	}
	return (i);
}

int	other_input(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '	' || is_operator(str[i]) == 1)
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
	if (str[i] == '\0' && str[i - 1] != '\"')
		printf("ERROR: unclosed quotes\n");
	return (i);
}

int	s_quotes(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] == '\'')
			break ;
	}
	if (str[i] == '\0' && str[i - 1] != '\'')
		printf("ERROR: unclosed quotes\n");
	return (i);
}

int	quotes_split_size(char *str)
{
	int	iter;
	int	counter;

	iter = 0;
	counter = 0;
	while(str[iter] != NULL)
	{
		if (str[iter] == ' ')
			iter++;
		else if (str[iter] == '\"')
		{
			iter = d_quotes(str, iter);		
			counter++;
		}
		else if (str[iter] == '\'')
		{
			iter = s_quotes(str, iter);
			counter++;
		}
		else
		{
			iter = other_input(str, iter);
			counter++;
		}
	}
}

char	**quotes_split(char *str)
{
	
}

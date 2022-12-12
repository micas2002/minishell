/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/12 13:29:31 by mibernar         ###   ########.fr       */
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
	{
		printf("ERROR: unclosed quotes\n");
		terminal();
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
	if (str[i] == '\0' && str[i - 1] != '\'')
	{
		printf("ERROR: unclosed quotes\n");
		terminal();
	}
	return (i);
}

void	lexer(char *str, t_minish *minish)
{
	int		i;
	int		x;
	int		y;

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
			if (is_operator(str[i]) == 1)
				i = operators(str, i);
			else
				i = other_input(str, i);
			minish->nb_tokens++;
		}
	}
	minish->tokens = malloc(sizeof(char *) * minish->nb_tokens + 1);
	i = 0;
	x = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	')
			i++;
		else
		{
			x = i;
			if (str[i] == '\"')
				i = d_quotes(str, i);
			if (str[i] == '\'')
				i = s_quotes(str, i);
			if (is_operator(str[i]) == 1)
				i = operators(str, i);
			else
				i = other_input(str, i);
			minish->tokens[y] = ft_substr(str, x, i - x);
			y++;
		}
	}
	minish->tokens[y] = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:49 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/19 13:57:23 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Checks if the character is a metachar
int	is_operator(char c)
{
	if (c == '|' || c == '&' || c == ';' || c == '(' || c == ')' || c == '<'
		|| c == '>')
		return (1);
	return (0);
}

//Saves the operator token
int	operators(char *str, int i)
{
	while (str[++i])
	{
		if (is_operator(str[i]) == 0)
			break ;
	}
	return (i);
}

//Saves the input that isn't any of the other listed
int	other_input(char *str, int i)
{
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '	' || is_operator(str[i]) == 1)
			break ;
	}
	return (i);
}

//Saves the double quote token. If the quote is not closed, promts a message
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

//Saves the single quote token. If the quote is not closed, promts a message 
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

//Lexer takes input and devides it into tokens. Skips any spaces(if not between
//quotes) and checks if the argument is a sinlge quote, double quote, an
//operator(for example a pipe), or other kind of input. Creates an array of size
//equal to the number os tokens and saves each token his own string
void	lexer(char *str, t_sh *sh)
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
			sh->nb_tokens++;
		}
	}
	sh->tokens = malloc(sizeof(char *) * sh->nb_tokens + 1);
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
			sh->tokens[y] = ft_substr(str, x, i - x);
			y++;
		}
	}
	sh->tokens[y] = NULL;
}

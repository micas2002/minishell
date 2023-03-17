/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:49 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/17 17:09:40 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lexer(char *s, char c)
{
	int		array_size;
	char	**str;

	if (!s)
		return (NULL);
	array_size = get_lexer_array_size((char *)s, ' ');
	if (array_size == -1)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (!str)
		return (NULL);
	str = lexer_loop(s, str);
	return (str);
}

char	**lexer_loop(char const *s, char **str)
{
	int	begin;
	int	i;
	int	x;

	i = 0;
	x = 0;
	begin = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			i = quote_handler((char *)s, i + 1, '\'') + 1;
		if (s[i] == '\"')
			i = quote_handler((char *)s, i + 1, '\"') + 1;
		if (s[i] == ' ')
		{
			str[x] = ft_substr((char *)s, begin, i - begin);
			i++;
			begin = i;
			x++;
		}
		else
			i++;
	}
	str[x] = ft_substr((char *)s, begin, i - begin);
	str[++x] = NULL;
	return (str);
}

int	get_lexer_array_size(char *s, char c)
{
	int	i;
	int	control;
	int	size;

	i = 0;
	control = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			i = quote_handler(s, i, '\'');
		if (s[i] == '\"')
			i = quote_handler(s, i, '\"');
		if (i == -1)
			return (-1);
		if (s[i] != c && control == 0)
		{
			control = 1;
			size++;
		}
		else if (s[i] == c)
			control = 0;
		i++;
	}
	return (size);
}

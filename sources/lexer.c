/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:49 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/15 17:34:48 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**lexer_loop(char const *s, char **str)
{
	int	begin;
	int	i;
	int x;

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

char	**lexer(char *s, char c)
{
	int		array_size;
	char	**str;

	if (!s)
		return (NULL);
	array_size = get_array_size((char *)s, c);
	if (array_size == -1)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (!str)
		return (NULL);
	str = minishell_split_loop(s, str, 0, 0);
	return (minishell_split_loop(s, str, 0, 0));
}
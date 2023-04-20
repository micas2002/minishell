/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:14:37 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/18 19:51:50 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_array_size_split(char *s, char c, int i, int size)
{
	int	control;
	int	quotes;

	control = 0;
	quotes = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			if (quotes == 0)
				quotes = s[i];
			else if (quotes == s[i])
				quotes = 0;
		}
		else if (s[i] != c && control == 0 && quotes == 0)
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

static char	*get_str(char *s, int begin, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!str)
		return (NULL);
	while (begin < end)
	{
		str[i] = s[begin];
		i++;
		begin++;
	}
	str[i] = '\0';
	return (str);
}

static int	get_end(char *s, int end, char c)
{
	int	quotes;

	quotes = 0;
	while (s[end] != '\0')
	{
		if (s[end] == '"' || s[end] == '\'')
		{
			if (quotes == 0)
				quotes = s[end];
			else if (quotes == s[end])
				quotes = 0;
		}
		else if (s[end] == c && quotes == 0)
			return (end);
		end++;
	}
	return (end);
}

static int	get_begin(char *s, int begin, char c)
{
	while (s[begin] == c && s[begin] != '\0')
		begin++;
	return (begin);
}

char	**ft_split_minishell(char const *s, char c, int begin, int end)
{
	int		array_size;
	char	**str;
	int		i;

	if (!s)
		return (NULL);
	array_size = get_array_size_split((char *)s, c, 0, 0);
	if (array_size == 0)
		array_size = 1;
	str = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < array_size)
	{
		begin = get_begin((char *)s, end, c);
		end = get_end((char *)s, begin, c);
		str[i] = get_str((char *)s, begin, end);
		i++;
	}
	str[i] = NULL;
	return (str);
}

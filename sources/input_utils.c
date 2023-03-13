/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/13 19:16:37 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	quote_checker(char *str)
{	
	int	single_quote;
	int	double_quote;
	int	i;

	i = -1;
	single_quote = 0;
	double_quote = 0;
	while (str[++i])
	{
		if (i >= 2 && str[i - 1] == '\\' && str[i - 2] != '\\')
			continue ;
		if (str[i] == '\"' && double_quote == 0 && single_quote == 0)
			double_quote = 1;
		else if (str[i] == '\"' && double_quote == 1 && single_quote == 0)
			double_quote = 0;
		else if (str[i] == '\'' && single_quote == 0 && double_quote == 0)
			single_quote = 1;
		else if (str[i] == '\'' && single_quote == 1 && double_quote == 0)
			single_quote = 0;
	}
	if ((single_quote && !double_quote) || (!single_quote && double_quote))
		return (1);
	return (0);
}

int	quote_handler(char *str, int i, char c)
{
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	get_array_size(char *s, char c)
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

char	**minishell_split(char const *s, char c, int i)
{
	int		array_size;
	char	**str;
	int		x;
	int		begin;

	if (!s)
		return (NULL);
	array_size = get_array_size((char *)s, c);
	if (array_size == -1)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (!str)
		return (NULL);
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

int	is_redir(char *str)
{
	if (ft_strcmp(str, ">") == 0)
		return (1);
	else if (ft_strcmp(str, "<") == 0)
		return (1);
	else if (ft_strcmp(str, ">>") == 0)
		return (1);
	else if (ft_strcmp(str, "<<") == 0)
		return (1);
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:26:46 by fialexan          #+#    #+#             */
/*   Updated: 2023/03/15 15:07:47 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_double_array_size(char **str)
{
	int	iter;

	iter = 0;
	while (str[iter] != NULL)
		iter++;
	return (iter);
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

int	quote_checker(char *str)
{	
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] == '\'')
			x = quote_handler(str, x, '\'');
		if (str[x] == '\'')
			x = quote_handler(str, x, '\'');
		if (x == -1)
			return (0);
		x++;
	}
	return (1);
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

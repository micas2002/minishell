/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:57:47 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/27 21:31:28 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_after_var(char *str, int i)
{
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '$' && str[i] != '\''
		&& str[i] != '\"')
	{
		if (str[i] == '\'')
			i = quote_handler(str, i, '\'');
		else
			i++;
	}
	if (i == 0)
		return (0);
	else if (str[i] == '$' || str[i] == ' ' || str[i] == '\'' || str[i] == '\"')
		return (i);
	return (-1);
}

int	check_var(char *str, int i)
{
	if (str[0] == '\"')
		i++;
	while (str[i] != '\0' && str[i] != '$' && str[i] != '\"')
	{
		if (str[i] == '\'')
			i = quote_handler(str, i + 1, '\'') + 1;
		else
			i++;
	}
	if (i == 0)
		return (0);
	else if (str[i] == '$' || str[i] == '\'' || str[i] == '\"')
		return (i);
	return (-1);
}

char	*get_env_var(t_shell *shell, char *str, char *tmp)
{
	int		x;
	int		y;
	char	*before_var;
	char	*var;
	char	*after_var;

	x = check_var(str, 0);
	if (x == -1)
		return (str);
	before_var = ft_substr(str, 0, x);
	y = check_after_var(str, x + 1);
	if (y == -1)
	{
		var = no_var_after(shell, str, before_var, x);
		return (var);
	}
	tmp = ft_substr(str, x + 1, y - x - 1);
	var = get_env_variable(shell, tmp, y - x);
	after_var = ft_strjoin(before_var, var);
	free(before_var);
	if (var != NULL && ft_strcmp(var, "") != 0)
		free(var);
	before_var = ft_substr(str, y, ft_strlen(str) - y);
	var = join_final(var, after_var, before_var, tmp);
	return (var);
}

t_token	**handle_dollar(t_shell *shell, t_token **tokens)
{
	int		iter;

	iter = 0;
	if (tokens == NULL)
		return (NULL);
	while (tokens[iter] != NULL)
	{
		check_dollar(shell, tokens, iter);
		iter++;
	}
	return (tokens);
}

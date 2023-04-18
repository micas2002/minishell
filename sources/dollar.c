/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:57:47 by mibernar          #+#    #+#             */
/*   Updated: 2023/04/18 16:13:55 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*found_exit_status_var(int x, char *str, char *before_var, char *tmp)
{
	char	*var;
	char	*after_var;

	var = ft_itoa(g_exit_value);
	tmp = ft_strjoin(before_var, var);
	after_var = ft_substr(str, x + 2, ft_strlen(str) - x - 2);
	free(before_var);
	before_var = ft_strjoin(tmp, after_var);
	free(tmp);
	free(after_var);
	free(var);
	return (before_var);
}

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
	while (str[i] != '\0' && str[i] != '\"')
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\0'	)
				i++ ;
			else
				break ;
		}
		else if (str[i] == '\'')
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
	if (str[x] == '$' && str[x + 1] == '?')
		return (found_exit_status_var(x, str, before_var, tmp));
	y = check_after_var(str, x + 1);
	if (y == -1)
		return (no_var_after(shell, str, before_var, x));
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

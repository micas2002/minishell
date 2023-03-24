/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/24 12:24:14 by mibernar         ###   ########.fr       */
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

	x = 0;
	if (str[0] == '\"')
		x++;
	x = check_var(str, x);
	if (x == -1)
		return (str);
	before_var = ft_substr(str, 0, x);
	y = check_after_var(str, x + 1);
	if (y == -1)
	{
		var = ft_substr(str, x + 1, ft_strlen(str) - x);
		after_var = get_env_variable(shell, var, ft_strlen(var));
		free(var);
		var = ft_strjoin(before_var, after_var);
		if (after_var && ft_strcmp(after_var, "") != 0)
			free(after_var);
		free(before_var);
		return (var);
	}
	tmp = ft_substr(str, x + 1, y - x - 1);
	var = get_env_variable(shell, tmp, y - x);
	after_var = ft_strjoin(before_var, var);
	free(before_var);
	if (var != NULL && ft_strcmp(var, "") != 0)
		free(var);
	before_var = ft_substr(str, y, ft_strlen(str) - y);
	var = ft_strjoin(after_var, before_var);
	free(after_var);
	free(before_var);
	free(tmp);
	return (var);
}

t_token	**handle_dollar(t_shell *shell, t_token **tokens)
{
	int		iter;
	int		x;
	char	*tmp;
	char	*util;


	iter = 0;
	util = NULL;
	while (tokens[iter] != NULL)
	{
		x = 0;
		while (tokens[iter]->args[x] != NULL)
		{
			while (ft_strchr(tokens[iter]->args[x], '$') != NULL)
			{
				tmp = get_env_var(shell, tokens[iter]->args[x], util);
				if (ft_strcmp(tmp, tokens[iter]->args[x]) == 0)
					break ;
				free(tokens[iter]->args[x]);
				tokens[iter]->args[x] = tmp;
			}
			x++;
		}
		iter++;
	}
	return (tokens);
}

t_token	**divide_tokens(char **cmds)
{
	t_token	**tokens;
	int		iter;

	iter = 0;
	while (cmds[iter] != NULL)
		iter++;
	tokens = (t_token **)malloc(sizeof(t_token *) * (iter + 1));
	iter = 0;
	while (cmds[iter] != NULL)
	{
		tokens[iter] = (t_token *)malloc(sizeof(t_token));
		tokens[iter]->args = lexer(cmds[iter]);
		tokens[iter]->str = ft_strdup(cmds[iter]);
		iter++;
	}
	tokens[iter] = NULL;
	return (tokens);
}

int	get_array_size(char **str)
{
	int	iter;

	iter = 0;
	while (str[iter] != NULL)
		iter++;
	return (iter);
}

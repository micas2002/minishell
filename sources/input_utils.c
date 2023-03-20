/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/20 18:28:59 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_var(char *str, int i)
{
	while (str[i] != '\0' && str[i] != '$')
		i++;
	if (i == 0)
		return (0);
	else if (str[i] == '$')
		return (i);
	return (-1);
}

char	*get_env_var(t_shell *shell, char *str)
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
	y = check_var(str, x + 1);
	if (y == -1)
	{
		var = ft_substr(str, x + 1, ft_strlen(str) - x);
		before_var = ft_strjoin(before_var,
				get_env_variable(shell, var, ft_strlen(var)));
		return (before_var);
	}
	after_var = ft_substr(str, y, ft_strlen(str) - y);
	before_var = ft_strjoin(before_var, get_env_variable(shell,
				ft_substr(str, x + 1, y - x - 1), y - x));
	before_var = ft_strjoin(before_var, after_var);
	return (before_var);
}

t_token	**handle_dollar(t_shell *shell, t_token **tokens)
{
	int		iter;
	int		x;
	char	*tmp;


	iter = 0;
	while (tokens[iter] != NULL)
	{
		x = 0;
		while (tokens[iter]->args[x] != NULL)
		{
			while (ft_strchr(tokens[iter]->args[x], '$') != NULL)
			{
				tmp = get_env_var(shell, tokens[iter]->args[x]);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/17 19:54:53 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_var(char *str, int i)
{
	while (str[i] != '\0' && str[i] != '$')
		i++;
	if (str[i] == '$')
		return (i - 1);
	return (-1);
}

char	*get_env_var(t_shell *shell, char *str)
{
	int		x;
	int		y;
	char	*tmp;
	char	*tmp2;

	x = check_var(str, 0);
	if (x == -1)
		return (str);
	tmp = ft_substr(str, 0, x + 1);
	y = check_var(str, x + 1);
	if (y == -1)
	{
		tmp2 = ft_substr(str, x + 1, ft_strlen(str) - x);
		tmp = ft_strjoin(tmp, get_env_variable(shell, tmp2, ft_strlen(tmp2)));
		tmp = ft_strjoin(tmp, tmp2);
		free(tmp2);
		return (tmp);
	}
	tmp2 = ft_substr(str, y + 1, ft_strlen(str) - y);
	tmp = ft_strjoin(tmp, get_env_variable(shell, tmp2, y));
	tmp = ft_strjoin(tmp, tmp2);
	free(tmp2);
	return (tmp);
}

t_token	**handle_dollar(t_shell *shell, t_token **tokens)
{
	int		iter;
	int		x;
	int		y;
	char	*tmp;

	iter = 0;
	while (tokens[iter] != NULL)
	{
		x = 0;
		while (tokens[iter]->args[x] != NULL)
		{
			while (ft_findchar(tokens[iter]->args[x], '$') == 1)
			{
				tmp = get_env_var(shell, tokens[iter]->args[x], );
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
		tokens[iter]->args = lexer(cmds[iter], ' ');
		tokens[iter]->str = ft_strdup(cmds[iter]);
		iter++;
	}
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

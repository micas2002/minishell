/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/15 19:18:07 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_var(char *str, int i)
{
	while (str[i] != '\0' && str[i] != '$')
		i++;
	if (str[i] == '$')
		return (i - 1);
	return (i);
}

char *get_env_var(t_shell *shell, char *str, int i)
{
	char	*tmp;
	int		start;
	int		x;

	start = i;
	x = 0;
	i = check_var(str, i);
	tmp = ft_strjoin(ft_substr(str, start, i - start), "=");
	while (shell->env[x])
	{
		if (ft_strncmp(shell->env[x], tmp, ft_strlen(tmp)) == 0)
		{
			free(str);
			str = ft_substr(shell->env[x], ft_strlen(tmp), ft_strlen(shell->env[x]));
			free(tmp);
			return (str);
		}
		x++;
	}
	return ("");
}

t_token	**handle_dollar(t_token *tokens)
{
	int		iter;
	int		iter2;
	char	*tmp;

	iter = 0;
	while (tokens->args[iter] != NULL)
	{
		iter2 = 0;
		while (tokens->args[iter][iter2] != '\0')
		{
			if (tokens->args[iter][iter2] == '$')
			{
				tmp = ft_strdup(tokens->args[iter]);
				free(tokens->args[iter]);
				tokens->args[iter] = ft_strjoin(ft_substr(tmp, 0, iter2), ft_substr(tmp, iter2 + 1, ft_strlen(tmp)));
				free(tmp);
			}
			iter2++;
		}
		iter++;
	}
	return (tokens->args);
}

t_token **divide_tokens(char **cmds)
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

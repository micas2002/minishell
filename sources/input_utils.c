/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/15 18:22:29 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

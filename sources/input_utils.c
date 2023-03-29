/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/29 16:23:53 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	divide_tokens_loop(char **cmds, int iter, t_token **tokens)
{
	while (cmds[iter] != NULL)
	{
		tokens[iter] = (t_token *)malloc(sizeof(t_token));
		tokens[iter]->args = lexer(cmds[iter]);
		if (g_exit_value == EXIT_FAILURE)
		{
			while (iter >= 0)
			{
				free(tokens[iter]);
				iter--;
			}
			free(tokens);
			return (0);
		}
		iter++;
	}
	return (1);
}

t_token	**divide_tokens(t_shell *shell, char **cmds)
{
	t_token	**tokens;
	int		iter;
	int		og_exit_value;

	og_exit_value = g_exit_value;
	g_exit_value = EXIT_SUCCESS;
	iter = 0;
	if (cmds == NULL)
		return (NULL);
	while (cmds[iter] != NULL)
		iter++;
	tokens = (t_token **)malloc(sizeof(t_token *) * (iter + 1));
	if (divide_tokens_loop(cmds, 0, tokens) == 0)
	{
		shell->unclosed_quotes = 1;
		g_exit_value = og_exit_value;
		return (NULL);
	}
	tokens[iter] = NULL;
	return (tokens);
}

int	get_array_size(char **str)
{
	int	iter;

	iter = 0;
	if (str == NULL)
		return (0);
	while (str[iter] != NULL)
		iter++;
	return (iter);
}

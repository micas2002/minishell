/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:49 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/23 18:38:44 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_tokens(t_shell *shell, char *str, int x)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			x = i;
			if (str[i] == '\"')
				i = d_quotes(str, i, shell);
			if (str[i] == '\'')
				i = s_quotes(str, i, shell);
			if (is_operator(str[i]) == 1)
				i = operators(str, i);
			else
				i = other_input(str, i);
			shell->tokens[y] = ft_substr(str, x, i - x);
			y++;
		}
	}
	shell->tokens[y] = NULL;
}

void	lexer(char *str, t_shell *shell)
{
	int		i;
	int		x;

	free_tokens(shell);
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			if (str[i] == '\"')
				i = d_quotes(str, i, shell);
			if (str[i] == '\'')
				i = s_quotes(str, i, shell);
			if (is_operator(str[i]) == 1)
				i = operators(str, i);
			else
				i = other_input(str, i);
			shell->nb_tokens++;
		}
	}
	shell->tokens = malloc(sizeof(char *) * (shell->nb_tokens + 1));
	x = 0;
	save_tokens(shell, str, x);
}

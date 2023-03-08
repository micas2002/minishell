/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:49 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/08 18:33:11 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_tokens(t_shell *shell, char *str, int x)
{
	char	*env_var;
	int		i;
	int		a;
	int		y;

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

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else
		{
			if (str[i] == '\"')
				i = d_quotes(str, i);
			if (str[i] == '\'')
				i = s_quotes(str, i, shell);
			else
				i = other_input(str, i);
	}
	shell->tokens = malloc(sizeof(char *) * (shell->nb_tokens + 1));
	save_tokens(shell, str, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:49:49 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/25 12:24:23 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	save_tokens(t_shell *shell, char *str, int x)
{
	char	*env_var;
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
			if (str[i] == '$')
			{
				env_var = ft_substr(str, i + 1, ft_strlen(str));
				shell->tokens[y] = get_env_var(shell, env_var);
				i += ft_strlen(env_var) + 1;
				free(env_var);
			}
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
				shell->tokens[y] = ft_substr(str, x, i - x);
			}
			y++;
		}
	}
	shell->tokens[y] = NULL;
}

void	lexer(char *str, t_shell *shell)
{
	int		i;

	free_tokens(shell);
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '	')
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
	save_tokens(shell, str, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:58:49 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/25 14:45:08 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_final(char *var, char *after_var, char *before_var, char *tmp)
{
	var = ft_strjoin(after_var, before_var);
	free(after_var);
	free(before_var);
	free(tmp);
	return (var);
}

char	*no_var_after(t_shell *shell, char *str, char *before_var, int x)
{
	char	*var;
	char	*after_var;

	var = ft_substr(str, x + 1, ft_strlen(str) - x);
	after_var = get_env_variable(shell, var, ft_strlen(var));
	free(var);
	var = ft_strjoin(before_var, after_var);
	if (after_var && ft_strcmp(after_var, "") != 0)
		free(after_var);
	free(before_var);
	return (var);
}

void	check_dollar(t_shell *shell, t_token **tokens, int iter)
{
	char	*util;
	char	*tmp;
	int		x;

	x = 0;
	util = NULL;
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:14 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/18 16:47:15 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_env_size(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
		i++;
	return (i);
}

char	**new_env(t_shell *shell, int i)
{
	char	**new_env;
	int		x;
	int		y;

	new_env = malloc(sizeof(char **) * (get_env_size(shell->env)));
	x = 0;
	y = 0;
	while (shell->env[y] != NULL)
	{
		if (y == i)
			y++;
		else
		{
			new_env[x] = ft_strdup(shell->env[y]);
			x++;
			y++;
		}
	}
	new_env[x] = NULL;
	free_double_array(shell->env);
	return (new_env);
}

void	unset(t_shell *shell, t_token *token, int i)
{
	char	*env_var;
	int		x;

	while (token->args[i] != NULL)
	{
		env_var = ft_strjoin(token->args[i], "=");
		x = 0;
		while (shell->env[x] != NULL)
		{
			if (ft_strncmp(shell->env[x], env_var, ft_strlen(env_var)) == 0)
				break ;
			x++;
		}
		free(env_var);
		shell->env = new_env(shell, x);
	}
}

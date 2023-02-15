/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:14 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/15 19:43:26 by mibernar         ###   ########.fr       */
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

void	new_env(char **env, int i)
{
	char	**new_env;
	int		x;
	int		y;

	new_env = malloc(sizeof(char **) * get_env_size(env) - 1);
	x = 0;
	y = 0;
	while (env[x] != NULL)
	{
		if (x == i)
			y--;
		else
		{
			new_env[x + y] = malloc(sizeof(char) * ft_strlen(env[x]));
			new_env[x + y] = env[x];
		}
		x++;
	}
}

void	unset(t_shell *shell, int i, char **env)
{
	char	*env_var;
	int		x;

	env_var = ft_strjoin(shell->tokens[i + 1], "=");
	x = 0;
	while (env[x] != NULL)
	{
		if (ft_strncmp(env[x], env_var, ft_strlen(env_var)) == 0)
			break ;
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:11:14 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/16 13:01:05 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_prev_env(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		printf("here\n");
		free(shell->env[i]);
		i++;
	}
	free(shell->env);
}

int	get_env_size(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i] != NULL)
		i++;
	return (i);
}

char	**new_env(t_shell *shell, int i)
{
	char	**new_env;
	int		x;
	int		y;

	new_env = malloc(sizeof(char **) * (get_env_size(shell) - 1));
	x = 0;
	y = 0;
	while (shell->env[y] != NULL)
	{
		if (y == i)
			y++;
		else
		{
			new_env[x] = malloc(sizeof(char) * ft_strlen(shell->env[y]));
			new_env[x] = shell->env[y];
			x++;
			y++;
		}
	}
	new_env[x] = NULL;
	return (new_env);
}

void	unset(t_shell *shell, int i)
{
	char	*env_var;
	int		x;

	env_var = ft_strjoin(shell->tokens[i + 1], "=");
	x = 0;
	while (shell->env[x] != NULL)
	{
		if (ft_strncmp(shell->env[x], env_var, ft_strlen(env_var)) == 0)
			break ;
		x++;
	}
	// printf("index: %s\n", shell->env[x]);
	shell->env = new_env(shell, x);
	// x = 0;
	// while (shell->env[x])
	// {
	// 	printf("%s\n", shell->env[x]);
	// 	x++;
	// }
}

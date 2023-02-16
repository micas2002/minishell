/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:22:41 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/16 14:32:11 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	export(t_shell *shell, int i)
{
	char	**new_env;
	int		x;

	new_env = malloc(sizeof(char **) * (get_env_size(shell) + 1));
	x = 0;
	while (shell->env[x] != NULL)
	{
		new_env[x] = malloc(sizeof(char) * ft_strlen(shell->env[x]));
		new_env[x] = shell->env[x];
		x++;
	}
	new_env[x] = shell->tokens[++i];
	new_env[++x] = NULL;
	shell->env = new_env;
	//free_double_array(shell->env);
}

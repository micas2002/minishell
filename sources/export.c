/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:22:41 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/22 16:25:50 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_var_size(t_shell *shell, int i)
{
	int	len;

	len = 0;
	while(shell->tokens[i + 1][len] && shell->tokens[i + 1][len] != '=')
		len++;
	return (len);
}

void	export(t_shell *shell, int i)
{
	char	**new_env;
	int		ctrl_if_exist;
	int		x;
	int		y;

	new_env = malloc(sizeof(char *) * (get_env_size(shell->env) + 2));
	ctrl_if_exist = 0;
	x = 0;
	y = 0;
	while (shell->env[y] != NULL)
	{
		if (ft_strncmp(shell->tokens[i + 1], shell->env[y], get_var_size(shell ,i) + 1) == 0)
		{
			new_env[x] = ft_strdup(shell->tokens[i + 1]);
			ctrl_if_exist = 1;
		}
		else
			new_env[x] = ft_strdup(shell->env[y]);
		x++;
		y++;
	}
	if (ctrl_if_exist == 0)
	{
		new_env[x] = ft_strdup(shell->tokens[++i]);
		x++;
	}
	new_env[x] = NULL;
	free_double_array(shell->env);
	shell->env = new_env;
}

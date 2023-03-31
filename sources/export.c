/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:22:41 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/31 13:48:14 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(char **env)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	sort(char **names)
{
	char	*temp;
	int		i;
	int		j;
	int		n;

	n = get_env_size(names);
	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (strcmp(names[j], names[j + 1]) > 0)
			{
				temp = names[j];
				names[j] = names[j + 1];
				names[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	print_env(names);
}

char	**export_loop(t_shell *shell, t_token *token, int i, int x)
{
	char	**new_env;
	int		ctrl_if_exist;
	int		y;

	new_env = malloc(sizeof(char *) * (get_env_size(shell->env) + 2));
	ctrl_if_exist = 0;
	y = -1;
	while (shell->env[++y] != NULL)
	{
		if (ft_strncmp(token->args[i], shell->env[y],
				get_var_size(token->args[i]) + 1) == 0)
		{
			new_env[x++] = ft_strdup(token->args[i]);
			ctrl_if_exist = 1;
		}
		else
			new_env[x++] = ft_strdup(shell->env[y]);
	}
	if (ctrl_if_exist == 0)
		new_env[x++] = ft_strdup(token->args[++i]);
	new_env[x] = NULL;
	return (new_env);
}

void	export(t_shell *shell, t_token *token, int i, int x)
{
	char	**new_env;

	if (token->args[i + 1] == NULL)
	{
		new_env = dup_env(shell->env);
		sort(new_env);
		free_double_array(new_env);
		return ;
	}
	while (token->args[++i] != NULL)
	{
		if (check_token_chars(token->args[i]) == 0)
		{
			g_exit_value = error_handler(ERR_NO_VALID_IDENT,
					EXIT_FAILURE, token->args[i]);
			return ;
		}
		new_env = export_loop(shell, token, i, x);
		free_double_array(shell->env);
		shell->env = new_env;
	}
	g_exit_value = EXIT_SUCCESS;
}

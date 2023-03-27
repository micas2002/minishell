/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:22:41 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/27 16:21:50 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_token_chars(char *arg)
{
	int	x;

	x = 0;
	if (arg[x] == '=')
		return (0);
	while (arg[x] != '\0' && arg[x] != '=')
	{
		if (ft_isalnum(arg[x]) == 0)
			return (0);
		x++;
	}
	if (arg[x] == '\0')
		return (0);
	return (1);
}

int	get_var_size(char *arg)
{
	int	len;

	len = 0;
	while (arg[len] && arg[len] != '=')
		len++;
	return (len);
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

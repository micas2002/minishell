/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:49:12 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/28 15:53:16 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(t_shell *shell, char *str)
{
	char	*tmp;
	int		exit_val;
	int		x;

	exit_val = 0;
	x = 0;
	if (str[0] == '?')
	{
		if (str[1] == '$')
			str = ft_substr(str, 2, ft_strlen(str));
		else
			str = ft_substr(str, 1, ft_strlen(str));
		exit_val = 1;
	}
	tmp = ft_strjoin(str, "=");
	while (shell->env[x])
	{
		if (ft_strncmp(shell->env[x], tmp, ft_strlen(tmp)) == 0)
		{
			free(str);
			str = ft_substr(shell->env[x], ft_strlen(tmp), ft_strlen(shell->env[x]));
			if (exit_val == 1)
				str = ft_strjoin(ft_itoa(g_exit_value), str);
			free(tmp);
			return (str);
		}
		x++;
	}
	if (exit_val == 1)
		return (ft_strjoin(ft_itoa(g_exit_value), str));
	return ("");
}

void	enviroment(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		printf("%s\n", shell->env[i]);
		i++;
	}
}

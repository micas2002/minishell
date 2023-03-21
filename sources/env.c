/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:49:12 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/21 22:30:28 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_variable(t_shell *shell, char *str, int i)
{
	char	*tmp;
	int		x;
	int		size;

	x = 0;
	(void)i;
	tmp = ft_strjoin(str, "=");
	size = ft_strlen(tmp);
	while (shell->env[x])
	{
		if (ft_strncmp(shell->env[x], tmp, size) == 0)
		{
			free(tmp);
			tmp = ft_substr(shell->env[x], size, ft_strlen(shell->env[x]));
			return (tmp);
		}
		x++;
	}
	free(tmp);
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
	g_exit_value = EXIT_SUCCESS;
}

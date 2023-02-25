/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:49:12 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/25 12:37:52 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(t_shell *shell, char *str)
{
	int	x;

	x = 0;
	str = ft_strjoin(str, "=");
	while (shell->env[x])
	{
		if (ft_strncmp(shell->env[x], str, ft_strlen(str)) == 0)
			return (ft_substr(shell->env[x], ft_strlen(str) + 1, ft_strlen(shell->env[x])));
		x++;
	}
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

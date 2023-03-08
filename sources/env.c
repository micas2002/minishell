/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:49:12 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/27 16:45:46 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_var(t_shell *shell, char *str)
{
	char	*tmp;
	int		x;

	x = 0;
	tmp = ft_strjoin(str, "=");
	while (shell->env[x])
	{
		if (ft_strncmp(shell->env[x], tmp, ft_strlen(tmp)) == 0)
		{
			free(str);
			str = ft_substr(shell->env[x], ft_strlen(tmp), ft_strlen(shell->env[x]));
			free(tmp);
			return (str);
		}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:49:12 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/17 19:58:17 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_variable(t_shell *shell, char *str, int i)
{
	char	*tmp;
	int		x;

	x = 0;
	tmp = ft_strjoin(str, "=");
	while (shell->env[x])
	{
		if (ft_strncmp(shell->env[x], tmp, i) == 0)
		{
			free(str);
			str = ft_substr(shell->env[x], ft_strlen(tmp),
					ft_strlen(shell->env[x]));
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

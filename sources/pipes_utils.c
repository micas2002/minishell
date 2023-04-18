/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:06:43 by fialexan          #+#    #+#             */
/*   Updated: 2023/04/18 17:01:33 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_special_function(t_shell *shell, int iter)
{
	if (ft_strcmp(shell->tokens[iter]->args[0], "cd") == 0)
		cd(shell, shell->tokens[iter]);
	else if (ft_strcmp(shell->tokens[iter]->args[0], "export") == 0)
		export(shell, shell->tokens[iter], 0, 0);
	else if (ft_strcmp(shell->tokens[iter]->args[0], "unset") == 0)
		unset(shell, shell->tokens[iter], 1);
	else if (ft_strcmp(shell->tokens[iter]->args[0], "exit") == 0)
		exit_status();
	else
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:53:34 by fialexan          #+#    #+#             */
/*   Updated: 2023/03/20 18:35:03 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_shell *shell)
{
	int	iter;
	int	iter2;

	if (shell->tokens != NULL)
	{
		iter = 0;
		while (shell->tokens[iter] != NULL)
		{
			iter2 = 0;
			while (shell->tokens[iter]->args[iter2] != NULL)
			{
				free(shell->tokens[iter]->args[iter2]);
				iter2++;
			}
			free(shell->tokens[iter]->args);
			free(shell->tokens[iter]->str);
			free(shell->tokens[iter]);
			iter++;
		}
		free(shell->tokens);
	}
}

void	free_double_array(char **double_array)
{
	int	i;

	i = 0;
	if (double_array == NULL)
		return ;
	while (double_array[i])
	{
		free(double_array[i]);
		i++;
	}
	free(double_array);
}

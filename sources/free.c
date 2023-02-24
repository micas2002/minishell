/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:53:34 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/22 15:33:26 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_shell *shell)
{
	int	iter;

	if (shell->tokens != NULL)
	{
		iter = 0;
		while (shell->tokens[iter] != NULL)
		{
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

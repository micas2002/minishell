/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:53:34 by fialexan          #+#    #+#             */
/*   Updated: 2023/03/27 18:30:32 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_token(t_token *token)
{
	if (token != NULL)
	{
		free_double_array(token->args);
		free(token);
	}
}

void	free_all_tokens(t_shell *shell)
{
	int	iter;

	if (shell->tokens != NULL)
	{
		iter = 0;
		while (shell->tokens[iter] != NULL)
		{
			free_token(shell->tokens[iter]);
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

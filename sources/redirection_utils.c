/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:02:47 by filipe            #+#    #+#             */
/*   Updated: 2023/03/21 16:28:01 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirections(t_token *token)
{
	int	iter;

	iter = 0;
	while (token->args[iter])
	{
		if (ft_strcmp(token->args[iter], ">") == 0
			|| ft_strcmp(token->args[iter], ">>") == 0)
			return (1);
		else if (ft_strcmp(token->args[iter], "<") == 0
			|| ft_strcmp(token->args[iter], "<<") == 0)
			return (2);
		iter++;
	}
	return (0);
}

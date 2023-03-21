/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:20:51 by filipe            #+#    #+#             */
/*   Updated: 2023/03/21 16:29:22 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_redirections(t_token *token)
{
	if (check_redirections(token) == 1)
		handle_output_redirections(token);
	else if (check_redirections(token) == 2)
		handle_input_redirections(token);
}

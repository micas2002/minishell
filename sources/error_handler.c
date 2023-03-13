/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:16:25 by fialexan          #+#    #+#             */
/*   Updated: 2023/03/13 19:06:32 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_handler(int error_type, int exit_value)
{
	if (error_type == ERR_CMD_N_FOUND)
		printf("command not found\n");
	else if (error_type == ERR_CMD)
		printf("could not run command\n");
	else if (error_type == ERR_NO_FILE)
		printf("no such file or directory\n");
	else if (error_type == ERR_NO_PATH)
		printf("relative or absolute path needed\n");
	else if (error_type == ERR_UNCLOSED_QUOTES)
		printf("there are some unclosed quotes\n");
	return (exit_value);
}

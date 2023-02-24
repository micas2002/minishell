/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:16:25 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/24 12:49:25 by fialexan         ###   ########.fr       */
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
		printf("No such file or directory\n");
	else if (error_type == ERR_NO_PATH)
		printf("relative or absolute path needed\n");
	return (exit_value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:16:25 by fialexan          #+#    #+#             */
/*   Updated: 2023/03/20 17:47:05 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	error_handler(int error_type, int exit_value, char *error_var)
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
	else if (error_type == ERR_NO_VALID_IDENT)
		printf("export: `%s': not a valid identifier\n", error_var);
	return (exit_value);
}

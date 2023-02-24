/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:49:55 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/24 11:56:43 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_command_path(char *command_name)
{
	char	*command;

	command = NULL;
	command = getcwd(command, FILENAME_MAX);
	command = ft_strjoin(command, "/");
	command = ft_strjoin(command, command_name);
	return (command);
}

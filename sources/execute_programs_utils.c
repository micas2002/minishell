/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_programs_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:47:07 by fialexan          #+#    #+#             */
/*   Updated: 2023/02/28 16:51:15 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_command_path(char *command)
{
	char	*str;

	str = NULL;
	str = getcwd(str, FILENAME_MAX);
	str = ft_strjoin(str, "/");
	str = ft_strjoin(command, command);
	return (str);
}

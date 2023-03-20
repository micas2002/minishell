/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:28:46 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/20 17:42:35 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//implementation of pwd command. Gets current dir path with getcwd and prints
//it's output
void	pwd(void)
{
	char	*dir_path;

	dir_path = malloc(sizeof(char) * FILENAME_MAX);
	getcwd(dir_path, FILENAME_MAX);
	printf("%s\n", dir_path);
	free (dir_path);
	g_exit_value = EXIT_SUCCESS;
}

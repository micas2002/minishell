/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:28:46 by mibernar          #+#    #+#             */
/*   Updated: 2023/02/15 18:22:13 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//implementation of pwd command. Gets current dir path with getcwd and prints
//it's output
void	pwd(t_shell *shell)
{
	char	*dir_path;

	(void) shell;
	dir_path = malloc(sizeof(char) * FILENAME_MAX);
	getcwd(dir_path, FILENAME_MAX);
	printf("%s\n", dir_path);
	free (dir_path);
}

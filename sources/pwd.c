/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:28:46 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/19 13:58:48 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//implementation of pwd command. Gets current dir path with getcwd and prints
//it's output
void	pwd(t_sh *sh)
{
	char	*dir_path;

	(void) sh;
	dir_path = malloc(sizeof(char) * FILENAME_MAX);
	getcwd(dir_path, FILENAME_MAX);
	printf("%s\n", dir_path);
	free (dir_path);
}

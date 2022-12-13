/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:28:46 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/13 15:40:28 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(t_sh *sh)
{
	char	*dir_path;

	(void) sh;
	dir_path = malloc(sizeof(char) * 999);
	getcwd(dir_path, 999);
	printf("%s\n", dir_path);
	free (dir_path);
}

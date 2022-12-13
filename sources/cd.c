/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:48:53 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/13 16:05:55 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_sh *sh, int i)
{
	if (ft_strcmp(sh->tokens[i + 1], "..") == 1)
		chdir("..");
	else
	{
		if (chdir(sh->tokens[i + 1]) != 0)
			printf("No such file or directory\n");
	}
}

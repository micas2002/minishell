/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:48:53 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/14 18:18:53 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(t_sh *sh, int i)
{
	if (!sh->tokens[i + 1])
	{
		printf("relative or absolute path needed\n");
		return ;
	}
	if (ft_strcmp(sh->tokens[i + 1], "..") == 1)
		chdir("..");
	else
	{
		if (chdir(sh->tokens[i + 1]) != 0)
			printf("No such file or directory\n");
	}
}

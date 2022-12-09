/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:39:51 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/09 12:51:28 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHEL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft.h"

typedef struct s_minish
{
	int		nb_tokens;
	char	**tokens;
}t_minish;

//MAIN.C

//INPUT.C
void	parser(char *str, t_minish minish);

//LEXER.C
void	lexer(char *str, t_minish minish);

#endif

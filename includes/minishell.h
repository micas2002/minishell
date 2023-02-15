/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:39:51 by mibernar          #+#    #+#             */
/*   Updated: 2022/12/13 11:26:22 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft.h"

typedef struct s_sh
{
	int		nb_tokens;
	char	**tokens;
}t_sh;

//MAIN.C
void	terminal(char **env);

//INPUT.C
void	parser(char *str, t_sh *sh, char **env);

//LEXER.C
void	lexer(char *str, t_sh *sh, char **env);
int		s_quotes(char *str, int i, char **env);
int		d_quotes(char *str, int i, char **env);
int		other_input(char *str, int i);
int		operators(char *str, int i);
int		is_operator(char c);

//ECHO.C
void	echo(t_sh *sh, int i);

//PWD.C
void	pwd(t_sh *sh);

//CD.C
void	cd(t_sh *sh, int i);

//SIGNALS.C
void	handle_signals(int signum);

//EXECUTE_PROGRAMS.C
void	execute_program(t_sh *sh, int i, char **env);

//ENV.C
void	enviroment(char **env);

#endif

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
# include <sys/wait.h>
# include "./libft.h"

/**
 * @brief 
 * 
 * @param nb_tokens int
 * @param tokens char **
 */
typedef struct s_shell
{
	int		nb_tokens;
	char	**tokens;
	char	**env;
}	t_shell;

extern int		g_exit_value;

// Defines

//MAIN.C
void	terminal(char **env);

//INPUT.C
void	parser(char *str, t_shell *shell);

//LEXER.C
void	lexer(char *str, t_shell *shell);
int		s_quotes(char *str, int i, t_shell *shell);
int		d_quotes(char *str, int i, t_shell *shell);
int		other_input(char *str, int i);
int		operators(char *str, int i);
int		operators(char *str, int i);
int		is_operator(char c);

//ECHO.C
void	echo(t_shell *shell, int i);

//PWD.C
void	pwd(t_shell *shell);

//CD.C
void	cd(t_shell *shell, int i);

//SIGNALS.C
void	handle_signals(int signum);

//EXECUTE_PROGRAMS.C
void	execute_program(t_shell *shell, int i, char **env);

/**
 * @brief Receives all the enviroments variables, searhs for the 'PATH' variable
 *  and splits and the paths for the executables.
 * 
 * @param envp char **
 * @return char** 
 */
char	**get_command_paths(char **envp);

/**
 * @brief Get the path for the command given
 * 
 * @param paths char **
 * @param command_name char *
 * @return char* 
 */
char	*get_command(char **paths, char *command_name);

/**
 * @brief Runs the program with the given args
 * 
 * @param shell t_shell * 
 * @param i int
 * @param env char **
 */
void	run_program(t_shell *shell, int i, char **env);

/**
 * @brief Get the arguments for the command
 * 
 * @param shell 
 * @param i 
 * @return char** 
 */
char	**get_arguments(t_shell *shell, int i);

void	free_double_array(char **double_array);
//ENV.C
void	enviroment(t_shell *shell);

//UNSET.C
void	unset(t_shell *shell, int i);
char	**new_env(t_shell *shell, int i);
int		get_env_size(t_shell *shell);
void	free_double_array(char **double_array);

//EXPORT.C
void	export(t_shell *shell, int i);

#endif

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
	int		delimiters;
	char	**tokens;
	char	**env;
}	t_shell;

extern int		g_exit_value;

// Defines

//MAIN.C
void	terminal(t_shell shell);

//INPUT.C
/**
 * @brief 
 * 
 * @param str 
 * @param shell 
 */
void	parser(char *str, t_shell *shell);

/**
 * @brief
 * 
 * @param shell t_shell * 
 * @param i int
 */
void	commands(t_shell *shell, int i);

/**
 * @brief Checks if the tokens are valid
 * 
 * @param shell t_shell * 
 * @return int 
 */
int		check_tokens(t_shell *shell);

//LEXER.C

/**
 * @brief Lexer takes input and devides it into tokens. Skips any spaces
 * (if not between quotes) and checks if the argument is a sinlge quote, 
 * double quote, an operator(for example a pipe), or other kind of input.
 * Creates an array of size equal to the number os tokens and saves each 
 * token his own string.
 * 
 * @param str char *
 * @param shell t_shell *
 */
void	lexer(char *str, t_shell *shell);

//LEXER_UTILS.C

/**
 * @brief Saves the single quote token. If the quote is not closed, 
 * promts a message.
 * 
 * @param str char *
 * @param i int
 * @param shell t_shell
 * @return int - return the number of char between single quotes (included).
 */
int		s_quotes(char *str, int i, t_shell *shell);

/**
 * @brief Saves the double quote token. If the quote is not closed, 
 *  promts a message.
 * 
 * @param str char *
 * @param i int
 * @param shell t_shell * 
 * @return int - return the number of char between double quotes (included).
 */
int		d_quotes(char *str, int i, t_shell *shell);

/**
 * @brief Saves the input that isn't any of the other listed.
 * 
 * @param str char *
 * @param i int
 * @return int - return the number of chat between the 'i' until it finds a
 *  space or operator.
 */
int		other_input(char *str, int i);

/**
 * @brief Saves the operator token.
 * 
 * @param str char *
 * @param i int
 * @return int - return th number of char that are continuos operators.
 */
int		operators(char *str, int i);

/**
 * @brief Checks if the character is a metachar
 * 
 * @param c charr
 * @return int - returns 1 if is a metachar(operator) otherwise returns a 0.
 */
int		is_operator(char c);

//ECHO.C
void	echo(t_shell *shell, int i);

//PWD.C
void	pwd(t_shell *shell);

//CD.C
void	cd(t_shell *shell, int i);

//SIGNALS.C
void	receive_signal(void);
void	handle_signals(int signum);
void	receive_signal_i(void);
void	handle_signals_i(int signum);

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

//ENV.C
void	enviroment(t_shell *shell);

//UNSET.C
void	unset(t_shell *shell, int i);
char	**new_env(t_shell *shell, int i);
int		get_env_size(t_shell *shell);

//EXPORT.C
void	export(t_shell *shell, int i);

// Free

/**
 * @brief Frees all the tokens previously allocate for shell.
 * 
 * @param shell t_shell *
 */
void	free_tokens(t_shell *shell);

/**
 * @brief Receives a double array, frees all the arrays and them frees
 * the double array.
 * 
 * @param double_array char **
 */
void	free_double_array(char **double_array);

#endif

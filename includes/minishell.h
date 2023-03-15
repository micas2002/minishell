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
# include <fcntl.h>
# include <unistd.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include "./libft.h"

extern int		g_exit_value;

// Defines

# define ERR_CMD_N_FOUND 10
# define ERR_CMD 20
# define ERR_NO_FILE 30
# define ERR_NO_PATH 40
# define ERR_UNCLOSED_QUOTES 50

// Structs

typedef struct s_token
{
	char	*program_name;
	char	**arguments;
	int		num_redirections;
	char	**redirections;
	int		num_files;
	char	**files;
}	t_token;

typedef struct s_shell
{
	t_token	**tokens;
	int		num_tokens;
	char	**env;
}	t_shell;

//MAIN.C
void	terminal(t_shell shell);

//INPUT.C
void	commands(t_shell *shell, int i);
int		parser(char *str, t_shell *shell);

//INPUT_UTILS.C
char	**minishell_split(char const *s, char c, int i);
char	**minishell_split_loop(char const *s, char **str, int i, int x);
t_token	*create_token(char **str);
t_token	*get_redirection(char **str, int count, int iter);
t_token	**divide_tokens(char ***array);

// INPUT_UTILS2.C
int		get_double_array_size(char **str);
int		is_redir(char *str);
int		quote_checker(char *str);
int		quote_handler(char *str, int i, char c);
int		get_array_size(char *s, char c);

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
 * @return int - return the number of char between single quotes (included).
 */
int		s_quotes(char *str, int i);

/**
 * @brief Saves the double quote token. If the quote is not closed, 
 *  promts a message.
 * 
 * @param str char *
 * @param i int
 * @return int - return the number of char between double quotes (included).
 */
int		d_quotes(char *str, int i);

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
char	**get_paths(char **envp);

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

// EXECUTE_PROGRAM_UTILS

/**
 * @brief Get the absolute path for the command
 * 
 * @param command char *
 * @return char* 
 */
char	*get_command_path(char *command);

//ENV.C
void	enviroment(t_shell *shell);
char	*get_env_var(t_shell *shell, char *str);

//UNSET.C
void	unset(t_shell *shell, int i);
char	**new_env(t_shell *shell, int i);
int		get_env_size(char **env);

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

// ERROR_HANDLER

/**
 * @brief 
 * 
 * @param error_type int 
 * @param exit_value int
 * @return int 
 */
int		error_handler(int error_type, int exit_value);
//EXIT_STATUS.C
/**
 * @brief Returns the exit status of the last executed command
 * 
 */
int		exit_status(void);

#endif

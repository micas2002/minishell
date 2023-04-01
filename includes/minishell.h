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
# include <fcntl.h>
# include "./libft.h"

typedef struct s_token
{
	char	**args;
}	t_token;

/**
 * @brief 
 * 
 * @param nb_tokens int
 * @param tokens char **
 */
typedef struct s_shell
{
	int		unclosed_quotes;
	int		nb_tokens;
	t_token	**tokens;
	char	**env;
}	t_shell;

typedef struct s_pipe
{
	pid_t	*pid;
	int		pipe[2];
	int		fd;
}	t_pipe;

extern int	g_exit_value;

// Defines

# define ERR_CMD_N_FOUND 10
# define ERR_CMD 20
# define ERR_NO_FILE 30
# define ERR_NO_PATH 40
# define ERR_UNCLOSED_QUOTES 50
# define ERR_NO_VALID_IDENT 70
# define ERR_NO_SUCH_FILE_OR_DIR 80
# define ERR_SYNTAX 90

//MAIN.C
char	**dup_env(char **env);
void	terminal(t_shell shell);

//INPUT.C
void	commands(t_shell *shell, int i);
void	parser(char *str, t_shell *shell);
void	execute_parser_commands(t_shell *shell);

//INPUT_UTILS.C
int		divide_tokens_loop(char **cmds, int iter, t_token **tokens);
t_token	**divide_tokens(t_shell *shell, char **cmds);
int		get_array_size(char **str);

//DOLLAR.C
t_token	**handle_dollar(t_shell *shell, t_token **tokens);
char	*get_env_var(t_shell *shell, char *str, char *tmp);
int		check_var(char *str, int i);
int		check_after_var(char *str, int i);

//DOLLAR_UTILS.C
void	check_dollar(t_shell *shell, t_token **tokens, int iter);
char	*no_var_after(t_shell *shell, char *str, char *before_var, int x);
char	*join_final(char *var, char *after_var, char *before_var, char *tmp);

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
char	**lexer(char *s);
char	**lexer_loop(char const *s, char **str, int i, int x);
char	**unclosed_quote_found(char **str, int x);
int		get_lexer_array_size(char *s, char c);

//LEXER_UTILS.C

int		quote_handler(char *str, int i, char c);

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
char	*delete_quotes(char	*str, char current_quote, int iter, int str_iter);
int		check_option(char *str);
void	echo(t_token *token);

//PWD.C
void	pwd(void);

//CD.C
void	cd(t_shell *shell, t_token *token);

//SIGNALS.C
void	receive_signal(void);
void	handle_signals(int signum);
void	receive_signal_i(void);
void	handle_signals_i(int signum);

//EXECUTE_PROGRAMS.C
void	execute_program(t_shell *shell, int i);

/**
 * @brief Receives all the enviroments variables, searhs for the 'PATH' variable
 *  and splits and the paths for the executables.
 * 
 * @param envp char **
 * @return char** 
	while (env[i] != NULL)
		i++;
	return (i);
}

char	**new_env(t_shell *shell, int
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
 */
void	run_program(t_shell *shell, int i);

/**
 * @brief Get the arguments for the command
 * 
 * @param shell 
 * @param i 
 * @return char** 
 */
char	**get_arguments(t_shell *shell, int i);

//ENV.C
char	*get_env_variable(t_shell *shell, char *str, int i);
void	enviroment(t_shell *shell);

//UNSET.C
void	unset(t_shell *shell, t_token *token, int i);
char	**new_env(t_shell *shell, int i);
int		get_env_size(char **env);

//EXPORT.C
void	export(t_shell *shell, t_token *token, int i, int x);
char	**export_loop(t_shell *shell, t_token *token, int i, int x);
void	sort_env(char **env);
void	print_env(char **env);

//EXPORT_UTILS.C
int		check_token_chars(char *arg);
int		get_var_size(char *arg);

// Free

void	free_token(t_token *token);
/**
 * @brief Frees all the tokens previously allocate for shell.
 * 
 * @param shell t_shell *
 */
void	free_all_tokens(t_shell *shell);

/**
 * @brief Receives a double array, frees all the arrays and them frees
 * the double array.
 * 
 * @param double_array char **
 */
void	free_double_array(char **double_array);

//EXIT_STATUS.C
/**
 * @brief Returns the exit status of the last executed command
 * 
 */
int		exit_status(void);

//ERROR_HANDLER.C
int		error_handler(int error_type, int exit_value, char *error_var);

//REDIRECTION.C
void	handle_redirections(t_shell *shell, int i);
int		handle_output_redirections(t_token *token);
int		handle_input_redirections(t_token *token, int iter, int error, int fd);
int		here_doc(char *delim);

// REDIRECTION_UTILS.C
int		check_redirections(t_token *token);
t_token	*clean_redirections(t_token *token);
t_token	*clean_redirections_loop(t_token *new_token, t_token *token);

// PIPES.C
void	handle_pipes(t_shell *shell);
void	child_function(t_shell *shell, t_pipe *pipe, int iter);
void	child_input(t_shell *shell, t_pipe *pipe, int iter);
void	child_output(t_shell *shell, t_pipe *pipe, int iter);
void	wait_all_forks(t_shell *shell, t_pipe *pipe);

// PIPES_UTILS.C
int		is_special_function(t_shell *shell, int iter);

#endif

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

typedef struct s_token
{
	char	*str;
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
	int		nb_tokens;
	t_token	**tokens;
	char	**env;
}	t_shell;

extern int	g_exit_value;

// Defines

# define ERR_CMD_N_FOUND 10
# define ERR_CMD 20
# define ERR_NO_FILE 30
# define ERR_NO_PATH 40
# define ERR_UNCLOSED_QUOTES 50
# define ERR_NO_VALID_IDENT 70

//MAIN.C
void	terminal(t_shell shell);

//INPUT.C
void	commands(t_shell *shell, int i);
void	parser(char *str, t_shell *shell);
int		get_size_of_array(char **array);
t_token	**divide_tokens(char **cmds);

//INPUT_UTILS.C
char	*get_env_var(t_shell *shell, char *str);
t_token	**handle_dollar(t_shell *shell, t_token **tokens);
t_token	**divide_tokens(char **cmds);
int		get_array_size(char **str);

// INPUT_UTILS_2.C
int		check_redirections(t_token *token);

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
char	**lexer_loop(char const *s, char **str);
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
void	cd(t_token *token);

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
void	export(t_shell *shell, t_token *token, int i);

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

//EXIT_STATUS.C
/**
 * @brief Returns the exit status of the last executed command
 * 
 */
int		exit_status(void);

//ERROR_HANDLER.C
int		error_handler(int error_type, int exit_value, char *error_var);

#endif

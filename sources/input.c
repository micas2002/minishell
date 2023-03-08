/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:01:08 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/08 19:25:48 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "./libft.h"

//Checks if command is valid. If yes, gives paramaters to the respetcitve
//function and executes the command funciton. If not found, prints a message
void	commands(t_shell *shell, int i)
{
	if (ft_strcmp(shell->tokens[i], "echo") == 0)
		echo(shell, i);
	else if (ft_strcmp(shell->tokens[i], "cd") == 0)
		cd(shell, i);
	else if (ft_strcmp(shell->tokens[i], "pwd") == 0)
		pwd(shell);
	else if (ft_strcmp(shell->tokens[i], "export") == 0)
		export(shell, i);
	else if (ft_strcmp(shell->tokens[i], "unset") == 0)
		unset(shell, i);
	else if (ft_strcmp(shell->tokens[i], "env") == 0)
		enviroment(shell);
	else if (ft_strcmp(shell->tokens[i], "exit") == 0 && i == 0)
		exit (0);
	else if (ft_strcmp(shell->tokens[i], "$?") == 0 && i != 0)
		exit_status();
	else
		execute_program(shell, i, shell->env);
}

//Parser that devides the input into tokens using lexer and then check if the
//command given is valid or not. If valid, calls command function

void	parser(char *input, t_shell *shell)
{
	char	**tokens;
	
	tokens = divide_in_tokens(input);
	shell->tokens = divide_tokens(tokens);
}

char	**divide_in_tokens(char *input)
{
	return ft_split(input, '|');
}

t_token	create_token(char *str)
{
	int	redir_count;
	int	iter;
	
	redir_count = 0;
	iter = 0;
	while (str[iter])
	{
		
	}
}

t_token	*divide_tokens(char **array)
{
	int		iter;
	t_token	*tokens;

	iter = 0;
	while (array[iter] != NULL)
		iter++;
	tokens = malloc(sizeof(t_token) * (iter + 1));
	iter = 0;
	while (array[iter] != NULL)
	{
		tokens[iter] = create_token(array[iter]);
		iter++;
	}
}


char *my_strtok(char *str, char *delim)
{
    static char *backup_str; // start of the next search
    int				quotes;
    char		*ret_str;
    
    if(str == NULL)
        str = backup_str;
    if(str == NULL)
        return NULL;
    while (*str == ' ' && *str != '\0')
	str++;
	
	

//     while(1)
//     {
//         if(is_delim(*srcString, delim))
//         {
//             srcString++;
//             continue;
//         }
//         if(*srcString == '\0')
//         {
//             // we've reached the end of the string
//             return NULL; 
//         }
//         break;
//     }
    ret_str = str;
    
    while (*str != '\0')
    {
	if (*str == ' ' && quotes == 0)
	{
		
	}
    }
    while(1)
    {
        if(*srcString == '\0')
        {
            /*end of the input string and
            next exec will return NULL*/
            backup_string = srcString;
            return ret;
        }
        if(is_delim(*srcString, delim))
        {
            *srcString = '\0';
            backup_string = srcString + 1;
            return ret;
        }
        srcString++;
    }
}


coco "ola e adeus          amigos"adeus avos

coco
"ola e adeus          amigos"
adeus
avos

coco
"ola
e
adeus
amigos"adeus
avos


char **
coco 
"ola e adeus amigos


ft_strjoin(ola, ' ')
ftstrjoin(ola , e)
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:10 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/17 18:38:49 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of echo command. If the argument after command is the flag -n
//(which removes the newline), moves to the next argument. While there is valid
//input, it prints the message. If the -n flag exists, it doesn't print the
//newline

/*void	echo(t_token *tokens)
{
	char	*str;
	int		x;

	if (!tokens->args[1])
	{
		printf("\n");
		return ;
	}
	x = i + 1;
	if (ft_strcmp(tokens[i]->args[i + 1], "-n") == 0)
		i++;
	while (shell->tokens[i] && ft_strcmp(shell->tokens[i], "|") != 0)
	{
		if (shell->tokens[i][0] == '\"')
			str = ft_strtrim(shell->tokens[i], "\"");
		else
			str = ft_strtrim(shell->tokens[i], "\'");
		printf("%s", str);
		if (shell->tokens[i + 1] && is_operator(shell->tokens[i + 1][0]) == 0)
			printf(" ");
		i++;
		if (str)
			free(str);
	}
	if (ft_strcmp(shell->tokens[x], "-n") == 0)
		return ;
	printf("\n");
} */

char	*delete_quotes(char	*str)
{
	char	current_quote;
	char	*new_str;
	int		iter;
	int		str_iter;
	
	new_str = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (new_str == NULL)
		return (NULL);
	iter = 0;
	str_iter = 0;
	current_quote = ' ';
	while (str[iter] != '\0')
	{
		if ((str[iter] == '\'' || str[iter] == '\"'))
		{
			if (str[iter] != current_quote && current_quote != ' ')
			{
				new_str[str_iter] = str[iter];
				str_iter++;
			}
			else if (str[iter] == current_quote && current_quote != ' ')
				current_quote = ' ';
			else
				current_quote = str[iter];
		}
		else
		{
			new_str[str_iter] = str[iter];
			str_iter++;
		}
		iter++;
	}
	return (new_str);
}

int	check_option(char *str)
{
	int	iter;
	
	if (str[0] != '-')
		return (0);
	iter = 1;
	while (str[iter] != '\0')
	{
		if (str[iter] != 'n')
			return (0);
		iter++;
	}
	return (1);
}

void	echo(t_token *token)
{
	char	*str;
	int		iter;

	if (token->args[1] == NULL)
	{
		printf("\n");
		return ;
	}
	iter = 1;
	if (check_option(token->args[1]) == 1)
		iter++;
	while (token->args[iter] != NULL)
	{
		if (ft_srchr(token->args[iter], '\'') != NULL
				|| ft_strchr(token->args[iter], '\"') != NULL)
		{
			str = delete_quotes(token->args[iter]);
			printf("%s", str);
			free(str);
		}
		else
			printf("%s", token->args[iter]);
		if (token->args[iter + 1] != NULL)
			printf(" ");
		iter++;
	}
	if (check_option(token->args[1]) == 0)
		printf("\n");
}

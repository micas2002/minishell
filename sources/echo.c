/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 11:51:10 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/20 17:41:56 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Implementation of echo command. If the argument after command is the flag -n
//(which removes the newline), moves to the next argument. While there is valid
//input, it prints the message. If the -n flag exists, it doesn't print the
//newline

char	*delete_quotes(char	*str, char current_quote, int iter, int str_iter)
{
	char	*new_str;

	new_str = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (new_str == NULL)
		return (NULL);
	while (str[++iter] != '\0')
	{
		if ((str[iter] == '\'' || str[iter] == '\"'))
		{
			if (str[iter] != current_quote && current_quote != ' ')
				new_str[str_iter++] = str[iter];
			else if (str[iter] == current_quote && current_quote != ' ')
				current_quote = ' ';
			else
				current_quote = str[iter];
		}
		else
			new_str[str_iter++] = str[iter];
	}
	return (new_str);
}

int	check_option(char *str)
{
	int	iter;

	if (str == NULL)
		return (0);
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

	iter = 1;
	if (check_option(token->args[1]) == 1)
		iter++;
	while (token->args[iter] != NULL)
	{
		if (ft_strchr(token->args[iter], '\'') != NULL
			|| ft_strchr(token->args[iter], '\"') != NULL)
		{
			str = delete_quotes(token->args[iter], ' ', -1, 0);
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
	g_exit_value = EXIT_SUCCESS;
}

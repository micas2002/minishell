/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/15 15:11:55 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**minishell_split_loop(char const *s, char **str, int i, int x)
{
	int	begin;

	begin = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			i = quote_handler((char *)s, i + 1, '\'') + 1;
		if (s[i] == '\"')
			i = quote_handler((char *)s, i + 1, '\"') + 1;
		if (s[i] == ' ')
		{
			str[x] = ft_substr((char *)s, begin, i - begin);
			i++;
			begin = i;
			x++;
		}
		else
			i++;
	}
	str[x] = ft_substr((char *)s, begin, i - begin);
	str[++x] = NULL;
	return (str);
}

char	**minishell_split(char const *s, char c, int i)
{
	int		array_size;
	char	**str;

	if (!s)
		return (NULL);
	array_size = get_array_size((char *)s, c);
	if (array_size == -1)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (!str)
		return (NULL);
	str = minishell_split_loop(s, str, 0, 0);
	return (minishell_split_loop(s, str, 0, 0));
}

t_token	**divide_tokens(char ***array)
{
	int		iter;
	t_token	**tokens;

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
	tokens[iter] = NULL;
	return (tokens);
}

t_token	*create_token(char **str)
{
	t_token	*token;
	int		iter;
	int		command;

	token = get_redirection(str, 0, -1);
	iter = 0;
	command = 0;
	while (str[iter] != NULL)
		iter++;
	token->arguments = malloc(sizeof(char *)
			* (iter - (token->num_files * 2) + 1));
	iter = 0;
	while (str[iter] != NULL)
	{
		if (is_redir(str[iter]) == 1 && str[iter + 1] != NULL)
			iter += 2;
		else if (is_redir(str[iter]) == 1 && str[iter + 1] == NULL)
			return (NULL);
		else
		{
			if (command == 0)
				token->program_name = ft_strdup(str[iter]);
			token->arguments[command] = ft_strdup(str[iter]);
			command++;
			iter++;
		}
	}
	return (token);
}

t_token	*get_redirection(char **str, int count, int iter)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	while (str[++iter] != NULL)
	{
		if (is_redir(str[iter]) == 1)
			count++;
	}
	token->redirections = malloc(sizeof(char *) * (count + 1));
	token->files = malloc(sizeof(char *) * (count + 1));
	token->num_redirections = count;
	token->num_files = count;
	count = 0;
	iter = -1;
	while (str[++iter] != NULL)
	{
		if (is_redir(str[iter]) == 1)
		{
			token->redirections[count] = str[iter];
			token->files[count] = str[iter + 1];
			count++;
		}
	}
	token->redirections[count] = NULL;
	token->files[count] = NULL;
	return (token);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mibernar <mibernar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:27:33 by mibernar          #+#    #+#             */
/*   Updated: 2023/03/15 17:42:17 by mibernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

{
	t_token	**tokens;
	int		iter;
	
	iter = 0;
	while (cmds[iter] != NULL)
		iter++;
	tokens = (t_token **)malloc(sizeof(t_token *) * (iter + 1));
	iter = 0;
	while (cmds[iter] != NULL)
	{
		tokens[iter] = (t_token *)malloc(sizeof(t_token));
		tokens[iter]->args = lexer(cmds[iter], ' ');
		iter++;
	}
	return (tokens);
}

		tokenstokens[iter]->cmd = 		iter+to		tokens[iter]->next = NULL
	tke	tokens[iter] = NULL;
strft_str		tokens[iter]->str = ft_strdup(cmds[iter]);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:55:40 by fialexan          #+#    #+#             */
/*   Updated: 2022/10/28 12:00:59 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	get_array_size(char *s, char c)
{
	int	i;
	int	control;
	int	size;

	i = 0;
	control = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && control == 0)
		{
			control = 1;
			size++;
		}
		else if (s[i] == c)
			control = 0;
		i++;
	}
	return (size);
}

static char	*get_str(char *s, int begin, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!str)
		return (NULL);
	while (begin < end)
	{
		str[i] = s[begin];
		i++;
		begin++;
	}
	str[i] = '\0';
	return (str);
}

static int	get_end(char *s, int end, char c)
{
	while (s[end] != c && s[end] != '\0')
		end++;
	return (end);
}

static int	get_begin(char *s, int begin, char c)
{
	while (s[begin] == c && s[begin] != '\0')
		begin++;
	return (begin);
}

char	**ft_split(char const *s, char c)
{
	int		array_size;
	char	**str;
	int		i;
	int		begin;
	int		end;

	if (!s)
		return (NULL);
	array_size = get_array_size((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (!str)
		return (NULL);
	i = 0;
	end = 0;
	begin = 0;
	while (i < array_size)
	{
		begin = get_begin((char *)s, end, c);
		end = get_end((char *)s, begin, c);
		str[i] = get_str((char *)s, begin, end);
		i++;
	}
	str[i] = NULL;
	return (str);
}

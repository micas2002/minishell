/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 12:26:23 by fialexan          #+#    #+#             */
/*   Updated: 2022/11/30 14:53:43 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_read(fd);
	tmp = str;
	str = ft_strjoin(tmp, line);
	if (line)
		free(line);
	if (tmp)
		free(tmp);
	if (!str)
		return (NULL);
	if (ft_findchar(str, '\n') == -1)
		str = find_new_line(str, fd);
	tmp = ft_strdup(str);
	tmp = get_before_nl(tmp);
	str = get_after_nl(str);
	return (tmp);
}

char	*find_new_line(char *str, int fd)
{
	char	*tmp1;
	char	*tmp2;

	while (ft_findchar(str, '\n') == -1)
	{
		tmp1 = str;
		tmp2 = ft_read(fd);
		if (!tmp2)
			return (str);
		str = ft_strjoin(tmp1, tmp2);
		if (tmp1)
			free(tmp1);
		if (tmp2)
			free(tmp2);
	}
	return (str);
}

char	*get_before_nl(char *s)
{
	char	*str;
	int		i;
	int		index;

	index = ft_findchar(s, '\n');
	if (index == -1)
		return (s);
	str = malloc(sizeof(char) * (index + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < index)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

char	*get_after_nl(char *s)
{
	char	*str;
	int		size;
	int		start;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	start = 0;
	while (s[start] && s[start] != '\n')
		start++;
	if (s[start] == '\n')
		start++;
	str = ft_substr(s, start, (size - start));
	if (str[0] == '\0')
	{
		free(str);
		free(s);
		return (NULL);
	}
	free(s);
	return (str);
}

char	*ft_read(int fd)
{
	char	*str;
	size_t	size_read;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (str == NULL)
		return (NULL);
	size_read = read(fd, str, BUFFER_SIZE);
	if (size_read <= 0 || size_read > BUFFER_SIZE)
	{
		free(str);
		return (NULL);
	}
	str[size_read] = '\0';
	return (str);
}

#include "minishell.h"

int	quote_handler(char *str, int i, char c)
{
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

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
		if (s[i] == '\'')
			i = quote_handler(s, i, '\'');
		if (s[i] == '\"')
			i = quote_handler(s, i, '\"');
		if (i == -1)
			return (-1);
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

char	**minishell_split_loop(char const *s, char c, char **str)
{
	int	begin;
	int	x;
	int	i;

	begin = 0;
	i = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'')
			i = quote_handler((char *)s, i + 1, '\'') + 1;
		if (s[i] == '\"')
			i = quote_handler((char *)s, i + 1, '\"') + 1;
		if (s[i] == ' ')
		{
			str[x] = ft_substr((char *)s, begin, i - begin);
			begin = ++i;
			x++;
		}
		else
			i++;
	}
	str[x] = ft_substr((char *)s, begin, i - begin);
	str[++x] = NULL;
	return (str);
}

char	**minishell_split(char const *s, char c, int i, int x)
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
	str = minishell_split_loop(s, c, str);
	return (str);
}

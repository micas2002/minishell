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

char	**minishell_split(char const *s, char c)
{
	int		array_size;
	char	**str;
	int		x;
	int		i;
	int		begin;

	if (!s)
		return (NULL);
	array_size = get_array_size((char *)s, c);
	if (array_size == -1)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (array_size + 1));
	if (!str)
		return (NULL);
	x = 0;
	i = 0;
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
			printf("%s\n", str[x]);
			i++;
			begin = i;
			x++;
		}
		else
			i++;
	}
	str[x] = ft_substr((char *)s, begin, i - begin);
	printf("%s\n", str[x]);
	str[++x] = NULL;
	return (str);
}

int	main()
{
	char	str[] = "Ola amigos 'ja estamos'aqui chegou";
	char	**array;
	int		i = 0;

	printf("og:\n%s\nnew:\n", str);
	array = minishell_split(str, ' ');
	// while (array[i] != NULL)
	// {
	// 	printf("%s\n", array[i]);
	// 	i++;
	// }
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:12:04 by fialexan          #+#    #+#             */
/*   Updated: 2022/10/28 12:00:59 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*str;

	if (!s1)
		return (NULL);
	begin = 0;
	end = ft_strlen((char *)s1);
	while (*(char *)(s1 + begin) != '\0' &&
		ft_check(*(char*)(s1 + begin), (char*)set))
		begin++;
	while (end > begin && ft_check(*(char *)(s1 + end - 1), (char *)set))
		end--;
	str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (char *)(s1 + begin), end - begin + 1);
	return (str);
}

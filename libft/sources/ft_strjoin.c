/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:03:22 by fialexan          #+#    #+#             */
/*   Updated: 2022/11/30 17:03:50 by fialexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	e;
	char	*str;

	i = 0;
	e = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(char)
			* (ft_strlen((char *)s1) + ft_strlen((char *)s2)) + 1);
	if (!str)
		return (NULL);
	while (s1 && *(char *)(s1 + i) != '\0')
	{
		str[i] = *(char *)(s1 + i);
		i++;
	}
	while (s2 && *(char *)(s2 + e) != '\0')
	{
		str[i + e] = *(char *)(s2 + e);
		e++;
	}
	str[i + e] = '\0';
	return (str);
}

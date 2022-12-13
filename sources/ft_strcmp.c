/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:40:02 by miguel            #+#    #+#             */
/*   Updated: 2022/06/22 12:45:28 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	x;

	x = 0;
	while ((unsigned char)s1[x] == (unsigned char)s2[x]
		&& ((unsigned char)s1[x] != '\0'
			&& (unsigned char)s2[x] != '\0'))
		x++;
	if ((unsigned char)s1[x] != (unsigned char)s2[x])
		return (0);
	return (1);
}

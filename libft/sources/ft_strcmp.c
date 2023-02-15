/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fialexan <fialexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:40:02 by miguel            #+#    #+#             */
/*   Updated: 2023/02/15 19:13:43 by fialexan         ###   ########.fr       */
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
	return ((unsigned char)s1[x] - (unsigned char)s2[x]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:05:01 by tyou              #+#    #+#             */
/*   Updated: 2021/04/13 16:10:16 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t				i;
	const unsigned char	*s_1;
	const unsigned char	*s_2;

	i = 0;
	s_1 = (unsigned char *)s1;
	s_2 = (unsigned char *)s2;
	while (s_1[i] && s_2[i] && s_1[i] && s_2[i])
	{
		if (s_1[i] != s_2[i])
			return (s_1[i] - s_2[i]);
		i++;
	}
	if (s_1[i] != s_2[i])
		return (s_1[i] - s_2[i]);
	return (0);
}

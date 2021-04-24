/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 20:40:03 by tyou              #+#    #+#             */
/*   Updated: 2021/01/21 20:47:46 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size1;
	int		size2;
	int		i;
	char	*rt;

	if (s1 && s2)
	{
		i = 0;
		size1 = ft_strlen(s1);
		size2 = ft_strlen(s2);
		if (!(rt = malloc(size1 + size2 + 1)))
			return (NULL);
		while (i < size1)
		{
			rt[i] = s1[i];
			i++;
		}
		i = -1;
		while (++i < size2)
			rt[size1 + i] = s2[i];
		rt[size1 + i] = '\0';
		return (rt);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*rt;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	if (!(rt = (char*)malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		rt[i] = s1[i];
		i++;
	}
	rt[i] = '\0';
	return (rt);
}

char	*ft_strchr(const char *s, int c)
{
	char *tmp;

	tmp = (char*)s;
	while (*tmp != c)
	{
		if (!*tmp)
			return (NULL);
		tmp++;
	}
	return (tmp);
}

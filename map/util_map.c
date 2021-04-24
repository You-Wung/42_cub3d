/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 17:34:22 by tyou              #+#    #+#             */
/*   Updated: 2021/04/24 19:55:50 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int			sizeofarray(int *i)
{
	int	a;

	a = 0;
	while (i[a])
		a++;
	return (a);
}

void        re_malloc(char **buf, int size, int *line_size)
{
	char    *fre;
	int     i;
	int     j;

	i = -1;
	while (buf[++i] && i < sizeofarray(line_size))
	{
		fre = buf[i];
		buf[i] = malloc(size + 1);
		buf[i][size] = 0;
		j = -1;
		while (++j < size)
			buf[i][j] = ' ';
		j = -1;
		while (++j < line_size[i])
			if (fre[j])
				buf[i][j] = fre[j];
		free(fre);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:08:21 by tyou              #+#    #+#             */
/*   Updated: 2021/04/26 17:34:07 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "map.h"

static void buf_free(char **buf)
{
	int		i;

	i = -1;
	while (++i < 256)
		if(buf[i] != NULL)
			free(buf[i]);
}

static void	find_direction(char **buf, t_info *info)
{
	int i;
	int j;

	i = 0;
	while (buf[i])
	{
		j = 0;
		while (buf[i][j])
		{
			if (buf[i][j] == 'N' || buf[i][j] == 'S'
					|| buf[i][j] == 'E' || buf[i][j] == 'W')
			{
				if (info->direct != 0)
					free_exit(info, 1);
				info->direct = buf[i][j];
				info->posx = j + 0.5;
				info->posy = i + 0.5;
				buf[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	if (info->direct == 0)
		free_exit(info, 2);
}

static char	**put_index_in(char *str, int line)
{
	static char	*buf[256];

	if (line == 8888)
		return (buf);
	buf[line] = str;
	return (buf);
}

static int	**put_index_in2(char **buf, int line, int *size)
{
	int **map;
	int i;
	int j;

	map = (int **)malloc(sizeof(int *) * line + 1);
	i = -1;
	while (++i < line)
		map[i] = (int *)malloc(sizeof(int) * size[i]);
	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < size[i] && buf[i][j])
		{
			if (buf[i][j] == ' ')
				map[i][j] = 0;
			else
				map[i][j] = buf[i][j] - '0';
			j++;
		}
		i++;
	}
	map[line] = NULL;
	return (map);
}

int			**read_map(int fd, t_info *info)
{
	int		**map;
	char	*str;
	int		i;

	i = 0;
	while (get_next_line(fd, &str))
	{
		if (!(ft_strchr(str, '0')) && !(ft_strchr(str, '1')))
		{
			free(str);
			continue ;
		}
		info->size[i] = ft_strlen(str);
		put_index_in(str, i++);
	}
	free(str);
	find_direction(put_index_in(0, 8888), info);
	check_map(put_index_in(0, 8888), info);
	map = put_index_in2(put_index_in(0, 8888), i, info->size);
	buf_free(put_index_in(0, 8888));
	return (map);
}

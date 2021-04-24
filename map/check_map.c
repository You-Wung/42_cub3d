/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:31:18 by tyou              #+#    #+#             */
/*   Updated: 2021/04/24 19:33:43 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "../cub3d.h"

static void		testmap_free(char **map)
{
	int	i;

	i = -1;
	while (++i < 256)
		free(map[i]);
	free(map);
}

static int		checking(char **map, int x, int y)
{
	const int	dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
	const int	diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};
	int			i;

	// printf("x: %d\ty: %d\n",x,y);
	//     for (int i=0; i<20; i++)
    // {
    //     for (int y=0; y<40; y++)
    //         printf("%c",map[i][y]);
    //     printf("\n");
    // }

	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == ' ')
		return (0);
	map[y][x] = 'x';
	i = -1;
	while (++i < 8)
		if (checking(map, x + dirx[i], y + diry[i]) == 0)
			return (0);
	return (1);
}

static char		**init_map(char **map, int *size)
{
	int		x;
	int		y;
	char	**test;

	test = (char **)malloc(sizeof(char *) * 256);
	test[255] = 0;
	y = -1;
	while (++y < 255)
	{
		test[y] = malloc(256);
		test[y][255] = 0;
		x = -1;
		while (++x < 255)
			test[y][x] = ' ';
	}
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			test[y + 1][x + 1] = map[y][x];
	}
	return (test);
}

int				check_map(char **map, int *size, t_info *info)
{
	int		x;
	int		y;
	char	**test_map;

	test_map = init_map(map, size);
	y = -1;
	while (test_map[++y])
	{
		x = -1;
		while (test_map[y][++x])
			if (test_map[y][x] == '0')
			{
				if (checking(test_map, x, y) == 0)
					free_exit(info, 10);
			}
	}
	testmap_free(test_map);
	return (1);
}

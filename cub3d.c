/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:15:58 by tyou              #+#    #+#             */
/*   Updated: 2021/04/24 16:48:20 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_screensize(t_info *info)
{
	int		y;
	int		x;

	mlx_get_screen_size(info->mlx, &x, &y);
	if (info->width > x)
		info->width = x - 1;
	if (info->height > y)
		info->height = y - 1;
}

static int		set_gnl(t_info *info, char *argv)
{
	int		fd;
	char	*str;
	char	*fre;

	info->floor = -1;
	info->ceilling = -1;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		free_exit(info, 1);
	while (get_next_line(fd, &str))
	{
		fre = str;
		info->sign = 0;
		skip_empty_char(&str, 0);
		if (!(sort_gnl(&str, info)))
			break ;
		free(fre);
	}
	check_screensize(info);
	return (fd);
}

static void		calc(t_info *info)
{
	info->zbuffer = malloc(sizeof(double) * info->width);
	floor_ceilling(info);
	wall(info);
	sprite(info);
}

static int		main_loop(t_info *info)
{
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_info	info;

	ft_memset(&info, 0, sizeof(t_info));
	info.mlx = mlx_init();
	fd = set_gnl(&info, argv[1]);
	info.map = read_map(fd, &info);
	set_up(&info);
	info.win = mlx_new_window(info.mlx, info.width, info.height, "cub3d");
	info.img.img = mlx_new_image(info.mlx, info.width, info.height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img,
							&info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	if (argc == 3 && !ft_strcmp(argv[2], "--save"))
	{
		main_loop(&info);
		save_bmp(&info);
	}
	else if (argc >= 3)
		exit(printf("Error\n"));
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 0, &key_release, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 0, &leave, &info);
	mlx_loop(info.mlx);
}

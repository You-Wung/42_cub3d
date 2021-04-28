/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:32:58 by tyou              #+#    #+#             */
/*   Updated: 2021/04/28 15:24:06 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_memory(int ***pointer, int height, int width)
{
	int i;
	int j;

	i = 0;
	j = 0;
	*pointer = (int **)malloc(sizeof(int *) * height);
	while (i < height)
	{
		(*pointer)[i] = (int *)malloc(sizeof(int) * width);
		i++;
	}
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			(*pointer)[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	set_up(t_info *info)
{
	if (info->direct == 'S')
	{
		info->diry = 1.0;
		info->planex = 0.5;
	}
	else if (info->direct == 'E')
	{
		info->dirx = 1.0;
		info->planey = -0.5;
	}
	else if (info->direct == 'N')
	{
		info->diry = -1.0;
		info->planex = -0.5;
	}
	else if (info->direct == 'E')
	{
		info->dirx = -1.0;
		info->planey = 0.5;
	}
	setup_memory(&info->buf, info->height, info->width);
	setup_memory(&info->texture, 5, TEXHEIGHT * TEXWIDTH);
	load_texture(info);
}

void	draw(t_info *info)
{
	int		y;
	int		x;

	y = 0;
	while (y < info->height)
	{
		x = 0;
		while (x < info->width)
		{
			info->img.data[y * info->width +
				(info->width - x)] = info->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int y;
	int x;

	y = 0;
	x = 0;
	img->img = mlx_xpm_file_to_image(info->mlx, path,
									&img->img_width, &img->img_height);
	if (img->img == 0)
		free_exit(info, 1);
	img->data = (int *)mlx_get_data_addr(img->img,
									&img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] =
					img->data[img->img_width * y + (img->img_width - x)];
			x++;
		}
		y++;
	}
	mlx_destroy_image(info->mlx, img->img);
}

void	load_texture(t_info *info)
{
	t_img	img;

	load_image(info, info->texture[0], info->north, &info->img);
	load_image(info, info->texture[1], info->south, &info->img);
	load_image(info, info->texture[2], info->east, &info->img);
	load_image(info, info->texture[3], info->west, &info->img);
	load_image(info, info->texture[4], info->s, &info->img);
}

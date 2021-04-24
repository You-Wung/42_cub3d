/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:07:01 by tyou              #+#    #+#             */
/*   Updated: 2021/04/24 20:08:14 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	wall_init(t_info *info, t_wall *wall, int x)
{
	wall->camerax = 2 * x / (double)info->width - 1;
	wall->raydirx = info->dirx + info->planex * wall->camerax;
	wall->raydiry = info->diry + info->planey * wall->camerax;
	wall->mapx = (int)info->posx;
	wall->mapy = (int)info->posy;
	wall->deltadistx = fabs(1 / wall->raydirx);
	wall->deltadisty = fabs(1 / wall->raydiry);
	wall->hit = 0;
}

void	sidedist(t_info *info, t_wall *wall)
{
	if (wall->raydirx < 0)
	{
		wall->stepx = -1;
		wall->sidedistx = (info->posx - wall->mapx) * wall->deltadistx;
	}
	else
	{
		wall->stepx = 1;
		wall->sidedistx = (wall->mapx + 1.0 - info->posx) * wall->deltadistx;
	}
	if (wall->raydiry < 0)
	{
		wall->stepy = -1;
		wall->sidedisty = (info->posy - wall->mapy) * wall->deltadisty;
	}
	else
	{
		wall->stepy = 1;
		wall->sidedisty = (wall->mapy + 1.0 - info->posy) * wall->deltadisty;
	}
}

void	texture_number(t_info *info, t_wall *wall)
{
	if (wall->side == 0)
	{
		if (wall->raydirx < 0)
			wall->texnum = 3;
		else
			wall->texnum = 2;
	}
	else
	{
		if (wall->raydiry > 0)
			wall->texnum = 1;
		else
			wall->texnum = 0;
	}
}

void	dda(t_info *info, t_wall *wall)
{
	while (wall->hit == 0)
	{
		if (wall->sidedistx < wall->sidedisty)
		{
			wall->sidedistx += wall->deltadistx;
			wall->mapx += wall->stepx;
			wall->side = 0;
		}
		else
		{
			wall->sidedisty += wall->deltadisty;
			wall->mapy += wall->stepy;
			wall->side = 1;
		}
		// printf("y: %d x: %d = %d\n",wall->mapy, wall->mapx,info->map[wall->mapy][wall->mapx]);
		if (info->map[wall->mapy][wall->mapx] == 1)
			wall->hit = 1;
	}
	texture_number(info, wall);
}

void	wall(t_info *info)
{
	int		x;
	int		y;
	t_wall	wall;

	x = 0;
	while (x < info->width)
	{
		wall_init(info, &wall, x);
		sidedist(info, &wall);
		dda(info, &wall);
		perp(info, &wall);
		draw1(info, &wall);
		draw2(info, &wall, x);
		x++;
	}
}

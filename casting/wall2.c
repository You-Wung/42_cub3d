/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 22:46:03 by tyou              #+#    #+#             */
/*   Updated: 2021/04/26 17:09:56 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	perp(t_info *info, t_wall *wall)
{
	if (wall->side == 0)
		wall->perpwalldist = (wall->mapx - info->posx
									+ (1 - wall->stepx) / 2) / wall->raydirx;
	else
		wall->perpwalldist = (wall->mapy - info->posy
									+ (1 - wall->stepy) / 2) / wall->raydiry;
}

void	draw1(t_info *info, t_wall *wall)
{
	wall->lineheight = (int)(info->height / wall->perpwalldist);
	wall->drawstart = -wall->lineheight / 2 + info->height / 2;
	if (wall->drawstart < 0)
		wall->drawstart = 0;
	wall->drawend = wall->lineheight / 2 + info->height / 2;
	if (wall->drawend >= info->height)
		wall->drawend = info->height - 1;
	if (wall->side == 0)
		wall->wallx = info->posy + wall->perpwalldist * wall->raydiry;
	else
		wall->wallx = info->posx + wall->perpwalldist * wall->raydirx;
	wall->wallx -= (int)wall->wallx;
	wall->texx = (int)(wall->wallx * (double)TEXWIDTH);
}

void	draw2(t_info *info, t_wall *wall, int x)
{
	int y;

	wall->step = (double)TEXHEIGHT / wall->lineheight;
	wall->texpos = (wall->drawstart - info->height / 2
								+ wall->lineheight / 2) * wall->step;
	y = wall->drawstart;
	while (y < wall->drawend)
	{
		wall->texy = (int)wall->texpos;
		wall->texpos += wall->step;
		info->buf[y][x] = info->texture[wall->texnum]
									[TEXHEIGHT * wall->texy + wall->texx];
		y++;
	}
	info->zbuffer[x] = wall->perpwalldist;
}

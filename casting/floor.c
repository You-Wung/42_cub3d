/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 00:39:02 by tyou              #+#    #+#             */
/*   Updated: 2021/04/09 00:08:59 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floor_ceilling(t_info *info)
{
	int		y;
	int		x;

	y = info->height / 2 + 1;
	x = 0;
	while (y < info->height)
	{
		x = 0;
		while (++x < info->width)
		{
			info->buf[y][x] = info->ceilling;
			info->buf[info->height - y - 1][x] = info->floor;
		}
		y++;
	}
}

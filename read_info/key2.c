/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:31:08 by tyou              #+#    #+#             */
/*   Updated: 2021/04/26 01:11:17 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_rot_left(t_info *info)
{
	double olddirx;
	double oldplanex;

	if (info->key_left)
	{
		olddirx = info->dirx;
		info->dirx = info->dirx * cos(-RS)
										- info->diry * sin(-RS);
		info->diry = olddirx * sin(-RS) + info->diry * cos(-RS);
		oldplanex = info->planex;
		info->planex = info->planex * cos(-RS)
										- info->planey * sin(-RS);
		info->planey = oldplanex * sin(-RS)
										+ info->planey * cos(-RS);
	}
}

void	key_rot_right(t_info *info)
{
	double olddirx;
	double oldplanex;

	if (info->key_right)
	{
		olddirx = info->dirx;
		info->dirx = info->dirx * cos(RS) - info->diry * sin(RS);
		info->diry = olddirx * sin(RS) + info->diry * cos(RS);
		oldplanex = info->planex;
		info->planex = info->planex * cos(RS)
										- info->planey * sin(RS);
		info->planey = oldplanex * sin(RS)
										+ info->planey * cos(RS);
	}
}

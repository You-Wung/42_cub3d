/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:31:08 by tyou              #+#    #+#             */
/*   Updated: 2021/04/21 14:08:38 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	key_rot_d(t_info *info)
{
	double olddirx;
	double oldplanex;

	if (info->key_d)
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

void	key_rot_a(t_info *info)
{
	double olddirx;
	double oldplanex;

	if (info->key_a)
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

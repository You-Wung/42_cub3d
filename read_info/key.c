/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:31:08 by tyou              #+#    #+#             */
/*   Updated: 2021/04/21 14:08:39 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		leave(int key, t_info *info)
{
	free_exit(info, 1);
	return (0);
}

int		key_press(int key, t_info *info)
{
	if (key == K_ESC)
		free_exit(info, 0);
	else if (key == KEY_W)
		info->key_w = 1;
	else if (key == KEY_A)
		info->key_a = 1;
	else if (key == KEY_S)
		info->key_s = 1;
	else if (key == KEY_D)
		info->key_d = 1;
	return (0);
}

int		key_release(int key, t_info *info)
{
	if (key == K_ESC)
		free_exit(info, 0);
	else if (key == KEY_W)
		info->key_w = 0;
	else if (key == KEY_A)
		info->key_a = 0;
	else if (key == KEY_S)
		info->key_s = 0;
	else if (key == KEY_D)
		info->key_d = 0;
	return (0);
}

void	key_update(t_info *info)
{
	if (info->key_w)
	{
		if (1 != info->map[(int)info->posy]
								[(int)(info->posx + info->dirx * MS)])
			info->posx += info->dirx * MS;
		if (1 != info->map[(int)(info->posy + info->diry
								* MS)][(int)(info->posx)])
			info->posy += info->diry * MS;
	}
	if (info->key_s)
	{
		if (1 != info->map[(int)(info->posy)]
								[(int)(info->posx - info->dirx * MS)])
			info->posx -= info->dirx * MS;
		if (1 != info->map[(int)(info->posy - info->diry
								* MS)][(int)(info->posx)])
			info->posy -= info->diry * MS;
	}
	if (info->key_d)
		key_rot_d(info);
	if (info->key_a)
		key_rot_a(info);
	if (info->key_esc)
		free_exit(info, 0);
}
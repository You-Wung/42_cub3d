/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:39:29 by tyou              #+#    #+#             */
/*   Updated: 2021/04/21 14:08:37 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		read_sprite(t_info *info)
{
	int		i;
	int		j;
	int		a;

	a = 0;
	i = 0;
	j = 0;
	while (info->map[i])
	{
		j = 0;
		while (j < info->size[i])
		{
			if (info->map[i][j] == 2)
			{
				info->sprite[a][0] = i + 0.5;
				info->sprite[a][1] = j + 0.5;
				a++;
			}
			j++;
		}
		i++;
	}
	return (a);
}

void	sort_order(int temp[][2], int amount)
{
	int		i;
	int		j;
	int		sub[2];

	i = 0;
	while (i < amount)
	{
		j = 0;
		while (j < amount - 1)
		{
			if (temp[j][0] > temp[j + 1][0])
			{
				sub[0] = temp[j][0];
				sub[1] = temp[j][1];
				temp[j][0] = temp[j + 1][0];
				temp[j][1] = temp[j + 1][1];
				temp[j + 1][0] = sub[0];
				temp[j + 1][1] = sub[1];
			}
			j++;
		}
		i++;
	}
}

void	sortsprites(int *order, double *dist, int amount)
{
	int		i;
	int		temp[256][2];

	i = 0;
	while (i < amount)
	{
		temp[i][0] = dist[i];
		temp[i][1] = order[i];
		i++;
	}
	sort_order(temp, i);
	i = 0;
	while (i < amount)
	{
		dist[i] = temp[amount - i - 1][0];
		order[i] = temp[amount - i - 1][1];
		i++;
	}
}

void	sprite_init(t_info *info, t_sprite *sp)
{
	int		i;

	i = 0;
	while (i < sp->amount)
	{
		sp->spriteorder[i] = i;
		sp->spritedistance[i] = ((info->posx - info->sprite[i][1])
					* (info->posx - info->sprite[i][1])
					+ (info->posy - info->sprite[i][0])
					* (info->posy - info->sprite[i][0]));
		i++;
	}
}

void	sprite(t_info *info)
{
	t_sprite sp;

	ft_memset(&sp, 0, sizeof(sp));
	sp.amount = read_sprite(info);
	sprite_init(info, &sp);
	sortsprites(sp.spriteorder, sp.spritedistance, sp.amount);
	sprite2(info, &sp);
}

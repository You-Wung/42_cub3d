/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:52:09 by tyou              #+#    #+#             */
/*   Updated: 2021/04/21 14:08:42 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		exception(t_info *info, t_sprite *sp)
{
	if (sp->drawstarty < 0)
		sp->drawstarty = 0;
	if (sp->drawendy >= (int)info->height)
		sp->drawendy = info->height - 1;
	if (sp->drawstartx < 0)
		sp->drawstartx = 0;
	if (sp->drawendx >= (int)info->width)
		sp->drawendx = info->width - 1;
}

static void		stripe(t_info *info, t_sprite *sp)
{
	int	stripe;
	int	y;
	int	d;
	int	texx;
	int	texy;

	stripe = sp->drawstartx;
	while (stripe < sp->drawendx)
	{
		texx = (int)((256 * (stripe - (-sp->spritewidth / 2
		+ sp->spritescreenx)) * TEXWIDTH / sp->spritewidth) / 256);
		y = sp->drawstarty;
		if (sp->transformy > 0 && stripe > 0 && stripe < info->width
								&& sp->transformy < info->zbuffer[stripe])
			while (y < sp->drawendy)
			{
				d = y * 256 - info->height * 128 + sp->spriteheight * 128;
				texy = ((d * TEXHEIGHT) / sp->spriteheight) / 256;
				if (info->texture[4][TEXWIDTH * texy + texx] & 0xFFFFFF)
					info->buf[y][stripe] = info->texture[4]
													[TEXWIDTH * texy + texx];
				y++;
			}
		stripe++;
	}
}

static	void	sp_init(t_info *info, t_sprite *sp, int i)
{
	sp->spritey = info->sprite[sp->spriteorder[i]][0] - info->posy;
	sp->spritex = info->sprite[sp->spriteorder[i]][1] - info->posx;
	sp->invdet = 1.0 / (info->planex * info->diry - info->dirx * info->planey);
	sp->transformx = sp->invdet * (info->diry *
									sp->spritex - info->dirx * sp->spritey);
	sp->transformy = sp->invdet * (-info->planey *
									sp->spritex + info->planex * sp->spritey);
	sp->spritescreenx = (int)(info->width / 2)
									* (1 + sp->transformx / sp->transformy);
	sp->spriteheight = (int)fabs(info->height / sp->transformy);
	sp->drawstarty = -sp->spriteheight / 2 + info->height / 2;
	sp->drawendy = sp->spriteheight / 2 + info->height / 2;
	sp->spritewidth = (int)fabs(info->height / sp->transformy);
	sp->drawstartx = -sp->spritewidth / 2 + sp->spritescreenx;
	sp->drawendx = sp->spritewidth / 2 + sp->spritescreenx;
}

void			sprite2(t_info *info, t_sprite *sp)
{
	int	i;

	i = -1;
	while (++i < sp->amount)
	{
		sp_init(info, sp, i);
		exception(info, sp);
		stripe(info, sp);
	}
}

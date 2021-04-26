/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_read_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:02:20 by tyou              #+#    #+#             */
/*   Updated: 2021/04/26 14:31:27 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_index(t_info *info, int r, int g, int b)
{
	if (r > 0xFF || g > 0xFF || b > 0xFF
		|| r < 0 || g < 0 || b < 0)
		free_exit(info, 10);
	if (info->sign == 'F')
		info->floor = (r << 16) | (g << 8) | b;
	else if (info->sign == 'C')
		info->ceilling = (r << 16) | (g << 8) | b;
	return (1);
}

void	two_free(int **a)
{
	int		i;

	i = 0;
	if (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

void	free_exit(t_info *info, int i)
{
	if (info->s != NULL)
		free(info->s);
	if (info->north != NULL)
		free(info->north);
	if (info->south != NULL)
		free(info->south);
	if (info->west != NULL)
		free(info->west);
	if (info->east != NULL)
		free(info->east);
	if (info->zbuffer != NULL)
		free(info->zbuffer);
	if (info->map != NULL)
		two_free(info->map);
	if (info->buf != NULL)
		two_free(info->buf);
	if (info->texture != NULL)
		two_free(info->texture);
	if (i > 0)
		exit(printf("Error%d\n", i));
	exit(0);
}

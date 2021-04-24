/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 23:57:54 by tyou              #+#    #+#             */
/*   Updated: 2021/04/21 15:58:42 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_int_in_char(unsigned char *start, int value)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)(value >> 8);
	start[2] = (unsigned char)(value >> 16);
	start[3] = (unsigned char)(value >> 24);
}

static int	write_bmp_header(int fd, int filesize, t_info *info)
{
	int				i;
	int				tmp;
	unsigned char	bmpfileheader[54];

	i = 0;
	while (i < 54)
		bmpfileheader[i++] = (unsigned char)(0);
	bmpfileheader[0] = (unsigned char)('B');
	bmpfileheader[1] = (unsigned char)('M');
	set_int_in_char(bmpfileheader + 2, filesize);
	bmpfileheader[10] = (unsigned char)(54);
	bmpfileheader[14] = (unsigned char)(40);
	tmp = info->width;
	set_int_in_char(bmpfileheader + 18, tmp);
	tmp = info->height;
	set_int_in_char(bmpfileheader + 22, tmp);
	bmpfileheader[26] = (unsigned char)(1);
	bmpfileheader[28] = (unsigned char)(24);
	return (!(write(fd, bmpfileheader, 54) < 0));
}

static int	write_bmp_data(int file, t_info *info, int pad)
{
	const unsigned char	zero[3] = {0, 0, 0};
	int					i;
	int					j;
	int					color;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			color = info->img.data[(info->height - i) * info->width + j];
			if (write(file, &color, 3) < 0)
				return (0);
			if (pad > 0 && write(file, &zero, pad) < 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void		save_bmp(t_info *info)
{
	int		filesize;
	int		file;
	int		padding;

	file = 0;
	padding = info->width % 4;
	filesize = 54 + (3 * info->width + padding) * info->height;
	if ((file = open("screenshot.bmp", O_WRONLY | O_CREAT
									| O_TRUNC | O_APPEND, 0777)) < 0)
		return (free_exit(info, 1));
	if (!write_bmp_header(file, filesize, info))
		return (free_exit(info, 1));
	if (!write_bmp_data(file, info, padding))
		return (free_exit(info, 1));
	close(file);
	return (free_exit(info, 0));
}

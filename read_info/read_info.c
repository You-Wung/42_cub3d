/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 21:53:27 by tyou              #+#    #+#             */
/*   Updated: 2021/04/26 14:33:04 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		skip_empty_char(char **str, int sign, t_info *info)
{
	int		comma;

	if (sign == 0)
		while (**str == '	' || **str == ' ')
			(*str)++;
	else if (sign == 1)
	{
		while (**str >= '0' && **str <= '9')
			(*str)++;
		while (**str == '	' || **str == ' ' || **str == ',')
		{
			if (**str == ',' && comma == 1)
				free_exit(info, 10);
			comma = 1;
			(*str)++;
		}
	}
	else
	{
		while ((**str >= '0' && **str <= '9') || **str == ' ' || **str == '	')
			(*str)++;
		if (**str >= 33 && **str <= 126)
			free_exit(info, 11);
	}
}

static int	jump_to_index(char **str, t_info *t)
{
	if (t->sign == 's' || t->sign == 'R' || t->sign == 'F' || t->sign == 'C')
		(*str)++;
	if (t->sign == 'N' || t->sign == 'S' || t->sign == 'S'
			|| t->sign == 'W' || t->sign == 'E')
		*str = *str + 2;
	skip_empty_char(str, 0, t);
	return (1);
}

static int	read_num(char **str, t_info *info)
{
	int		r;
	int		g;
	int		b;

	jump_to_index(str, info);
	if (info->sign == 'F' || info->sign == 'C')
	{
		skip_empty_char(str, 0, info);
		r = ft_atoi(*str);
		skip_empty_char(str, 1, info);
		g = ft_atoi(*str);
		skip_empty_char(str, 1, info);
		b = ft_atoi(*str);
		skip_empty_char(str, 2, info);
		return (check_index(info, r, g, b));
	}
	skip_empty_char(str, 0, info);
	info->width = ft_atoi(*str);
	skip_empty_char(str, 1, info);
	info->height = ft_atoi(*str);
	skip_empty_char(str, 2, info);
	return (1);
}

static int	read_letter(char **str, t_info *info)
{
	char	*buf;
	int		len;
	int		i;

	len = 0;
	i = -1;
	jump_to_index(str, info);
	while ((*str)[len] >= '!' && (*str)[len] <= '~')
		len++;
	buf = (char*)malloc(len + 1);
	while (++i < len)
		buf[i] = (*str)[i];
	buf[i] = '\0';
	if (info->sign == 's')
		info->s = buf;
	if (info->sign == 'N')
		info->north = buf;
	if (info->sign == 'S')
		info->south = buf;
	if (info->sign == 'W')
		info->west = buf;
	if (info->sign == 'E')
		info->east = buf;
	return (1);
}

int			sort_gnl(char **str, t_info *info)
{
	if (info->north && info->south && info->west && info->east &&
	info->floor != -1 && info->ceilling != -1 && info->width && info->height)
		return (0);
	if (**str == 'S')
		info->sign = 's';
	if (**str == 'N' && *(*str + 1) == 'O')
		info->sign = 'N';
	if (**str == 'S' && *(*str + 1) == 'O')
		info->sign = 'S';
	if (**str == 'W' && *(*str + 1) == 'E')
		info->sign = 'W';
	if (**str == 'E' && *(*str + 1) == 'A')
		info->sign = 'E';
	if (info->sign)
		return (read_letter(str, info));
	if (**str == 'R')
		info->sign = 'R';
	if (**str == 'F')
		info->sign = 'F';
	if (**str == 'C')
		info->sign = 'C';
	if (info->sign)
		return (read_num(str, info));
	return (1);
}

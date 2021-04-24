/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:32:16 by tyou              #+#    #+#             */
/*   Updated: 2021/04/14 22:24:59 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_map
{
	unsigned int	y;
	unsigned int	x;
	unsigned int	starty;
	unsigned int	startx;
	int				previous[2];
}					t_map;

int					sizeofarrary(int *size);
void				preset(int *previous, int y, int x);
int					right_bottom(int **map, int y, int x, int *size);
int					right_top(int **map, int y, int x, int *size);
int					plus_x(int **map, int x, int y, int *size);
int					plus_y(int **map, int x, int y, int *size);
int					minus_x(int **map, int x, int y, int *size);
int					minus_y(int **map, int x, int y, int *size);

#endif

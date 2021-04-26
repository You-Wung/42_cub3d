/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 18:32:16 by tyou              #+#    #+#             */
/*   Updated: 2021/04/26 01:12:27 by tyou             ###   ########.fr       */
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

int			sizeofarray(int *i);
#endif

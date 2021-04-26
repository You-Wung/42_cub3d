/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyou <tyou@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 22:22:52 by tyou              #+#    #+#             */
/*   Updated: 2021/04/26 01:09:15 by tyou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT	17
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define K_ESC 53
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define MS 0.03
# define SS 0.05
# define RS 0.03
# include "mlx2/mlx.h"
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "map/map.h"
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_img
{
	void			*img;
	int				*data;
	int				size_l;
	int				bpp;
	int				endian;
	int				img_width;
	int				img_height;
}					t_img;
typedef struct		s_info
{
	char			sign;
	char			direct;
	char			*s;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	unsigned int	floor;
	unsigned int	ceilling;
	unsigned int	width;
	unsigned int	height;
	int				**map;
	int				size[256];
	double			sprite[256][2];
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	void			*mlx;
	void			*win;
	int				key_a;
	int				key_w;
	int				key_s;
	int				key_d;
	int				key_right;
	int				key_left;
	int				key_esc;
	t_img			img;
	int				**buf;
	double			*zbuffer;
	int				**texture;
}					t_info;
typedef struct		s_wall
{
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			wallx;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
	int				texnum;
}					t_wall;
typedef struct		s_sprite
{
	int				spriteorder[256];
	double			spritedistance[256];
	int				amount;
	double			spritex;
	double			spritey;
	double			invdet;
	double			transformx;
	double			transformy;
	int				spritescreenx;
	int				spriteheight;
	int				spritewidth;
	int				drawstarty;
	int				drawendy;
	int				drawstartx;
	int				drawendx;
}					t_sprite;

int					sort_gnl(char **str, t_info *info);
int					**read_map(int fd, t_info *info);
void				skip_empty_char(char **str, int sign);
int					check_index(t_info *info, int r, int g, int b);
int					leave(int key, t_info *info);
int					key_press(int key, t_info *info);
int					key_release(int key, t_info *info);
void				key_update(t_info *info);
void				setup_memory(int ***pointer, int height, int width);
void				set_up(t_info *info);
void				draw(t_info *info);
void				load_image(t_info *info, int *texture, char *path,
																t_img *img);
void				load_texture(t_info *info);
void				perp(t_info *info, t_wall *wall);
int					check_map(char **map, int *size, t_info *info);
void				floor_ceilling(t_info *info);
void				wall(t_info *info);
void				draw1(t_info *info, t_wall *wall);
void				draw2(t_info *info, t_wall *wall, int x);
void				sprite(t_info *info);
void				sprite2(t_info *info, t_sprite *sp);
void				save_bmp(t_info *info);
void				free_exit(t_info *info, int i);
void				key_rot_right(t_info *info);
void				key_rot_left(t_info *info);
#endif

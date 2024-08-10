/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:45:18 by mgauvrit          #+#    #+#             */
/*   Updated: 2023/09/04 12:45:18 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/extensions/Xfixes.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define SCREENWIDTH 1880
# define SCREENHEIGHT 1000
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef double __attribute__((ext_vector_type(2)))	t_mgam2d;
typedef int __attribute__((ext_vector_type(2)))		t_mgam2i;

typedef struct s_data
{
	int		x;
	int		y;
	int		f;
	int		c;
	int		p;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		front;
	int		back;
	int		right;
	int		left;
	int		sprint;
	int		mouse;
	int		r_right;
	int		r_left;
	int		mouse_r_right;
	int		mouse_r_left;
	int		r;
	int		g;
	int		b;
	int		frgb;
	int		crgb;
	char	**map;
	int		mouse_x;
}	t_data;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*n;
	void	*s;
	void	*w;
	void	*e;
	void	*f;
	void	*c;
}	t_mlx;

typedef struct s_algo
{
	int			x;
	int			y;
	int			hit;
	int			side;
	int			line_height;
	int			pitch;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		camera_x;
	double		perp_wall_dist;
	double		wall_x;
	double		walk;
	double		tex_pos;
	double		old_dir_x;
	double		old_plane_x;
	double		move_speed;
	double		rot_speed;
	t_mgam2i	map;
	t_mgam2i	tex;
	t_mgam2d	pos;
	t_mgam2d	dir;
	t_mgam2d	step;
	t_mgam2d	plane;
	t_mgam2d	ray_dir;
	t_mgam2d	side_dist;
	t_mgam2d	delta_dist;
}	t_algo;

typedef struct s_img
{
	void		*image;
	char		*img_addr;
	char		*data;
	int			size_line;
	int			bpp;
	int			line;
	int			bp;
	int			endian;
}	t_img;

typedef struct s_struct
{
	t_data	*data;
	t_mlx	*mlx;
	t_algo	*algo;
	t_img	*img;
}	t_struct;

/************|||~Parsing~|||**************/

/*	parse_utils.c	*/
void	opening_extend(t_struct *all, char *str);
char	**ft_opening(char *file, t_struct *all);
void	arg_error(int argc, char *argv, t_struct *all);
int		check_border(char **map);

/*	parse_utils2.c	*/
double	find_playerx(char **tab);
double	find_playery(char **tab);
void	ft_check_textures( t_struct *all, char **tab);
void	ft_check_rgb( t_struct *all, char **tab);

/*	parse_utils3.c	*/
int		big_length(char **tmp);
char	*fake_cpy(char *old, int len);
char	**fill_space(char **tmp);
int		security_map(char **map, int y, int i);
int		check_map(char **map);

/*	parsing.c	*/
void	check_nl(char *str, t_struct *all);
void	ft_elem(t_struct *all);
void	info_error(char **tab, t_struct *all);
void	get_infos(t_struct *all);
int		ft_map_checking(int ac, char *filename, t_struct *all);

/************|||~Raycasting~|||**************/

/*	event.c		*/
int		event(t_struct *all);
/*	mouse.c		*/
int		mouse_rot(int x, int y, t_data *data);
/*	pixel.c		*/
int		get_color(t_struct *all, t_algo *algo, t_img *img, void *image);
int		get_color2(int tx, int ty, t_struct *all, void *image);
void	my_pixel_put(t_algo *algo, t_img *img, int color);
void	my_pixel_put2(int x, int y, t_img *img, int color);
void	ft_mini_map(t_struct *all);
/*	ray_init.c	*/
void	ray_init(t_data *data, t_algo *algo);
void	ray_init2(t_data *data, t_algo *algo);
void	ray_dir_cam_init(t_algo *algo);
void	ray_side_init(t_algo *algo);
/*	raycsting.c	*/
int		raycasting(t_struct *all);

/************|||~Utils~|||**************/

/*	event_utils.c	*/
int		key_press(int command, t_struct *all);
int		key_release(int command, t_struct *all);
void	rotate(t_struct *all, double rot_speed);
/*		utils.c	 	*/
void	kill_da_shit(char *msg, t_struct *all);
void	free_map_tab(char **map_tab);
int		clean_win_kill(t_struct *all);
float	ft_fabs(float i);

/************|||~Main~|||**************/

#endif

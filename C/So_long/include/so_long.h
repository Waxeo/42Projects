/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgauvrit <mgauvrit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:25:19 by mgauvrit          #+#    #+#             */
/*   Updated: 2022/12/23 16:44:21 by mgauvrit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include </opt/X11/include/X11/X.h>
# include </opt/X11/include/X11/keysymdef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	char	**map;
	int		player;
	int		collect;
	int		exit;
	int		move;
	int		count;
	void	*w;
	void	*f;
	void	*p;
	void	*e;
	void	*c;
	char	adresse[1];
}	t_data;

void	kill_da_shit(char *msg, t_data *data);
void	clean_win_kill(t_data *data);
int		close_with_mouse(t_data *data);

void	free_map_tab(char **map_tab);

int		check_nl(char *str, t_data *data);
char	**ft_opening(char *file, t_data *data);
int		ft_map_checking(int ac, char *filename, t_data *data);

int		ft_elem(t_data *data);
int		arg_error(int argc, char *argv, t_data *data);

int		ft_rectangular(t_data *data);

int		ft_check_pec(t_data *data);
int		ft_check_p(t_data *data);
int		ft_check_e(t_data *data);
int		ft_check_c(t_data *data);

int		ft_check_border(t_data *data);
int		len(char **tab);

int		verify_path(char *filename, t_data *data);
char	*ft_fill_one(char *taby, int x);
int		ft_find_path(char **tab, int x, int y, int count);
int		ft_elem_nbr(char **tab);
char	**ft_replace(char **tab);
int		find_playery(char **tab, int y);
int		find_playerx(char **tab, int x);

void	ft_associates(t_data *data);
void	ft_add_image(char **tab, t_data *data);
void	ft_func_too_long(t_data *data, int toggle, int i, int j);

int		controls_working(int command, t_data *game);
int		a_movement(t_data *data);
int		d_movement(t_data *data);
int		w_movement(t_data *data);
int		s_movement(t_data *data);
int		check_move(t_data *game, int i, int j);
#endif

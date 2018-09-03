/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:01:22 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/03 18:06:24 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include "/goinfre/tmadau/.brew/include/SDL2/SDL.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# define WIN_HEIGHT 350
# define WIN_WIDTH 515

typedef struct		s_info
{
	double			**map;
	size_t			row;
	int				x;
	int				y;
	int				fill_x;
	int				fill_y;
	int				fd;
	int				running;
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	int				height;
	int				width;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			time;
	double			old_time;
	double			count_x;
	double			cam_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				hit;
	int				step_x;
	int				step_y;
	double			side_dist_x;
	double			side_dist_y;
	int				side;
	double			perp_wall_dist;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				count_j;
	int				count_y;
	double			frame_time;
	double			move_speed;
	double			rot_speed;
	double			old_dir_x;
	double			old_plane_x;
}					t_info;

//void				get_x_and_y(char *str, t_info *ev);
//void				map_alloc(char *str, t_info *ev);
//t_info				ft_ray_calc(t_info *ev);
//t_info				ft_side_dist_calc(t_info *ev);
//t_info				ft_dda_calc(t_info *ev);
//t_info				ft_draw_stuff(t_info *ev);
//t_info				ft_render_stuff(t_info *ev);
//t_info				draw_ceiling(t_info *ev);
//void				events(t_info *ev);

#endif

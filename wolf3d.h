/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <tmadau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:01:22 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/12 15:56:53 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define ARG_ERR "\x1b[31mWrong number of arguments | usage : ./wolf3d map\n"
# define LINE_ERR "\x1b[31mFound wrong line length, program now Exiting\n"
# define DATA_ERR "\x1b[31mNo data found.\n"
# define REND_COLOR SDL_SetRenderDrawColor
# define SDX in->side_dist_x
# define SDY in->side_dist_y
# include "/goinfre/tmadau/.brew/include/SDL2/SDL.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	int				height;
	int				count_j;
	int				draw_end;
	int				draw_start;
	int				count_y;
	int				running;
	double			frame_time;
	double			time;
	double			old_time;
}					t_sdl;

typedef struct		s_raycast
{
	double			cam_x;
	double			count_x;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			ray_pos_x;
	double			ray_pos_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	double			perp_wall_dist;
	int				line_height;
	double			ray_dir_x;
	double			ray_dir_y;
	int				step_x;
	int				step_y;
	int				width;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
}					t_raycast;

typedef struct		s_buttons
{
	double			rot_speed;
	double			old_plane_x;
	double			old_dir_x;
	double			move_speed;
}					t_buttons;

void				draw_floor(t_sdl *ev, t_raycast *in);
void				draw_ceiling(t_sdl *ev, t_raycast *in);
void				ft_render_stuff(t_sdl *ev, t_raycast *in);
void				ft_do_stuff(t_raycast *ev, t_sdl *in, t_map *op);
void				move_left(t_raycast *ev, t_buttons *in);
void				move_right(t_raycast *ev, t_buttons *in);
void				move_down(t_raycast *ev, t_buttons *in, t_map *op);
void				move_up(t_raycast *ev, t_buttons *in, t_map *op);
void				take_ev(t_raycast *op, t_buttons *ev, t_sdl *in);
void				events(t_raycast *op, t_buttons *ev, t_sdl *in, t_map *ol);
void				ft_draw_stuff(t_raycast *ev, t_sdl *in);
void				ft_dda_calc(t_raycast *ev, t_map *in);
void				ft_side_dist_calc(t_raycast *ev);
void				ft_ray_calc(t_raycast *ev);

#endif

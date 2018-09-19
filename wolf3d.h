/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <tmadau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 13:01:22 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/18 17:36:23 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define ARG_ERR "\x1b[31mWrong number of arguments | usage : ./wolf3d map\n"
# define LINE_ERR "\x1b[31mFound wrong line length, program now Exiting\n"
# define MAP_ERR "\x1b[31mNo map selected\n"
# define DATA_ERR "\x1b[31mNo data found.\n"
# define MAP_ER "\x1b[31mInvalid map.\n"
# define REND_COLOR SDL_SetRenderDrawColor
# define PRESS var->event.type == SDL_KEYDOWN
# define RELEASE var->event.type == SDL_KEYUP
# define KEY var->event.key.keysym.sym
# define ROT ev->rot_speed
# define GO ev->move_speed
# define ALP_OPQ SDL_ALPHA_OPAQUE
# define SDX op->side_dist_x
# define SDY op->side_dist_y
# include "/goinfre/tmadau/.brew/include/SDL2/SDL.h"
# include "libft/libft.h"
# include <math.h>

typedef struct		s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
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
	int				height;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
}					t_raycast;

typedef struct		s_buttons
{
	SDL_bool		left;
	SDL_bool		right;
	SDL_bool		down;
	SDL_bool		up;
	double			rot_speed;
	double			old_plane_x;
	double			old_dir_x;
	double			move_speed;
}					t_buttons;

void				draw_floor(t_sdl *var, t_raycast *op);
void				draw_ceiling(t_sdl *var, t_raycast *op);
void				ft_render_stuff(t_sdl *var, t_raycast *op);
void				ft_do_stuff(t_raycast *op, t_sdl *var, t_map *in);
void				ft_init_stuff(t_raycast *op, t_sdl *var);
void				move_rotate(t_raycast *op, t_buttons *ev);
void				move(t_raycast *op, t_buttons *ev, t_map *in);
void				take_ev(t_raycast *op, t_buttons *ev, t_sdl *var);
void				events(t_raycast *op, t_buttons *ev, t_sdl *var, t_map *in);
void				game_run(char **av, t_raycast *op, t_map *in, t_sdl *var);
int					check_map(t_map *in, t_raycast *op);
void				ft_draw_stuff(t_raycast *op, t_sdl *var);
void				ft_dda_calc(t_raycast *op, t_map *in);
void				ft_side_dist_calc(t_raycast *op);
void				ft_ray_calc(t_raycast *op);
int					ft_sdl_init(t_sdl *var);
int					place_player(t_map *in, t_raycast *op);
void				movement(t_raycast *op, t_buttons *ev, t_map *in);

#endif

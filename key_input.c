/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:24:53 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/14 10:14:41 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_left(t_raycast *ev, t_buttons *in)
{
	in->old_dir_x = ev->dir_x;
	ev->dir_x = ev->dir_x * cos(in->rot_speed) - ev->dir_y * sin(in->rot_speed);
	ev->dir_y = in->old_dir_x * sin(in->rot_speed) +
		ev->dir_y * cos(in->rot_speed);
	in->old_plane_x = ev->plane_x;
	ev->plane_x = ev->plane_x * cos(in->rot_speed) - ev->plane_y *
		sin(in->rot_speed);
	ev->plane_y = in->old_plane_x * sin(in->rot_speed) + ev->plane_y *
		cos(in->rot_speed);
}

void		move_right(t_raycast *ev, t_buttons *in)
{
	in->old_dir_x = ev->dir_x;
	ev->dir_x = ev->dir_x * cos(-in->rot_speed) - ev->dir_y *
		sin(-in->rot_speed);
	ev->dir_y = in->old_dir_x * sin(-in->rot_speed) + ev->dir_y *
		cos(-in->rot_speed);
	in->old_plane_x = ev->plane_x;
	ev->plane_x = ev->plane_x * cos(-in->rot_speed) - ev->plane_y *
		sin(-in->rot_speed);
	ev->plane_y = in->old_plane_x * sin(-in->rot_speed) + ev->plane_y *
		cos(-in->rot_speed);
}

void		move_down(t_raycast *ev, t_buttons *in, t_map *op)
{
	if (op->map[(int)(ev->pos_x - ev->dir_x * in->move_speed)][(int)ev->pos_y]
			== 0)
		ev->pos_x -= ev->dir_x * in->move_speed;
	if (op->map[(int)ev->pos_x][(int)(ev->pos_y - ev->dir_y * in->move_speed)]
			== 0)
		ev->pos_y -= ev->dir_y * in->move_speed;
}

void		move_up(t_raycast *ev, t_buttons *in, t_map *op)
{
	if (op->map[(int)(ev->pos_x + ev->dir_x * in->move_speed)][(int)ev->pos_y]
			== 0)
		ev->pos_x += ev->dir_x * in->move_speed;
	if (op->map[(int)ev->pos_x][(int)(ev->pos_y + ev->dir_y *
				in->move_speed)] == 0)
		ev->pos_y += ev->dir_y * in->move_speed;
}

void		take_ev(t_raycast *op, t_buttons *ev, t_sdl *in)
{
	op->count_x = 0;
	in->old_time = in->time;
	in->time = SDL_GetTicks();
	in->frame_time = (in->time - in->old_time) / 1000.0;
	SDL_RenderPresent(in->renderer);
	REND_COLOR(in->renderer, 0, 0, 0, 255);
	SDL_RenderClear(in->renderer);
	ev->move_speed = in->frame_time * 7.0;
	ev->rot_speed = in->frame_time * 4.0;
}

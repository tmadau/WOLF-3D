/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:24:53 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/18 12:08:50 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_rotate(t_raycast *op, t_buttons *ev)
{
	if (ev->left == SDL_TRUE)
	{
		ev->old_dir_x = op->dir_x;
		op->dir_x = op->dir_x * cos(ev->rot_speed) - op->dir_y * sin(ev->rot_speed);
		op->dir_y = ev->old_dir_x * sin(ev->rot_speed) +
			op->dir_y * cos(ev->rot_speed);
		ev->old_plane_x = op->plane_x;
		op->plane_x = op->plane_x * cos(ev->rot_speed) - op->plane_y *
			sin(ev->rot_speed);
		op->plane_y = ev->old_plane_x * sin(ev->rot_speed) + op->plane_y *
			cos(ev->rot_speed);
	}
	if (ev->right == SDL_TRUE)
	{
		ev->old_dir_x = op->dir_x;
		op->dir_x = op->dir_x * cos(-ev->rot_speed) - op->dir_y *
			sin(-ev->rot_speed);
		op->dir_y = ev->old_dir_x * sin(-ev->rot_speed) + op->dir_y *
			cos(-ev->rot_speed);
		ev->old_plane_x = op->plane_x;
		op->plane_x = op->plane_x * cos(-ev->rot_speed) - op->plane_y *
			sin(-ev->rot_speed);
		op->plane_y = ev->old_plane_x * sin(-ev->rot_speed) + op->plane_y *
			cos(-ev->rot_speed);
	}
}

void		move(t_raycast *op, t_buttons *ev, t_map *in)
{
	if (ev->down == SDL_TRUE)
	{
		if (in->map[(int)(op->pos_x - op->dir_x * ev->move_speed)][(int)op->pos_y]
				== 0)
			op->pos_x -= op->dir_x * ev->move_speed;
		if (in->map[(int)op->pos_x][(int)(op->pos_y - op->dir_y * ev->move_speed)]
				== 0)
			op->pos_y -= op->dir_y * ev->move_speed;
	}
	if (ev->up == SDL_TRUE)
	{
		if (in->map[(int)(op->pos_x + op->dir_x * ev->move_speed)][(int)op->pos_y]
				== 0)
			op->pos_x += op->dir_x * ev->move_speed;
		if (in->map[(int)op->pos_x][(int)(op->pos_y + op->dir_y *
					ev->move_speed)] == 0)
			op->pos_y += op->dir_y * ev->move_speed;
	}
}

void		take_ev(t_raycast *op, t_buttons *ev, t_sdl *var)
{
	op->count_x = 0;
	var->old_time = var->time;
	var->time = SDL_GetTicks();
	var->frame_time = (var->time - var->old_time) / 1000.0;
	SDL_RenderPresent(var->renderer);
	REND_COLOR(var->renderer, 0, 0, 0, 255);
	SDL_RenderClear(var->renderer);
	ev->move_speed = var->frame_time * 1.025;
	ev->rot_speed = var->frame_time * 1.025;
}

void	events(t_raycast *op, t_buttons *ev, t_sdl *var, t_map *in)
{
	take_ev(op, ev, var);
	while (SDL_PollEvent(&var->event))
	{
		if (var->event.type == SDL_QUIT)
			var->running = 1;
		if (PRESS)
		{
			if (KEY == SDLK_ESCAPE)
				var->running = 1;
			(KEY == SDLK_UP || KEY == SDLK_w) ? ev->up = SDL_TRUE : 1;
			(KEY == SDLK_DOWN || KEY == SDLK_s) ? ev->down = SDL_TRUE : 1;
			(KEY == SDLK_RIGHT || KEY == SDLK_d) ? ev->right = SDL_TRUE : 1;
			(KEY == SDLK_LEFT || KEY == SDLK_a) ? ev->left = SDL_TRUE : 1;
		}
		else if (RELEASE)
		{
			(KEY == SDLK_UP || KEY == SDLK_w) ? ev->up = SDL_FALSE : 1;
			(KEY == SDLK_DOWN || KEY == SDLK_s) ? ev->down = SDL_FALSE : 1;
			(KEY == SDLK_RIGHT || KEY == SDLK_d) ? ev->right = SDL_FALSE : 1;
			(KEY == SDLK_LEFT || KEY == SDLK_a) ? ev->left = SDL_FALSE : 1;
		}
	}
}

/*void	events(t_raycast *op, t_buttons *ev, t_sdl *var, t_map *in)
{
	take_ev(op, ev, var);
	while (SDL_PollEvent(&var->event))
	{
		if (var->event.type == SDL_QUIT)
			var->running = 1;
		if (PRESS)
		{
			if (KEY == SDLK_ESCAPE)
				var->running = 1;
			if (KEY == SDLK_UP || KEY == SDLK_w)
				ev->up = SDL_TRUE;
			if (KEY == SDLK_DOWN || KEY == SDLK_s)
				ev->down = SDL_TRUE;
			if (KEY == SDLK_RIGHT || KEY == SDLK_d)
				ev->right = SDL_TRUE;
			if (KEY == SDLK_LEFT || KEY == SDLK_a)
				ev->left = SDL_TRUE;
		}
		else if (RELEASE)
		{
			if (KEY == SDLK_UP || KEY == SDLK_w)
				ev->up = SDL_FALSE;
			if (KEY == SDLK_DOWN || KEY == SDLK_s)
				ev->down = SDL_FALSE;
			if (KEY == SDLK_RIGHT || KEY == SDLK_d)
				ev->right = SDL_FALSE;
			if (KEY == SDLK_LEFT || KEY == SDLK_a)
				ev->left = SDL_FALSE;
		}
	}
}*/

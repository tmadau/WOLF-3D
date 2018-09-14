/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <tmadau@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 09:29:00 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/14 12:54:35 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	events(t_raycast *op, t_buttons *ev, t_sdl *in, t_map *ol)
{
	take_ev(op, ev, in);
	while (SDL_PollEvent(&in->event))
	{
		if (in->event.type == SDL_QUIT)
			in->running = 1;
		if (in->event.type == SDL_KEYDOWN)
		{
			if (in->event.key.keysym.sym == SDLK_ESCAPE)
				in->running = 1;
			if (in->event.key.keysym.sym == SDLK_UP ||
					in->event.key.keysym.sym == SDLK_w)
				move_up(op, ev, ol);
			if (in->event.key.keysym.sym == SDLK_DOWN ||
					in->event.key.keysym.sym == SDLK_s)
				move_down(op, ev, ol);
			if (in->event.key.keysym.sym == SDLK_RIGHT ||
					in->event.key.keysym.sym == SDLK_d)
				move_right(op, ev);
			if (in->event.key.keysym.sym == SDLK_LEFT ||
					in->event.key.keysym.sym == SDLK_a)
				move_left(op, ev);
		}
	}
}

void	ft_init_stuff(t_raycast *ev, t_sdl *in)
{
	ev->pos_x = 1.1;
	ev->pos_y = 1.1;
	ev->dir_x = -1;
	ev->dir_y = 0;
	ev->plane_x = 0;
	ev->plane_y = 0.66;
	in->time = 0;
	in->old_time = 0;
	ev->height = 600;
	ev->width = 1000;
}

int		ft_sdl_init(t_sdl *ev)
{
	ev->running = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (1);
	ev->window = SDL_CreateWindow("Wolf 3D",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			1000, 600, 0);
	ev->renderer = SDL_CreateRenderer(ev->window,
			-1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(ev->renderer, 0, 0, 0, 255);
	SDL_RenderClear(ev->renderer);
	return (0);
}

void	game_engine(char **av, t_raycast *ev, t_map *in, t_sdl *op)
{
	get_matrix(av[1], in);
	alloc_matrix(av[1], in);
	place_player(av, ev);
	ft_sdl_init(op);
	ft_init_stuff(ev, op);
}

int		main(int ac, char **av)
{
	t_raycast	ev;
	t_map		in;
	t_sdl		op;
	t_buttons	re;

	if (ac == 2)
	{
		if (open(av[1], O_RDONLY) == -1)
			ft_putstr(MAP_ERR);
		else
		{
			game_engine(av, &ev, &in, &op);
			while (op.running == 0)
			{
				while (ev.count_x++ < ev.width)
					ft_do_stuff(&ev, &op, &in);
				events(&ev, &re, &op, &in);
			}
			SDL_DestroyWindow(op.window);
			SDL_Quit();
		}
//		if (ev.count_x == -1)
//			ft_putstr("FAILURE");
//		ev.count_x == -2 ? ft_putstr(LINE_ERR) : ft_putstr(DATA_ERR);
	}
	else
		ft_putstr(ARG_ERR);
	return (0);
}

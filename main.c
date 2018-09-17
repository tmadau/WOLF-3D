/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:37 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/17 17:37:53 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	movement(t_raycast *op, t_buttons *ev, t_map *in)
{
	move_up(op, ev, in);
	move_down(op, ev, in);
	move_right(op, ev);
	move_left(op, ev);
}

void	events(t_raycast *op, t_buttons *ev, t_sdl *var, t_map *in)
{
	take_ev(op, ev, var);
	while (SDL_PollEvent(&var->event))
	{
		if (var->event.type == SDL_QUIT)
			var->running = 1;
		if (var->event.type == SDL_KEYDOWN)
		{
			if (var->event.key.keysym.sym == SDLK_ESCAPE)
				var->running = 1;
			if (var->event.key.keysym.sym == SDLK_UP ||
					var->event.key.keysym.sym == SDLK_w)
				ev->up = SDL_TRUE;
			if (var->event.key.keysym.sym == SDLK_DOWN ||
					var->event.key.keysym.sym == SDLK_s)
				ev->down = SDL_TRUE;
			if (var->event.key.keysym.sym == SDLK_RIGHT ||
					var->event.key.keysym.sym == SDLK_d)
				ev->right = SDL_TRUE;
			if (var->event.key.keysym.sym == SDLK_LEFT ||  
					var->event.key.keysym.sym == SDLK_a)
				ev->left = SDL_TRUE;
		}
		else if (var->event.type == SDL_KEYUP)
		{
			if (var->event.key.keysym.sym == SDLK_UP ||
					var->event.key.keysym.sym == SDLK_w)
				ev->up = SDL_FALSE;
			if (var->event.key.keysym.sym == SDLK_DOWN ||
					var->event.key.keysym.sym == SDLK_s)
				ev->down = SDL_FALSE;
			if (var->event.key.keysym.sym == SDLK_RIGHT ||
					var->event.key.keysym.sym == SDLK_d)
				ev->right = SDL_FALSE;
			if (var->event.key.keysym.sym == SDLK_LEFT ||  
					var->event.key.keysym.sym == SDLK_a)
				ev->left = SDL_FALSE;
		}
	}
}

void	ft_init_stuff(t_raycast *op, t_sdl *var)
{
	op->pos_x = 1.1;
	op->pos_y = 1.1;
	op->dir_x = -1;
	op->dir_y = 0;
	op->plane_x = 0;
	op->plane_y = 0.66;
	var->time = 0;
	var->old_time = 0;
	op->height = 600;
	op->width = 1000;
}

int		ft_sdl_init(t_sdl *var)
{
	var->running = 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (1);
	var->window = SDL_CreateWindow("Wolf 3D",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			1000, 600, 0);
	var->renderer = SDL_CreateRenderer(var->window,
			-1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(var->renderer, 0, 0, 0, 255);
	SDL_RenderClear(var->renderer);
	return (0);
}

void	game_engine(char **av, t_raycast *ev, t_map *in, t_sdl *var)
{
	get_matrix(av[1], in);
	alloc_matrix(av[1], in);
	if (in->get_y != 0)
	{
		place_player(av, ev);
		ft_sdl_init(var);
		ft_init_stuff(ev, var);
	}
	else
	{
		var->running = 1;
		ft_putstr(DATA_ERR);
	}
}

int		main(int ac, char **av)
{
	t_raycast	op;
	t_map		in;
	t_sdl		var;
	t_buttons	ev;

	if (ac == 2)
	{
		if (open(av[1], O_RDONLY) == -1)
			ft_putstr(MAP_ERR);
		else
		{
			game_engine(av, &op, &in, &var);
			while (var.running == 0)
			{
				while (op.count_x++ < op.width)
					ft_do_stuff(&op, &var, &in);
				events(&op, &ev, &var, &in);
				movement(&op, &ev, &in);
			}
			SDL_DestroyWindow(var.window);
			SDL_Quit();
		}
	}
	else
		ft_putstr(ARG_ERR);
	return (0);
}

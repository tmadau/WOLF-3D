/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 14:00:37 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/18 15:42:45 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_map(t_map *in, t_raycast *op)
{
	int			ret;
	int			x;
	int			y;

	x = 0;
	y = 0;
	if ((ret = place_player(in, op)) != 1)
		return (ret);
	x = -1;
	y = -1;
	while (++x < in->get_x)
	{
		if (in->map[0][x] == 0)
			return (0);
		if (in->map[in->get_y - 1][x] == 0)
			return (0);
	}
	while (++y < in->get_y)
	{
		if (in->map[y][0] == 0)
			return (0);
		if (in->map[y][in->get_x - 1] == 0)
			return (0);
	}
	return (1);
}

void	ft_init_stuff(t_raycast *op, t_sdl *var)
{
	op->dir_x = -1;
	op->dir_y = 0;
	op->plane_x = 0;
	op->plane_y = 0.66;
	var->time = 0.005;
	var->old_time = 0.005;
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

void	game_engine(char **av, t_raycast *op, t_map *in, t_sdl *var)
{
	get_matrix(av[1], in);
	printf("tk = %d\n", in->tk);
	alloc_matrix(av[1], in);
	if (in->tk == 0)
	{
		var->running = 1;
		ft_putstr(LINE_ERR);
	}
	else if (!check_map(in, op))
	{
		var->running = 1;
		ft_putstr(MAP_ER);
	}
	else if (in->get_y != 0 && place_player(in, op))
	{
		ft_sdl_init(var);
		ft_init_stuff(op, var);
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
			}
			SDL_DestroyWindow(var.window);
			SDL_Quit();
		}
	}
	else
		ft_putstr(ARG_ERR);
	return (0);
}

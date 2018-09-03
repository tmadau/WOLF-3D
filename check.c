/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:44:43 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/03 18:10:34 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_left(t_info *ev)
{
	ev->old_dir_x = ev->dir_x;
	ev->dir_x = ev->dir_x * cos(ev->rot_speed) - ev->dir_y * sin(ev->rot_speed);
	ev->dir_y = ev->old_dir_x * sin(ev->rot_speed) +
		ev->dir_y * cos(ev->rot_speed);
	ev->old_plane_x = ev->plane_x;
	ev->plane_x = ev->plane_x * cos(ev->rot_speed) - ev->plane_y *
		sin(ev->rot_speed);
	ev->plane_y = ev->old_plane_x * sin(ev->rot_speed) + ev->plane_y *
		cos(ev->rot_speed);
}

void		move_right(t_info *ev)
{
	ev->old_dir_x = ev->dir_x;
	ev->dir_x = ev->dir_x * cos(-ev->rot_speed) - ev->dir_y *
		sin(-ev->rot_speed);
	ev->dir_y = ev->old_dir_x * sin(-ev->rot_speed) + ev->dir_y *
		cos(-ev->rot_speed);
	ev->old_plane_x = ev->plane_x;
	ev->plane_x = ev->plane_x * cos(-ev->rot_speed) - ev->plane_y *
		sin(-ev->rot_speed);
	ev->plane_y = ev->old_plane_x * sin(-ev->rot_speed) + ev->plane_y *
		cos(-ev->rot_speed);
}

void		move_down(t_info *ev)
{
	if (ev->map[(int)(ev->pos_x - ev->dir_x * ev->move_speed)][(int)ev->pos_y]
			== 0)
		ev->pos_x -= ev->dir_x * ev->move_speed;
	if (ev->map[(int)ev->pos_x][(int)(ev->pos_y - ev->dir_y * ev->move_speed)]
			== 0)
		ev->pos_y -= ev->dir_y * ev->move_speed;
}

void		move_up(t_info *ev)
{
	if (ev->map[(int)(ev->pos_x + ev->dir_x * ev->move_speed)][(int)ev->pos_y]
			== 0)
		ev->pos_x += ev->dir_x * ev->move_speed;
	if (ev->map[(int)ev->pos_x][(int)(ev->pos_y + ev->dir_y *
				ev->move_speed)] == 0)
		ev->pos_y += ev->dir_y * ev->move_speed;
}

void		events(t_info *ev)
{
	ev->count_x = 0;
	ev->old_time = ev->time;
	ev->time = SDL_GetTicks();
	ev->frame_time = (ev->time - ev->old_time) / 1000.0;
	SDL_RenderPresent(ev->renderer);
	SDL_SetRenderDrawColor(ev->renderer, 0, 0, 0, 255);
	SDL_RenderClear(ev->renderer);
	ev->move_speed = ev->frame_time * 7.0;
	ev->rot_speed = ev->frame_time * 4.0;
	while (SDL_PollEvent(&ev->event))
	{
		if (ev->event.type == SDL_QUIT)
			ev->running = 1;
		if (ev->event.type == SDL_KEYDOWN)
		{
			if (ev->event.key.keysym.sym == SDLK_ESCAPE)
				ev->running = 1;
			if (ev->event.key.keysym.sym == SDLK_UP ||
					ev->event.key.keysym.sym == SDLK_w)
				move_up(ev);
			if (ev->event.key.keysym.sym == SDLK_DOWN ||
					ev->event.key.keysym.sym == SDLK_s)
				move_down(ev);
			if (ev->event.key.keysym.sym == SDLK_RIGHT ||
					ev->event.key.keysym.sym == SDLK_d)
				move_right(ev);
			if (ev->event.key.keysym.sym == SDLK_LEFT ||
					ev->event.key.keysym.sym == SDLK_a)
				move_left(ev);
		}
	}
}

t_info		draw_floor(t_info *ev)
{
	ev->count_j = ev->draw_end + 1;
	while (ev->count_j < ev->height)
	{
		SDL_SetRenderDrawColor(ev->renderer, 0, 124, 255, 255);
		SDL_RenderDrawPoint(ev->renderer, ev->count_x, ev->count_j);
		ev->count_j++;
	}
	return (*ev);
}

t_info		draw_ceiling(t_info *ev)
{
	ev->count_j = ev->draw_end + 1;
	while (ev->count_j < ev->height)
	{
		SDL_SetRenderDrawColor(ev->renderer, 255, 124, 255, 255);
		SDL_RenderDrawPoint(ev->renderer, ev->count_x, ev->height -
				ev->count_j);
		ev->count_j++;
	}
	draw_floor(ev);
	return (*ev);
}

t_info		ft_render_stuff(t_info *ev)
{
	draw_ceiling(ev);
	ev->count_y = ev->draw_start;
	if (ev->side == 0)
		SDL_SetRenderDrawColor(ev->renderer, 0, 0, 255, 255);
	if (ev->side != 0)
		SDL_SetRenderDrawColor(ev->renderer, 255, 0, 0, 255);
	if (ev->side == 0 && ev->ray_dir_x < 0)
		SDL_SetRenderDrawColor(ev->renderer, 0, 255, 0, 255);
	if (ev->side == 1 && ev->ray_dir_y < 0)
		SDL_SetRenderDrawColor(ev->renderer, 255, 255, 255, 255);
	while (ev->count_y < ev->draw_end)
	{
		SDL_RenderDrawPoint(ev->renderer, ev->count_x, ev->count_y);
		ev->count_y++;
	}
	return (*ev);
}

t_info		ft_draw_stuff(t_info *ev)
{
	if (ev->side == 0)
		ev->perp_wall_dist = (ev->map_x - ev->ray_pos_x +
				(1 - ev->step_x) / 2) / ev->ray_dir_x;
	else
		ev->perp_wall_dist = (ev->map_y - ev->ray_pos_y +
				(1 - ev->step_y) / 2) / ev->ray_dir_y;
	ev->line_height = (int)((int)ev->height / ev->perp_wall_dist);
	ev->draw_start = -ev->line_height + ev->height / 2;
	if (ev->draw_start < 0)
		ev->draw_start = 0;
	ev->draw_end = ev->line_height + ev->height / 2;
	if (ev->draw_end >= ev->height)
		ev->draw_end = ev->height - 1;
	return (*ev);
}

t_info		ft_dda_calc(t_info *ev)
{
	while (ev->hit == 0)
	{
		if (ev->side_dist_x < ev->side_dist_y)
		{
			ev->side_dist_x += ev->delta_dist_x;
			ev->map_x += ev->step_x;
			ev->side = 0;
		}
		else
		{
			ev->side_dist_y += ev->delta_dist_y;
			ev->map_y += ev->step_y;
			ev->side = 1;
		}
		if (ev->map[ev->map_x][ev->map_y] > 0)
			ev->hit = 1;
	}
	return (*ev);
}

t_info		ft_side_dist_calc(t_info *ev)
{
	if (ev->ray_dir_x < 0)
	{
		ev->step_x = -1;
		ev->side_dist_x = (ev->ray_pos_x - ev->map_x) * ev->delta_dist_x;
	}
	else
	{
		ev->step_x = 1;
		ev->side_dist_x = (ev->map_x + 1.0 - ev->ray_pos_x) * ev->delta_dist_x;
	}
	if (ev->ray_dir_y < 0)
	{
		ev->step_y = -1;
		ev->side_dist_y = (ev->ray_pos_y - ev->map_y) * ev->delta_dist_y;
	}
	else
	{
		ev->step_y = 1;
		ev->side_dist_y = (ev->map_y + 1.0 - ev->ray_pos_y) * ev->delta_dist_y;
	}
	return (*ev);
}

t_info		ft_ray_calc(t_info *ev)
{
	ev->cam_x = 2 * ev->count_x / (double)ev->width - 1;
	ev->ray_pos_x = ev->pos_x;
	ev->ray_pos_y = ev->pos_y;
	ev->ray_dir_x = ev->dir_x + ev->plane_x * ev->cam_x;
	ev->ray_dir_y = ev->dir_y + ev->plane_y * ev->cam_x;
	ev->map_x = (int)ev->ray_pos_x;
	ev->map_y = (int)ev->ray_pos_y;
	ev->delta_dist_x = sqrt(1 + (ev->ray_dir_y * ev->ray_dir_y) /
			(ev->ray_dir_x * ev->ray_dir_x));
	ev->delta_dist_y = sqrt(1 + (ev->ray_dir_x * ev->ray_dir_x) /
			(ev->ray_dir_y * ev->ray_dir_y));
	ev->hit = 0;
	return (*ev);
}

void	map_fill(char *str, t_info *ev)
{
	char	*line;
	char	**split;

	ev->fill_x = 0;
	ev->fill_y = 0;
	ev->fd = open(str, O_RDONLY);
	while (get_next_line(ev->fd, &line) > 0 && ev->fill_y < ev->y)
	{
		if ((ft_wordcount(line, ' ')) >= ev->row)
		{
			split = ft_strsplit(line, ' ');
			ev->fill_x = 0;
			while (ev->fill_x < ev->x)
			{
				ev->map[ev->fill_y][ev->fill_x] =
					(int)ft_atoi(split[ev->fill_x]);
				ev->fill_x++;
			}
			ev->fill_y++;
			free(line);
		}
		else
			printf("Map Error!\n");
	}
	close(ev->fd);
}

void	map_alloc(char *str, t_info *ev)
{
	int		index;

	index = 0;
	ev->map = (double **)malloc(sizeof(double *) * ev->y);
	while (index < ev->y)
	{
		ev->map[index] = (double *)malloc(sizeof(double) * ev->x);
		index++;
	}
	map_fill(str, ev);
}

void	get_x_and_y(char *str, t_info *ev)
{
	int		fd;
	char	*line;
	int		buff;
	int		inc;

	fd = open(str, O_RDONLY);
	line = NULL;
	inc = 1;
	if (get_next_line(fd, &line) > 0)
		buff = ft_wordcount(line, ' ');
	while (get_next_line(fd, &line) > 0)
		inc++;
	ev->row = buff;
	ev->x = buff;
	ev->y = inc;
	close(fd);
}

t_info		ft_do_stuff(t_info *ev)
{
	ft_ray_calc(ev);
	ft_side_dist_calc(ev);
	ft_dda_calc(ev);
	ft_draw_stuff(ev);
	ft_render_stuff(ev);
	return (*ev);
}

t_info		ft_init_stuff(t_info *ev)
{
	ev->pos_x = 2;
	ev->pos_y = 2;
	ev->dir_x = -1;
	ev->dir_y = 0;
	ev->plane_x = 0;
	ev->plane_y = 0.66;
	ev->time = 0;
	ev->old_time = 0;
	ev->height = 600;
	ev->width = 1000;
	return (*ev);
}

int			ft_sdl_init(t_info *ev)
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

int			main(int ac, char *av[])
{
	t_info ev;

	if (ac == 2)
	{
		if (open(av[1], O_RDONLY) == -1)
			ft_putendl("Map error!");
		else
		{
			get_x_and_y(av[1], &ev);
			map_alloc(av[1], &ev);
			ft_sdl_init(&ev);
			ft_init_stuff(&ev);
			while (ev.running == 0)
			{
				while (ev.count_x++ < ev.width)
					ft_do_stuff(&ev);
				events(&ev);
			}
			SDL_DestroyWindow(ev.window);
			SDL_Quit();
		}
	}
	else
		ft_putendl("An error occured!");
	return (0);
}

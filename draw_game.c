/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:32:24 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/14 11:30:45 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_floor(t_sdl *ev, t_raycast *in)
{
	ev->count_j = ev->draw_end + 1;
	while (ev->count_j <= in->height)
	{
		REND_COLOR(ev->renderer, 163, 94, 48, 0);
		SDL_RenderDrawPoint(ev->renderer, in->count_x, ev->count_j);
		ev->count_j++;
	}
}

void	draw_ceiling(t_sdl *ev, t_raycast *in)
{
	ev->count_j = ev->draw_end + 1;
	while (ev->count_j <= in->height)
	{
		REND_COLOR(ev->renderer, 0, 135, 255, 0);
		SDL_RenderDrawPoint(ev->renderer, in->count_x, in->height -
				ev->count_j);
		ev->count_j++;
	}
	draw_floor(ev, in);
}

void	ft_render_stuff(t_sdl *ev, t_raycast *in)
{
	draw_ceiling(ev, in);
	if (SDX > 2)
		SDX = 2;
	if (SDY > 2)
		SDY = 2;
	ev->count_y = ev->draw_start;
	if (in->side == 0)
		REND_COLOR(ev->renderer, 186 / SDX, 133 / SDX, 0, 0);
	if (in->side != 0)
		REND_COLOR(ev->renderer, 214 / SDY, 64 / SDY, 0, 0);
	if (in->side == 0 && in->ray_dir_x < 0)
		REND_COLOR(ev->renderer, 255 / SDX, 218 / SDX, 168 / SDX, 0);
	if (in->side == 1 && in->ray_dir_y < 0)
		REND_COLOR(ev->renderer, 0xFF / SDY, 0x9f / SDY, 0, 0);
	while (ev->count_y < ev->draw_end)
	{
		SDL_RenderDrawPoint(ev->renderer, in->count_x, ev->count_y);
		ev->count_y++;
	}
}

void	ft_do_stuff(t_raycast *ev, t_sdl *in, t_map *op)
{
	ft_ray_calc(ev);
	ft_side_dist_calc(ev);
	ft_dda_calc(ev, op);
	ft_draw_stuff(ev, in);
	ft_render_stuff(in, ev);
}

void	place_player(char **av, t_raycast *rc)
{
	int		c;
	int		i;

	c = -1;
	while (av[++c])
	{
		i = -1;
		while (++i < rc->width && i++ < rc->height)
		{
			if (av[c][i] == 0 && i + 1 < rc->width && i + 1 < rc->height)
			{
				rc->pos_x = c + 1;
				rc->pos_y = i + 1;
				break ;
			}
		}
	}
}

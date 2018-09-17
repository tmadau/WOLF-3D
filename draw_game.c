/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:32:24 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/17 16:32:11 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_floor(t_sdl *var, t_raycast *op)
{
	var->count_j = var->draw_end + 1;
	while (var->count_j <= op->height)
	{
		REND_COLOR(var->renderer, 163, 94, 48, 0);
		SDL_RenderDrawPoint(var->renderer, op->count_x, var->count_j);
		var->count_j++;
	}
}

void	draw_ceiling(t_sdl *var, t_raycast *op)
{
	var->count_j = var->draw_end + 1;
	while (var->count_j <= op->height)
	{
		REND_COLOR(var->renderer, 0, 135, 255, 0);
		SDL_RenderDrawPoint(var->renderer, op->count_x, op->height -
				var->count_j);
		var->count_j++;
	}
	draw_floor(var, op);
}

void	ft_render_stuff(t_sdl *var, t_raycast *op)
{
	draw_ceiling(var, op);
	if (SDX > 2)
		SDX = 2;
	if (SDY > 2)
		SDY = 2;
	var->count_y = var->draw_start;
	if (op->side == 0)
		REND_COLOR(var->renderer, 186 / SDX, 133 / SDX, 0, ALP_OPQ);
	if (op->side != 0)
		REND_COLOR(var->renderer, 214 / SDY, 64 / SDY, 0, ALP_OPQ);
	if (op->side == 0 && op->ray_dir_x < 0)
		REND_COLOR(var->renderer, 255 / SDX, 218 / SDX, 168 / SDX, ALP_OPQ);
	if (op->side == 1 && op->ray_dir_y < 0)
		REND_COLOR(var->renderer, 0xFF / SDY, 0x9f / SDY, 0, ALP_OPQ);
	while (var->count_y < var->draw_end)
	{
		SDL_RenderDrawPoint(var->renderer, op->count_x, var->count_y);
		var->count_y++;
	}
}

void	ft_do_stuff(t_raycast *ev, t_sdl *var, t_map *op)
{
	ft_ray_calc(ev);
	ft_side_dist_calc(ev);
	ft_dda_calc(ev, op);
	ft_draw_stuff(ev, var);
	ft_render_stuff(var, ev);
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

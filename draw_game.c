/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:32:24 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/18 15:32:55 by tmadau           ###   ########.fr       */
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

void	ft_do_stuff(t_raycast *op, t_sdl *var, t_map *in)
{
	ft_ray_calc(op);
	ft_side_dist_calc(op);
	ft_dda_calc(op, in);
	ft_draw_stuff(op, var);
	ft_render_stuff(var, op);
}

int		place_player(t_map *in, t_raycast *op)
{
	int		c;
	int		i;
	int		space;

	c = -1;
	space = 0;
	while (++c < in->get_y - 1 && space != 1)
	{
		i = -1;
		while (i++ < in->get_x - 1)
		{
			if (in->map[c][i] == 0)
			{
				op->pos_x = c + 0.5;
				op->pos_y = i + 0.5;
				space = 1;
				break ;
			}
		}
	}
	if (space == 0)
		return (0);
	return (1);
}

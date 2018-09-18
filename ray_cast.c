/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:19:03 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/18 09:49:35 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_stuff(t_raycast *op, t_sdl *var)
{
	if (op->side == 0)
		op->perp_wall_dist = (op->map_x - op->ray_pos_x +
				(1 - op->step_x) / 2) / op->ray_dir_x;
	else
		op->perp_wall_dist = (op->map_y - op->ray_pos_y +
				(1 - op->step_y) / 2) / op->ray_dir_y;
	op->line_height = (int)(op->height / op->perp_wall_dist);
	var->draw_start = -op->line_height + op->height / 2;
	if (var->draw_start < 0)
		var->draw_start = 0;
	var->draw_end = op->line_height + op->height / 2;
	if (var->draw_end >= op->height)
		var->draw_end = op->height - 1;
}

void	ft_dda_calc(t_raycast *op, t_map *in)
{
	while (op->hit == 0 && op->map_x > 0 && op->map_y > 0)
	{
		if (op->side_dist_x < op->side_dist_y)
		{
			op->side_dist_x += op->delta_dist_x;
			op->map_x += op->step_x;
			op->side = 0;
		}
		else
		{
			op->side_dist_y += op->delta_dist_y;
			op->map_y += op->step_y;
			op->side = 1;
		}
		if (in->map[op->map_x][op->map_y] > 0)
			op->hit = 1;
	}
}

void	ft_side_dist_calc(t_raycast *op)
{
	if (op->ray_dir_x < 0)
	{
		op->step_x = -1;
		op->side_dist_x = (op->ray_pos_x - op->map_x) * op->delta_dist_x;
	}
	else
	{
		op->step_x = 1;
		op->side_dist_x = (op->map_x + 1.0 - op->ray_pos_x) * op->delta_dist_x;
	}
	if (op->ray_dir_y < 0)
	{
		op->step_y = -1;
		op->side_dist_y = (op->ray_pos_y - op->map_y) * op->delta_dist_y;
	}
	else
	{
		op->step_y = 1;
		op->side_dist_y = (op->map_y + 1.0 - op->ray_pos_y) * op->delta_dist_y;
	}
}

void	ft_ray_calc(t_raycast *op)
{
	op->cam_x = 2 * op->count_x / (double)op->width - 1;
	op->ray_pos_x = op->pos_x;
	op->ray_pos_y = op->pos_y;
	op->ray_dir_x = op->dir_x + op->plane_x * op->cam_x;
	op->ray_dir_y = op->dir_y + op->plane_y * op->cam_x;
	op->map_x = (int)op->ray_pos_x;
	op->map_y = (int)op->ray_pos_y;
	op->delta_dist_x = sqrt(1 + (op->ray_dir_y * op->ray_dir_y) /
			(op->ray_dir_x * op->ray_dir_x));
	op->delta_dist_y = sqrt(1 + (op->ray_dir_x * op->ray_dir_x) /
			(op->ray_dir_y * op->ray_dir_y));
	op->hit = 0;
}

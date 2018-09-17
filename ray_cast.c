/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:19:03 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/17 13:21:14 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_draw_stuff(t_raycast *ev, t_sdl *in)
{
	if (ev->side == 0)
		ev->perp_wall_dist = (ev->map_x - ev->ray_pos_x +
				(1 - ev->step_x) / 2) / ev->ray_dir_x;
	else
		ev->perp_wall_dist = (ev->map_y - ev->ray_pos_y +
				(1 - ev->step_y) / 2) / ev->ray_dir_y;
	ev->line_height = (int)(ev->height / ev->perp_wall_dist);
	in->draw_start = -ev->line_height + ev->height / 2;
	if (in->draw_start < 0)
		in->draw_start = 0;
	in->draw_end = ev->line_height + ev->height / 2;
	if (in->draw_end >= ev->height)
		in->draw_end = ev->height - 1;
}

void	ft_dda_calc(t_raycast *ev, t_map *in)
{
	while (ev->hit == 0 && ev->map_x > 0 && ev->map_y > 0)
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
		if (in->map[ev->map_x][ev->map_y] > 0)
			ev->hit = 1;
	}
}

void	ft_side_dist_calc(t_raycast *ev)
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
}

void	ft_ray_calc(t_raycast *ev)
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
}

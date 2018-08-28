/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:22:41 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/21 10:54:55 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "gfx.h"

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	int			i;
}				t_mlx;

typedef struct	s_dda
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			z1;
	int			z2;
	double		scale;
}				t_dda;

typedef	struct	s_inc
{
	int			i;
	int			steps;
	double		x_inc;
	double		y_inc;
	double		z_inc;
}				t_inc;

typedef	struct	s_pixel
{
	int			dif_x;
	int			dif_y;
	int			dif_z;
	float		x;
	float		y;
	float		z;
	int			steps;
}				t_pixel;

typedef struct	s_sum
{
	char		***val;
	double		z_axis;
	int			x;
	int			y;
}				t_sum;

#endif

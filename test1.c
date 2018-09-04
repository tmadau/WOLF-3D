/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 09:29:43 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/04 10:13:59 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		dda_sum(t_pixel *add, t_dda *point)
{
	add->dif_x = point->x2 - point->x1;
	add->dif_y = point->y2 - point->y1;
	add->dif_z = point->z2 - point->z1;
	if (ABS(add->dif_x) >= ABS(add->dif_z))
		ABS(add->dif_x) >= ABS(add->dif_y) ? add->steps = ABS(add->dif_x)
			: (add->steps = ABS(add->dif_y));
	else
		ABS(add->dif_z) >= ABS(add->dif_y) ? add->steps = ABS(add->dif_z)
			: (add->steps = ABS(add->dif_y));
	add->x = point->x1;
	add->y = point->y1;
	add->z = point->z1;
	return (add->steps);
}

void	dda_algo(t_dda *draw, t_mlx *mlx, double z)
{
	t_pixel	set;
	t_inc	put;

	(void)z;
	put.steps = dda_sum(&set, draw);
	put.x_inc = set.dif_x / (float)put.steps;
	put.y_inc = set.dif_y / (float)put.steps;
	put.z_inc = set.dif_z / (float)put.steps;
	put.i = 0;
	while (put.i <= put.steps)
	{
		if (set.z > 0)
			mlx_pixel_put(mlx->mlx, mlx->win, (set.x - set.y)
					+ 800, (set.x + set.y) / 2 + 100 + set.z, 0xadff2f);
		else if (set.z < 0)
			mlx_pixel_put(mlx->mlx, mlx->win, (set.x - set.y)
					+ 800, (set.x + set.y) / 2 + 100 + set.z, 0xffd700);
		else
			mlx_pixel_put(mlx->mlx, mlx->win, (set.x - set.y)
					+ 800, (set.x + set.y) / 2 + 100 + set.z, 0xbc8f8f);
		set.x += put.x_inc;
		set.y += put.y_inc;
		set.z += put.z_inc;
		put.i++;
	}
}

void	draw_y_pixels(t_sum *plot, t_dda *pixel, t_mlx *mlx, t_array *row)
{
	mlx->i = 0;
	if ((plot->val[1] = ft_strsplit(row->matrix[plot->y + 1], ' ')))
	{
		pixel->x1 = 0;
		pixel->x2 = 0;
		plot->x = -1;
		while (plot->val[0][++plot->x] && plot->val[1][plot->x])
		{
			pixel->z1 = (-1 * (double)ft_atoi(plot->val[0][plot->x])) * 5;
			pixel->z2 = (-1 * (double)ft_atoi(plot->val[1][plot->x])) * 5;
			pixel->y1 = (pixel->scale * plot->y);
			pixel->y2 = (pixel->scale * (plot->y + 1));
			dda_algo(pixel, mlx, plot->z_axis);
			pixel->x2 += pixel->scale;
			pixel->x1 = pixel->x2;
		}
		mlx->i = -1;
		while (++mlx->i < row->count)
			free(plot->val[1][mlx->i]);
	}
	plot->x = 0;
	plot->y++;
	mlx->i = -1;
	while (++mlx->i < row->count)
		free(plot->val[0][mlx->i]);
}

int		draw_xy_pixels(t_sum *plot, t_array *row, t_mlx *mlx)
{
	t_dda	pixel;

	pixel.scale = 7;
	plot->y = 0;
	plot->x = 0;
	while (row->matrix[plot->y] && !(pixel.x1 = 0))
	{
		plot->val[0] = ft_strsplit(row->matrix[plot->y], ' ');
		pixel.x2 = pixel.scale;
		while (plot->val[0][plot->x] && plot->val[0][plot->x + 1])
		{
			pixel.z1 = (-1 * (double)ft_atoi(plot->val[0][plot->x])) * 10;
			pixel.z2 = (-1 * (double)ft_atoi(plot->val[0][plot->x + 1])) * 10;
			pixel.y1 = (pixel.scale * plot->y);
			pixel.y2 = (pixel.scale * (plot->y));
			dda_algo(&pixel, mlx, plot->z_axis);
			pixel.x1 = pixel.x2;
			pixel.x2 += pixel.scale;
			plot->x++;
		}
		draw_y_pixels(plot, &pixel, mlx, row);
		free(plot->val[0]);
		free(plot->val[1]);
	}
	return (0);
}

int		esc_fun(int key)
{
	if (key == 12 || key == 53)
	{
		ft_putendl_fd("\e\x1b[31mwindow closed!", 1);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

void	window(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1850, 1030, "FDF");
}

int		draw_pixels(t_mlx *mlx, t_array *matrix)
{
	int		n;
	t_sum	plot;

	n = 0;
	if (!(plot.val = (char ***)malloc(sizeof(plot.val) * 3)))
		return (0);
	plot.val[2] = NULL;
	draw_xy_pixels(&plot, matrix, mlx);
	free(plot.val);
	return (1);
}

int		wire_frame(int fd)
{
	t_array	matrix;
	t_mlx	mlx;
	int		n;

	if ((n = get_matrix(&matrix, fd)) != 1)
		return (n);
	window(&mlx);
	draw_pixels(&mlx, &matrix);
	mlx_key_hook(mlx.win, esc_fun, 0);
	mlx_loop(mlx.mlx);
	return (1);
}

int		main(int argc, char **argv)
{
	t_fd	draw;

	if (argc == 2)
	{
		draw.fd = open(argv[1], O_RDONLY);
		if (draw.fd != ERR)
		{
			draw.ret = wire_frame(draw.fd);
			if (draw.ret == 0)
				ft_putstr("FAILURE\n");
			draw.ret == L_ERR ? ft_putstr(LINE_ERR) : ft_putstr(DATA_ERR);
		}
		else
		{
			perror(P_ERR);
			return (ERR);
		}
		close(draw.fd);
	}
	else
		ft_putstr(ARG_ERR);
	return (0);
}

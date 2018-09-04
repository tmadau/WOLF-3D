/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 18:04:07 by tmadau            #+#    #+#             */
/*   Updated: 2018/09/04 10:13:57 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GFX_H
# define GFX_H

# define ARG_ERR "\x1b[31mWrong number of arguments | usage : ./fdf maps.fdf\n"
# define LINE_ERR "\x1b[31mFound wrong line length, program now Exiting\n"
# define DATA_ERR "\x1b[31mNo data found.\n"
# define ABS(n) (n > 0 ? n : -n)
# define L_ERR -2
# define P_ERR "\x1b[31mError "
# include "/goinfre/tmadau/.brew/include/SDL2/SDL.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "wolf3d.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define WIN_HEIGHT 350
# define WIN_WIDTH 515

typedef struct	s_fd
{
	int			fd;
	int			ret;
}				t_fd;

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

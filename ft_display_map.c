/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:40:15 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/21 10:26:50 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx/mlx.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <fcntl.h>

void	ft_display_others(t_mlx *mlx, t_img *mur, char **map)
{
	t_img	*sol;
	t_img	*collct;
	t_img	*door;

	sol = ft_floor(mlx);
	collct = ft_collct(mlx);
	door = ft_door(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		sol->img, mur->x, mur->y);
	if (map[mur->j][mur->i] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, collct->img,
			mur->x, mur->y);
		mlx->items++;
	}
	if (map[mur->j][mur->i] == 'E')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, door->img,
			mur->x, mur->y);
		mlx->x_door = mur->x;
		mlx->y_door = mur->y;
	}
	ft_free_img(sol, collct, door);
}

void	ft_display_all(t_mlx *mlx, t_img *mur, char **map)
{
	while (mur->i != (ft_strlen(map[mur->j]) - 1))
	{
		if (map[mur->j][mur->i] == '1')
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				mur->img, mur->x, mur->y);
		if (map[mur->j][mur->i] == 'P')
		{
			mlx->x = mur->x;
			mlx->y = mur->y;
		}
		if (map[mur->j][mur->i] != '1')
			ft_display_others(mlx, mur, map);
		mur->i++;
		mur->x = mur->x +32;
	}
}

void	create_mlx(t_mlx *mlx, char **map)
{
	mlx->relative_path = "./includes/DarkKnightXPM/tile000.xpm";
	mlx->img = mlx_xpm_file_to_image(mlx->mlx, mlx->relative_path,
			&mlx->img_width, &mlx->img_height);
	mlx->items = 0;
	mlx->nb_pas = 0;
	mlx->map = map;
}

void	ft_display_map(char	**map, int nb_lines)
{
	t_mlx	mlx;
	t_img	*mur;

	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, (((ft_strlen(map[0]) - 1) * 32)),
			((nb_lines * 32)), "SO LONG");
	mur = ft_wall(&mlx);
	create_mlx(&mlx, map);
	while (mur->j != nb_lines)
	{
		mur->i = 0;
		mur->x = 0;
		ft_display_all(&mlx, mur, map);
		mur->y = mur->y +32;
		mur->j++;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, mlx.x, mlx.y);
	mlx_string_put(mlx.mlx, mlx.mlx_win, 8, 20, 0xffffff, ft_itoa(mlx.nb_pas));
	mlx_hook(mlx.mlx_win, 17, (1L << 2), ft_close_mouse, &mlx);
	mlx_hook(mlx.mlx_win, 02, (1L << 0), ft_check_wasd, &mlx);
	mlx_loop(mlx.mlx);
}

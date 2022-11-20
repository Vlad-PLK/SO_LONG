/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:32:37 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/20 21:46:51 by vpolojie         ###   ########.fr       */
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

int	ft_loop_cara(t_mlx *mlx)
{
	if ((mlx->nb_pas % 2) == 0)
	{
		mlx->relative_path = "./includes/DarkKnightXPM/tile002.xpm";
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, mlx->relative_path,
				&mlx->img_width, &mlx->img_height);
	}
	else
	{
		mlx->relative_path = "./includes/DarkKnightXPM/tile000.xpm";
		mlx->img = mlx_xpm_file_to_image(mlx->mlx, mlx->relative_path,
				&mlx->img_width, &mlx->img_height);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		mlx->img, mlx->x, mlx->y);
	return (0);
}

void	ft_wasd_move_part2(int keycode, t_mlx *mlx, t_img *door)
{
	if (keycode == 2 && (mlx->map[mlx->i][mlx->j +1] != '1'))
	{
		if (mlx->map[mlx->i][mlx->j +1] == 'C' && mlx->items == 1)
			end_map_condition(mlx, door);
		if (mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items == 0)
			ending_message(mlx);
		if (!(mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items != 0))
			mlx->x = mlx->x + 32;
	}
	if (keycode == 13 && (mlx->map[mlx->i -1][mlx->j] != '1'))
	{
		if (mlx->map[mlx->i -1][mlx->j] == 'C' && mlx->items == 1)
			end_map_condition(mlx, door);
		if (mlx->map[mlx->i -1][mlx->j] == 'E' && mlx->items == 0)
			ending_message(mlx);
		if (!(mlx->map[mlx->i -1][mlx->j] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i -1][mlx->j] == 'E' && mlx->items != 0))
			mlx->y = mlx->y - 32;
	}
}

void	ft_wasd_move(int keycode, t_mlx *mlx, t_img *door)
{
	if (keycode == 0 && (mlx->map[mlx->i][mlx->j -1] != '1'))
	{
		if (mlx->map[mlx->i][mlx->j -1] == 'C' && mlx->items == 1)
			end_map_condition(mlx, door);
		if (mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items == 0)
			ending_message(mlx);
		if (!(mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items != 0))
			mlx->x = mlx->x - 32;
	}
	if (keycode == 1 && (mlx->map[mlx->i +1][mlx->j] != '1'))
	{
		if (mlx->map[mlx->i +1][mlx->j] == 'C' && mlx->items == 1)
			end_map_condition(mlx, door);
		if (mlx->map[mlx->i +1][mlx->j] == 'E' && mlx->items == 0)
			ending_message(mlx);
		if (!(mlx->map[mlx->i +1][mlx->j] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i +1][mlx->j] == 'E' && mlx->items != 0))
			mlx->y = mlx->y + 32;
	}
	ft_wasd_move_part2(keycode, mlx, door);
}

void	ft_wasd_loop(t_mlx *mlx, int keycode)
{
	t_img	*sol;
	t_img	*door;

	door = ft_door(mlx);
	sol = ft_floor(mlx);
	door->relative_path = "./includes/door2.xpm";
	door->img = mlx_xpm_file_to_image(mlx->mlx, door->relative_path,
			&door->img_width, &door->img_height);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, sol->img, mlx->x, mlx->y);
	ft_wasd_move(keycode, mlx, door);
	if (mlx->map[mlx->i][mlx->j] == 'C' && mlx->items != 0)
	{
		mlx->items--;
		mlx->map[mlx->i][mlx->j] = '0';
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, sol->img, mlx->x, mlx->y);
	mlx_loop_hook(mlx->mlx, ft_loop_cara, mlx);
}

int	ft_check_wasd(int keycode, t_mlx *mlx)
{
	int	i;

	i = mlx->nb_pas;
	if (keycode == 53)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode != 0 && keycode != 1 && keycode != 2 && keycode != 13)
		return (0);
	mlx->i = ((mlx->y) / 32);
	mlx->j = ((mlx->x) / 32);
	if ((keycode == 0 && (mlx->map[mlx->i][mlx->j -1] != '1'))
		|| (keycode == 1 && (mlx->map[mlx->i +1][mlx->j] != '1'))
		|| (keycode == 2 && (mlx->map[mlx->i][mlx->j +1] != '1'))
		|| (keycode == 13 && (mlx->map[mlx->i -1][mlx->j] != '1')))
		ft_wasd_loop(mlx, keycode);
	if (i != mlx->nb_pas)
		ft_printf("%d \n", mlx->nb_pas);
	return (0);
}

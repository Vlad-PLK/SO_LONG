/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:32:37 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/04 08:44:53 by vpolojie         ###   ########.fr       */
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
	int	i;
	int	j;

	i = ((mlx->y) / 32);
	j = ((mlx->x) / 32);
	if (mlx->map[i][j] == '1')
		return (0);
	if (mlx->map[i][j] != '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
			mlx->img, mlx->x, mlx->y);
	return (0);
}

void	ft_free_wasd_show_result(t_mlx *mlx, t_img *door)
{
	free(door);
	free(mlx->map);
	exit(EXIT_SUCCESS);
}

void	ft_wasd_move_part2(int keycode, t_mlx *mlx, t_img *door)
{
	if (keycode == 2 && (mlx->map[mlx->i][mlx->j +1] != '1'))
	{
		if (mlx->map[mlx->i][mlx->j +1] == 'C' && mlx->items == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				door->img, mlx->x_door, mlx->y_door);
		if (mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items == 0)
			ft_free_wasd_show_result(mlx, door);
		if (!(mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items != 0))
			mlx->x = mlx->x + 32;
	}
	if (keycode == 13 && (mlx->map[mlx->i -1][mlx->j] != '1'))
	{
		if (mlx->map[mlx->i -1][mlx->j] == 'C' && mlx->items == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				door->img, mlx->x_door, mlx->y_door);
		if (mlx->map[mlx->i -1][mlx->j] == 'E' && mlx->items == 0)
			ft_free_wasd_show_result(mlx, door);
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
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				door->img, mlx->x_door, mlx->y_door);
		if (mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items == 0)
			ft_free_wasd_show_result(mlx, door);
		if (!(mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items != 0))
			mlx->x = mlx->x - 32;
	}
	if (keycode == 1 && (mlx->map[mlx->i +1][mlx->j] != '1'))
	{
		if (mlx->map[mlx->i +1][mlx->j] == 'C' && mlx->items == 1)
			mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
				door->img, mlx->x_door, mlx->y_door);
		if (mlx->map[mlx->i +1][mlx->j] == 'E' && mlx->items == 0)
			ft_free_wasd_show_result(mlx, door);
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
	if (mlx->map[mlx->i][mlx->j] == 'C')
	{
		mlx->items--;
		mlx->map[mlx->i][mlx->j] = 'O';
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, sol->img, mlx->x, mlx->y);
	mlx_loop_hook(mlx->mlx, ft_loop_cara, mlx);
	free(sol);
	free(door);
}

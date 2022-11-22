/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:32:37 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/21 11:25:10 by vpolojie         ###   ########.fr       */
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
	t_img	*mur;

	mur = ft_wall(mlx);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 8, 20, 0xffffff,
		ft_itoa(mlx->nb_pas));
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		mur->img, 0, 0);
	mlx_string_put(mlx->mlx, mlx->mlx_win, 8, 20, 0xffffff,
		ft_itoa(mlx->nb_pas));
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		mlx->img, mlx->x, mlx->y);
	free(mur);
	return (0);
}

void	ft_wasd_move_part2(int keycode, t_mlx *mlx)
{
	if (keycode == 2 && (mlx->map[mlx->i][mlx->j +1] != '1'))
	{
		if (mlx->map[mlx->i][mlx->j +1] == 'C' && mlx->items > 1)
			mlx->items--;
		if (mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items == 0)
			ending_message(mlx);
		if (!(mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i][mlx->j +1] == 'E' && mlx->items != 0))
			mlx->x = mlx->x + 32;
	}
	if (keycode == 13 && (mlx->map[mlx->i -1][mlx->j] != '1'))
	{
		if (mlx->map[mlx->i -1][mlx->j] == 'C' && mlx->items > 1)
			mlx->items--;
		if (mlx->map[mlx->i -1][mlx->j] == 'E' && mlx->items == 0)
			ending_message(mlx);
		if (!(mlx->map[mlx->i -1][mlx->j] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i -1][mlx->j] == 'E' && mlx->items != 0))
			mlx->y = mlx->y - 32;
	}
}

void	ft_wasd_move(int keycode, t_mlx *mlx)
{
	if (keycode == 0 && (mlx->map[mlx->i][mlx->j -1] != '1'))
	{
		if (mlx->map[mlx->i][mlx->j -1] == 'C' && mlx->items > 1)
			mlx->items--;
		if (mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items == 0)
			ending_message(mlx);
		if (!(mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i][mlx->j -1] == 'E' && mlx->items != 0))
			mlx->x = mlx->x - 32;
	}
	if (keycode == 1 && (mlx->map[mlx->i +1][mlx->j] != '1'))
	{
		if (mlx->map[mlx->i +1][mlx->j] == 'C' && mlx->items > 1)
			mlx->items--;
		if (mlx->map[mlx->i +1][mlx->j] == 'E' && mlx->items == 0)
			ending_message(mlx);
		if (!(mlx->map[mlx->i +1][mlx->j] == 'E' && mlx->items != 0))
			mlx->nb_pas++;
		if (!(mlx->map[mlx->i +1][mlx->j] == 'E' && mlx->items != 0))
			mlx->y = mlx->y + 32;
	}
	ft_wasd_move_part2(keycode, mlx);
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
	if (((keycode == 0 && (mlx->map[mlx->i][mlx->j -1] == 'C'))
		|| (keycode == 1 && (mlx->map[mlx->i +1][mlx->j] == 'C'))
		|| (keycode == 2 && (mlx->map[mlx->i][mlx->j +1] == 'C'))
		|| (keycode == 13 && (mlx->map[mlx->i -1][mlx->j] == 'C')))
		&& mlx->items == 1)
		end_map_condition(mlx, door);
	ft_wasd_move(keycode, mlx);
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

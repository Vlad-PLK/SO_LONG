/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:31:01 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/21 11:11:08 by vpolojie         ###   ########.fr       */
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

int	ft_close_mouse(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_free_img(t_img *sol, t_img *collct, t_img *door)
{
	free(sol);
	free(collct);
	free(door);
}

void	ft_free_path_finding(t_data *data, int n)
{
	data->i = 0;
	while (data->i != n)
	{
		free(data->v_map[data->i]);
		data->i++;
	}
	free(data->v_map);
}

void	end_map_condition(t_mlx *mlx, t_img *door)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win,
		door->img, mlx->x_door, mlx->y_door);
	mlx->items = 0;
}

void	ending_message(t_mlx *mlx)
{
	ft_printf("You finished the game in %d steps\n", mlx->nb_pas +1);
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(EXIT_SUCCESS);
}

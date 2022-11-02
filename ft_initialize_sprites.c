/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_sprites.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:47:29 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/06 10:47:36 by vpolojie         ###   ########.fr       */
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

t_img	*ft_cara(t_mlx *mlx)
{
	t_img	*caracter;

	caracter = (t_img *)malloc(sizeof(t_img));
	caracter->relative_path = "./includes/DarkKnightXPM/tile000.xpm";
	caracter->img = mlx_xpm_file_to_image(mlx->mlx, caracter->relative_path,
			&caracter->img_width, &caracter->img_height);
	return (caracter);
}

t_img	*ft_door(t_mlx *mlx)
{
	t_img	*door;

	door = (t_img *)malloc(sizeof(t_img));
	door->relative_path = "./includes/door1.xpm";
	door->img = mlx_xpm_file_to_image(mlx->mlx, door->relative_path,
			&door->img_width, &door->img_height);
	return (door);
}

t_img	*ft_collct(t_mlx *mlx)
{
	t_img	*collct;

	collct = (t_img *)malloc(sizeof(t_img));
	collct->relative_path = "./includes/collectible/loot04coins.xpm";
	collct->img = mlx_xpm_file_to_image(mlx->mlx, collct->relative_path,
			&collct->img_width, &collct->img_height);
	return (collct);
}

t_img	*ft_floor(t_mlx *mlx)
{	
	t_img	*sol;

	sol = (t_img *)malloc(sizeof(t_img));
	sol->relative_path = "./includes/floor.xpm";
	sol->img = mlx_xpm_file_to_image(mlx->mlx, sol->relative_path,
			&sol->img_width, &sol->img_height);
	return (sol);
}

t_img	*ft_wall(t_mlx *mlx)
{
	t_img	*mur;

	mur = (t_img *)malloc(sizeof(t_img));
	mur->i = 0;
	mur->j = 0;
	mur->x = 0;
	mur->y = 0;
	mur->relative_path = "./includes/wall.xpm";
	mur->img = mlx_xpm_file_to_image(mlx->mlx, mur->relative_path,
			&mur->img_width, &mur->img_height);
	return (mur);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:37:52 by vpolojie          #+#    #+#             */
/*   Updated: 2022/09/28 10:20:11 by vpolojie         ###   ########.fr       */
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

int	get_next_line_v2(int fd)
{
	static char			buffer[1 +1];
	char				*line;
	int					rd;
	int					i;

	rd = 1;
	line = NULL;
	i = 0;
	line = ft_calloc(line, 1, sizeof(char));
	line = ft_strjoin(line, buffer);
	while (ft_check(buffer) == 0 && rd > 0)
	{
		rd = read(fd, buffer, 1);
		if ((rd == -1) || (rd == 0 && line && line[0] == '\0'))
		{
			free(line);
			return (0);
		}	
		buffer[rd] = 0;
		line = ft_strjoin(line, buffer);
	}
	line = ft_cut_line(line, buffer, i);
	free(line);
	return (1);
}

int	ft_check_wasd(int keycode, t_mlx *mlx)
{
	int	i;

	i = mlx->nb_pas;
	if (keycode == 53)
	{
		free(mlx->map);
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		exit(EXIT_SUCCESS);
	}
	if (keycode != 0 && keycode != 1 && keycode != 2 && keycode != 13)
		return (0);
	mlx->i = ((mlx->y) / 32);
	mlx->j = ((mlx->x) / 32);
	ft_wasd_loop(mlx, keycode);
	if (i != mlx->nb_pas)
		ft_printf("%d \n", mlx->nb_pas);
	return (0);
}
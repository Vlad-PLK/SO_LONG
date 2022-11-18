/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:34:30 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/18 10:51:19 by vpolojie         ###   ########.fr       */
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

int	ft_map_size_check(char **map_lines, int nb_lines)
{
	int	i;

	i = 0;
	if (nb_lines == 3)
	{
		while (i != nb_lines)
		{
			if (ft_strlen(map_lines[i]) - 1 >= 5)
				i++;
			else
				return (0);
		}
	}
	else if (nb_lines == 4)
	{
		i = 0;
		while (i != nb_lines)
		{
			if (ft_strlen(map_lines[i]) - 1 >= 4)
				i++;
			else
				return (0);
		}
	}
	return (1);
}

void	ft_map_empty_line_check(char **map_lines, int nb_lines)
{
	int	i;

	i = 0;
	while (i != nb_lines)
	{
		if (ft_strlen(map_lines[i]) == 1)
			ft_exit_func("EMPTY LINE DETECTED");
		i++;
	}
}

int	ft_map_check(char **map_lines, int nb_lines)
{
	ft_map_empty_line_check(map_lines, nb_lines);
	if (ft_map_size_check(map_lines, nb_lines) != 1)
		ft_exit_func("MAP TOO SMALL, NEED AT LEAST 3*5 or 4*4");
	if (ft_map_rect_check(map_lines, nb_lines) != 1)
		ft_exit_func("MAP IS NOT OBLONGUE");
	if (ft_map_one_lst_check(map_lines, nb_lines) != 1)
		ft_exit_func("MAP NOT CLOSED CORRECTLY");
	if (ft_map_check_cara(map_lines, nb_lines) != 1)
		ft_exit_func("MAP NOT CLOSED CORRECTLY");
	if (ft_find_path(map_lines, nb_lines) == -1)
		ft_exit_func("NO CLEAR PATH TO EXIT OR BLOCKED COLLECTIBLES");
	return (1);
}

void	ft_map_init(char **map_lines, int i, int line, int fd)
{
	map_lines = (char **)malloc(sizeof(char *) * (i +1));
	map_lines[i +1] = 0;
	while (i != 0)
	{
		map_lines[line] = get_next_line(fd);
		line++;
		i--;
	}
	close(fd);
	if (ft_map_check(map_lines, line) == 1)
		ft_display_map(map_lines, line);
}

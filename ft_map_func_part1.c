/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_func_part1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:34:30 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/04 10:11:41 by vpolojie         ###   ########.fr       */
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

int	ft_check_extension(char *arg)
{
	int	i;

	i = (int)ft_strlen(arg);
	if (arg[i -4] == '.' && arg[i -3] == 'b'
		&& arg[i -2] == 'e' && arg[i -1] == 'r')
		return (1);
	else
		return (-1);
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
	if (ft_map_check(map_lines, line) == 1)
		ft_display_map(map_lines, line);
	else
		ft_error_func(map_lines, line);
}

void	ft_error_func(char	**map, int nb_lines)
{
	int	i;

	i = 0;
	while (i != nb_lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

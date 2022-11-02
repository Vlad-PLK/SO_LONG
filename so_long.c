/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:02:27 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/05 09:00:55 by vpolojie         ###   ########.fr       */
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

void	so_long(char *map)
{
	int		fd;
	int		line;
	int		i;
	char	**map_lines;

	i = 0;
	line = 0;
	map_lines = NULL;
	if (ft_check_extension(map) == 1)
	{
		fd = open(map, O_RDONLY);
		while (get_next_line_v2(fd) != 0)
			i++;
		close(fd);
		fd = open(map, O_RDONLY);
		if (i >= 4)
			ft_map_init(map_lines, i, line, fd);
		else
			ft_error_func(map_lines);
	}
	else
		ft_error_func(map_lines);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
		ft_printf("Error\n");
}

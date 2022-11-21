/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:02:27 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/21 10:53:07 by vpolojie         ###   ########.fr       */
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

void	ft_exit_func(char *error_message)
{
	ft_printf("Error : %s\n", error_message);
	exit(EXIT_FAILURE);
}

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
		if (i >= 3)
			ft_map_init(map_lines, i, line, fd);
		else
			ft_exit_func("Map too small, please check your file");
	}
	else
		ft_exit_func("Extension issue, please check your file");
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else if (argc == 1)
		ft_printf("Error, no map passed\n");
	else
		ft_printf("Error, too many arguments\n");
}

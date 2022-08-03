/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:02:27 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/28 21:37:33 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
///#include "mlx.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <fcntl.h>

typedef struct	s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

/*int	main(void)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./test.xpm";
	int		img_width;
	int		img_height;
	void	*mlx_win;
	t_data	*img;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	//mlx_win = mlx_new_window(mlx, 500, 500, "Hello World!");
	///mlx_loop(mlx);
	//img.img = mlx_new_image(mlx, 500, 500);
	//img.addr = mlc_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
}*/

int		ft_check_extension(char *arg)
{
	int	i;

	i = (int)ft_strlen(arg);
	if (arg[i -4] == '.' && arg[i -3] == 'b'
		&& arg[i -2] == 'e' && arg[i -1] == 'r')
		return (1);
	else
		return (-1);
}

int		ft_map_check(char **map_lines, int nb_lines)
{
	int	j;
	int	k;
	int	i;

	j = 0;
	i = 0;

	while (j != nb_lines)
	{
		k = j +1;
		while (k != nb_lines)
		{
			if ((ft_strlen(map_lines[j]) == ft_strlen(map_lines[k]))
			&& (ft_strlen(map_lines[j]) -1) >= 4)
				k++;
			else
				return (0);
		}
		j++;
	}
	i = 0;
	while (i != (ft_strlen(map_lines[0]) -2))
	{
		if(map_lines[0][i] == '1' && map_lines[nb_lines -1][i] == '1')
			i++;
		else
			return (0);
	}
	i = 1;
	while (i != (nb_lines -1))
	{
		if (map_lines[i][0] == '1'
		&& map_lines[i][ft_strlen(map_lines[i]) -2] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

void	so_long(char *map)
{
	int		fd;
	int		i;
	int		line;
	char	**map_lines;

	i = 0;
	line = 0;
	if (ft_check_extension(map) == 1)
	{
		fd = open(map, O_RDONLY);
		while(get_next_line(fd) != NULL)
			i++;
		close(fd);
		fd = open(map, O_RDONLY);
		if (i >= 4)
			map_lines = (char **)malloc(sizeof(char *) * (i +1));
		else
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		map_lines[i +1] = 0;
		while(i != 0)
		{
			map_lines[line] = ft_strdup(get_next_line(fd));
			line++;
			i--;
		}
		if (ft_map_check(map_lines, line) == 1)
			ft_printf("1\n");
		else
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
		ft_printf("Error\n");
}

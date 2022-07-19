/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:02:27 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/19 21:53:43 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
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
	int	fd;
	int	i;

	i = (int)ft_strlen(arg);
	if (arg[i -3] == '.' && arg[i -2] == 'b'
		&& arg[i -1] == 'e' && arg[i] == 'r')
	{
		fd = open(arg, O_RDONLY | O_DIRECTORY);
		if (fd > 0)
		{
			close(fd);
			return (-1);
		}
		else
		{
			fd = open(arg, O_RDONLY);
			return (fd);
		}
	}
	else
		return (-1);
}

void	so_long(char *map)
{
	if (ft_check_extension(map) != -1)
	{
		ft_printf("1\n");
	}
	else
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{	
	ft_printf("%d\n", ft_strlen(argv[1]));
	//so_long(argv[1]);
}

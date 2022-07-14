/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:02:27 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/14 11:20:30 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

typedef struct	s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}t_data;

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;

	mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 500, 500, "Hello World!");
	///mlx_loop(mlx);
	img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlc_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

}

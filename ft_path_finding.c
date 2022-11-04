/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:35:35 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/04 09:21:41 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <stdbool.h>
#include <fcntl.h>

void	ft_initialize_values(t_data *d, char **map_lines, int nb_lines)
{
	d->x = 0;
	d->y = 0;
	d->collcts = 0;
	d->j = 0;
	d->k = 0;
	d->row = nb_lines;
	d->col = ft_strlen(map_lines[nb_lines -1]) - 1;
	d->new_x = 0;
	d->new_y = 0;
	d->i = 0;
	d->reached_end = false;
	d->dr[0] = -1;
	d->dr[1] = +1;
	d->dr[2] = 0;
	d->dr[3] = 0;
	d->dc[0] = 0;
	d->dc[1] = 0;
	d->dc[2] = +1;
	d->dc[3] = -1;
}

bool	**create_visited_map(char **map, int nb, t_data *data)
{
	data->k = 0;
	data->v_map = (bool **)malloc(sizeof(bool *) * nb);
	while (data->k != nb)
	{
		data->v_map[data->k] = (bool *)malloc(sizeof(bool)
				* (ft_strlen(map[nb -1]) - 1));
		data->k++;
	}
	data->k = 0;
	while (data->k != data->row)
	{
		data->j = 0;
		while (data->j != data->col)
		{
			data->v_map[data->k][data->j] = false;
			data->j++;
		}
		data->k++;
	}
	return (data->v_map);
}

void	ft_check_neighbours(t_data *data, char **map, t_queue *rq, t_queue *cq)
{
	data->i = 0;
	while (data->i < 4)
	{
		data->new_x = data->x + data->dr[data->i];
		data->new_y = data->y + data->dc[data->i];
		if ((data->row >= data->new_x && data->new_x >= 0)
			&& (data->col >= data->new_y && data->new_y >= 0)
			&& (data->v_map[data->new_x][data->new_y] == false)
			&& (map[data->new_x][data->new_y] != '1'))
		{
			if (map[data->new_x][data->new_y] == 'C')
				data->collcts--;
			ft_enqueue(rq, data->new_x);
			ft_enqueue(cq, data->new_y);
			data->v_map[data->new_x][data->new_y] = true;
		}
		data->i++;
	}
}

void	ft_bfs_algo(t_queue *rq, t_queue *cq, t_data *data, char **map_lines)
{
	while (!(isempty(rq)))
	{
		data->x = ft_dequeue(rq);
		data->y = ft_dequeue(cq);
		if (data->v_map[data->end_i][data->end_j] == true && data->collcts == 0)
		{
			data->reached_end = true;
			break ;
		}
		ft_check_neighbours(data, map_lines, rq, cq);
	}
}

int	ft_find_path(char **map_lines, int n)
{
	t_data	data;
	t_queue	*rq;
	t_queue	*cq;

	data.v_map = NULL;
	ft_initialize_values(&data, map_lines, n);
	ft_starting_cell(&data, map_lines, n);
	data.v_map = create_visited_map(map_lines, n, &data);
	rq = malloc(sizeof(t_queue));
	cq = malloc(sizeof(t_queue));
	initialize(rq);
	initialize(cq);
	ft_enqueue(rq, data.player_i);
	ft_enqueue(cq, data.player_j);
	data.v_map[data.player_i][data.player_j] = true;
	ft_bfs_algo(rq, cq, &data, map_lines);
	ft_free_path_finding(rq, cq, &data, n);
	if (data.reached_end == true)
		return (1);
	return (-1);
}

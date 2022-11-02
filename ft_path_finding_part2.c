/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finding_part2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:35:26 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/06 10:48:19 by vpolojie         ###   ########.fr       */
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

void	ft_starting_cell(t_data *data, char **map_lines, int nb_lines)
{
	int	i;
	int	j;

	i = 0;
	while (i != nb_lines)
	{
		j = 0;
		while (j != (ft_strlen(map_lines[i]) - 1))
		{
			if (map_lines[i][j] == 'P')
			{
				data->player_i = i;
				data->player_j = j;
			}
			if (map_lines[i][j] == 'E')
			{
				data->end_i = i;
				data->end_j = j;
			}
			if (map_lines[i][j] == 'C')
				data->collcts++;
			j++;
		}
		i++;
	}
}

void	initialize(t_queue *q)
{
	q->count = 0;
	q->front = NULL;
	q->rear = NULL;
}

int	isempty(t_queue *q)
{
	return (q->front == NULL);
}

int	ft_dequeue(t_queue *q)
{
	t_node	*tmp;
	int		int_tmp;

	int_tmp = q->front->data;
	tmp = q->front;
	q->front = q->front->next;
	q->count--;
	free(tmp);
	return (int_tmp);
}

void	ft_enqueue(t_queue *q, int value)
{
	t_node	*tmp;

	tmp = malloc(sizeof(t_node));
	tmp->data = value;
	tmp->next = NULL;
	if (isempty(q))
	{
		q->front = q->rear;
		q->front = tmp;
		q->rear = tmp;
	}
	else
	{
		q->rear->next = tmp;
		q->rear = tmp;
	}
	q->count++;
}

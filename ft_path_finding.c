/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:40:28 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/03 11:32:23 by vpolojie         ###   ########.fr       */
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

void    ft_starting_cell(t_data *data, char **map_lines, int nb_lines)
{
    data->i = 0;
    while (data->i != nb_lines)
    {   
        data->j = 0;
        while (data->j != (ft_strlen(map_lines[data->i]) -1))
        {
            if (map_lines[data->i][data->j] == 'P')
            {
                data->player_i = data->i;
                data->player_j = data->j;
            }
            if (map_lines[data->i][data->j] == 'E')
            {
                data->exit_i = data->i;
                data->exit_j = data->j;
            }
            data->j++;
        }
        data->i++;
    }
}

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size_max = size;
    stack->top_index = size;
	stack->tableau = (int *)malloc(sizeof(int) * size);
	return (stack);
}

void    enqueue(t_stack *queue, int pos)
{
    queue->top_index--;
    queue->tableau[queue->top_index] = pos;
}

int dequeue(t_stack *queue)
{
    int pos;

    pos = queue->tableau[queue->top_index];
    queue->top_index++;
    return (pos);
}

int ft_find_path(char **map_lines, int nb_lines)
{
    t_data data;
    t_stack *rq;
    t_stack *cq;
    int r;
    int c;
    int R = nb_lines;;
    int C = ft_strlen(map_lines[nb_lines -1]) -1;
    int dr[4] = {-1, +1, 0, 0};
    int dc[4] = {0, 0, +1 , -1};
    int rr;
    int cc;
    int i;
    bool reached_end = false;
    bool visited_map[R][C];

    ft_starting_cell(&data, map_lines, nb_lines);;
    rq = create_stack(R * C);
    cq = create_stack(R * C);

    enqueue(rq, data.player_i);
    enqueue(cq, data.player_j);
    visited_map[data.player_i][data.player_j] = true;
    while ((rq->size_max - rq->top_index) > 0)
    {
        r = dequeue(rq);
        c = dequeue(cq);

        if (map_lines[r][c] == 'E')
        {
            reached_end = true;
            break;
        }
        for(i = 0; i < 4; i++)
        {
            rr = r + dr[i];
            cc = c + dc[i];
            if (rr < 0 || cc < 0)
                continue;
            if (rr >= R || cc >= C)
                continue;
            if (visited_map[rr][cc] == true)
                continue;
            if (map_lines[rr][cc] == '1')
                continue;
            enqueue(rq, rr);
            enqueue(cq, cc);
            visited_map[rr][cc] = true;
        }
    }
    free(rq);
    free(cq);
    if (reached_end == true)
        return (1);
    return (-1);
}
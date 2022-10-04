/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_finding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:40:28 by vpolojie          #+#    #+#             */
/*   Updated: 2022/10/04 12:14:49 by vpolojie         ###   ########.fr       */
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

void    initialize(t_queue *q)
{
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
}

int isempty(t_queue *q)
{
    return (q->front == NULL);
}

int ft_dequeue(t_queue *q)
{
    t_node *tmp;
    int int_tmp;

    int_tmp = q->front->data;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
    return (int_tmp);

}

void    ft_enqueue(t_queue *q, int value)
{
    t_node *tmp;

    tmp = malloc(sizeof(t_node));
    tmp->data = value;
    tmp->next = NULL;
    if (isempty(q))
        q->front = q->rear = tmp;
    else
    {
        q->rear->next = tmp;
        q->rear = tmp;
    }
    q->count++;
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

int	is_empty(t_stack *stack)
{
	if (stack->top_index == stack->size_max)
		return (1);
	else
		return (-1);
}

void display(t_node *head)
{
    if(head == NULL)
    {
        ft_printf("NULL\n");
    }
    else
    {
        ft_printf("%d\n", head -> data);
        display(head->next);
    }
}


int ft_find_path(char **map_lines, int nb_lines)
{
    t_data data;
    t_queue *rq;
    t_queue *cq;
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
    rq = malloc(sizeof(t_queue));
    cq = malloc(sizeof(t_queue));
    initialize(rq);
    initialize(cq);

    ft_enqueue(rq, data.player_i);
    ft_enqueue(cq, data.player_j);
    visited_map[data.player_i][data.player_j] = true;
    while (!(isempty(rq)))
    {
        r = ft_dequeue(rq);
        c = ft_dequeue(cq);
        ft_printf("r = %d, c = %d\n", r, c);
        if (map_lines[r][c] == 'E')
        {
            reached_end = true;
            break;
        }
        for(i = 0; i < 4; i++)
        {
            rr = r + dr[i];
            cc = c + dc[i];
            if ((R >= rr && rr > 0) && (C >= cc && cc > 0) &&
                (visited_map[rr][cc] == false) && (map_lines[rr][cc] != '1'))
            {
                ft_enqueue(rq, rr);
                ft_enqueue(cq, cc);
                visited_map[rr][cc] = true;
                ft_printf("rr = %d, cc = %d\n", rr, cc);
            }
        }
    }
    free(rq);
    free(cq);
    if (reached_end == true)
        return (1);
    return (-1);
}
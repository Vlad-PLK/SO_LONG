/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:47:55 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/17 11:49:11 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx/mlx.h"
#include "printf/ft_printf.h"
#include "printf/libft/libft.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <fcntl.h>

int	ft_map_rect_check(char **map_lines, int nb_lines)
{
	int	j;
	int	k;

	j = 0;
	while (j != nb_lines)
	{
		k = j +1;
		while (k != nb_lines)
		{
			if ((ft_strlen(map_lines[j]) == ft_strlen(map_lines[k]))
				&& (ft_strlen(map_lines[j])) >= 4)
				k++;
			else
				return (0);
		}
		j++;
	}
	return (1);
}

int	ft_map_one_lst_check(char **map_lines, int nb_lines)
{
	int	i;

	i = 0;
	while (i != (ft_strlen(map_lines[nb_lines -1]) - 1))
	{
		if (map_lines[0][i] == '1' && map_lines[nb_lines -1][i] == '1')
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_map_check_cara2(char **map_lines, t_ele *ele)
{
	if (map_lines[ele->i][ele->j] == 'C' || map_lines[ele->i][ele->j] == 'P'
		|| map_lines[ele->i][ele->j] == 'E' || map_lines[ele->i][ele->j] == '1'
		|| map_lines[ele->i][ele->j] == '0')
	{
		if (map_lines[ele->i][ele->j] == 'C')
			ele->items++;
		if (map_lines[ele->i][ele->j] == 'P')
			ele->pos++;
		if (map_lines[ele->i][ele->j] == 'E')
			ele->e_xit++;
		ele->j++;
	}
	else
		ft_exit_func("INCORRECT ELEMENT DETECTED");
}

void	ft_map_check_items(t_ele *ele)
{
	if (ele->items == 0)
		ft_exit_func("NO COLLECTIBLES DETECTED, NEED ONE AT LEAST");
	if (ele->pos == 0)
		ft_exit_func("NO PLAYER, SHOULD BE ONE");
	if (ele->e_xit == 0)
		ft_exit_func("NO EXIT, SHOULD BE ONE");
	if (ele->pos > 1)
		ft_exit_func("TOO MANY PLAYERS, SHOULD BE ONE");
	if (ele->e_xit > 1)
		ft_exit_func("TOO MANY EXITS, SHOULD BE ONE");
}

int	ft_map_check_cara(char **map_lines, int nb_lines)
{
	t_ele	ele;

	ele.i = 1;
	ele.items = 0;
	ele.pos = 0;
	ele.e_xit = 0;
	while (ele.i != (nb_lines -1))
	{
		if (map_lines[ele.i][0] == '1'
			&& map_lines[ele.i][ft_strlen(map_lines[ele.i]) - 2] == '1')
		{	
			ele.j = 1;
			while (ele.j != (ft_strlen(map_lines[ele.i]) - 2))
				ft_map_check_cara2(map_lines, &ele);
			ele.i++;
		}
		else
			return (0);
	}
	ft_map_check_items(&ele);
	return (1);
}

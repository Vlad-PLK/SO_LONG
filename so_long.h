/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 15:48:42 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/18 11:49:08 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}t_node;

typedef struct s_queue
{
	int		count;
	t_node	*front;
	t_node	*rear;
}t_queue;

typedef struct s_data
{
	int		player_i;
	int		player_j;
	int		end_i;
	int		end_j;
	int		collcts;
	int		x;
	int		y;
	int		i;
	int		j;
	int		k;
	int		row;
	int		col;
	int		new_x;
	int		new_y;
	int		dr[4];
	int		dc[4];
	bool	reached_end;
	bool	**v_map;
}t_data;

typedef struct s_ele
{
	int	items;
	int	pos;
	int	e_xit;
	int	i;
	int	j;
}t_ele;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		x_door;
	int		y_door;
	int		x_prev;
	int		y_prev;
	int		i;
	int		j;
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		items;
	char	**map;
	int		nb_pas;
}t_mlx;

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
	int		x;
	int		y;
	int		i;
	int		j;
}t_img;

int		ft_map_check(char **map_lines, int nb_lines);
int		ft_check_extension(char *arg);
int		ft_map_rect_check(char **map_lines, int nb_lines);
int		ft_map_one_lst_check(char **map_lines, int nb_lines);
int		ft_map_check_cara(char **map_lines, int nb_lines);
int		ft_close_mouse(t_mlx *mlx);
int		ft_loop_cara(t_mlx *mlx);
int		get_next_line_v2(int fd);
int		ft_check_wasd(int keycode, t_mlx *mlx);
int		ft_find_path(char **map_lines, int nb_lines);
int		isempty(t_queue *q);
int		ft_dequeue(t_queue *q);
t_img	*ft_door(t_mlx *mlx);
t_img	*ft_collct(t_mlx *mlx);
t_img	*ft_floor(t_mlx *mlx);
t_img	*ft_wall(t_mlx *mlx);
void	ft_map_init(char **map_lines, int i, int line, int fd);
void	end_map_condition(t_mlx *mlx, t_img *door);
void	ending_message(t_mlx *mlx);
void	ft_free_wasd_show_result(t_mlx *mlx, t_img *door);
void	ft_wasd_move_part2(int keycode, t_mlx *mlx, t_img *door);
void	ft_wasd_move(int keycode, t_mlx *mlx, t_img *door);
void	ft_wasd_loop(t_mlx *mlx, int keycode);
void	ft_error_func(char **map);
void	ft_display_map(char	**map, int nb_lines);
void	ft_display_others(t_mlx *mlx, t_img *mur, char **map);
void	ft_display_all(t_mlx *mlx, t_img *mur, char **map);
void	ft_check_close(t_mlx *mlx);
void	ft_free_img(t_img *sol, t_img *collct, t_img *door);
void	so_long(char *map);
void	create_mlx(t_mlx *mlx, char **map_lines);
void	ft_starting_cell(t_data *data, char **map_lines, int nb_lines);
void	initialize(t_queue *q);
void	ft_enqueue(t_queue *q, int value);
void	ft_free_path_finding(t_data *data, int n);
void	ft_bfs_algo(t_queue *rq, t_queue *cq, t_data *data, char **map_lines);
void	ft_check_neighbours(t_data *data, char **map, t_queue *rq, t_queue *cq);
void	ft_exit_func(char *error_message);
bool	**create_visited_map(char **map, int nb, t_data *data);

#endif

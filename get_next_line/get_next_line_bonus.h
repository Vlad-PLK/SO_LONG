/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 20:42:21 by vpolojie          #+#    #+#             */
/*   Updated: 2022/05/23 20:50:04 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_len(char *str);
int		ft_check(char *str);
char	*ft_strcpy(char *dest, char *src);
void	*ft_calloc(char *line, size_t n, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_cut_line(char *line, char *buffer, int i);

#endif

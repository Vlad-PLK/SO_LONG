/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:42:30 by vpolojie          #+#    #+#             */
/*   Updated: 2022/07/24 18:30:39 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define GET_NEXT_LINE_H
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

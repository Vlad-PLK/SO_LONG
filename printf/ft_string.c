/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpolojie <vpolojie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 12:04:42 by vpolojie          #+#    #+#             */
/*   Updated: 2022/11/25 11:59:48 by vpolojie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_printf.h"

void	ft_string(va_list list_arg, size_t *nb_cara)
{
	char	*str;

	str = (char *)va_arg(list_arg, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	(*nb_cara) += ft_strlen(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:27:54 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_char_format(t_id *buff)
{
	int	w;
	int	l;

	w = (buff->size) ? buff->size->width : 0;
	l = (buff->data.data == NULL) ? 1 : ft_strlen(buff->s);
	if (buff->size)
	{
		if (w > l)
			init_width(buff);
	}
}

void		make_char_str(t_id *buff)
{
	int i;

	i = 0;
	buff->s = ft_strnew(1);
	if (buff->data.data == NULL)
	{
		buff->s[0] = 0;
	}
	else
		buff->s[0] = (char)buff->data.data;
	init_char_format(buff);
}

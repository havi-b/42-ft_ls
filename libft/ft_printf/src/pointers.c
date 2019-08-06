/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 21:49:11 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_pntr_format(t_id *buff)
{
	int		w;
	int		l;

	w = (buff->size) ? buff->size->width : 0;
	l = ft_strlen(buff->s);
	if (buff->size)
	{
		if (buff->size && buff->size->prcsn > l)
		{
			init_prcsn(buff);
			l = ft_strlen(buff->s);
		}
		if (w > l)
			init_width(buff);
	}
	else
		buff->s = init_hash(buff->s, buff->id);
	if (!(ft_strchr(buff->s, 'x') || ft_strchr(buff->s, 'X')))
		buff->s = init_hash(buff->s, buff->id);
}

void		make_pntr_str(t_id *buff)
{
	int		upper;

	upper = (buff->id == 'P') ? 1 : 0;
	if (buff->data.data == 0 && buff->size && buff->size->dot && \
	buff->size->prcsn == 0)
		buff->s = ft_strjoin("", "\0");
	else
		buff->s = ft_itoa_base((intmax_t)buff->data.data, 16, upper);
	init_pntr_format(buff);
}

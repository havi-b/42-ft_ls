/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:29:09 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/25 14:17:16 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_flt_format(t_id *buff)
{
	int		w;
	int		l;

	w = (buff->size) ? buff->size->width : 0;
	l = ft_strlen(buff->s);
	if (buff->size)
	{
		if (w > l)
			init_width(buff);
	}
	else
	{
		if (buff->flags && buff->flags->pos_neg && buff->s[0] != '-')
			buff->s = init_pos_neg(buff->s);
	}
	if (buff->flags && buff->flags->space &&
		!buff->flags->pos_neg && !w && buff->s[0] != '-')
		buff->s = init_space(buff->s);
}

void		make_flt_str(t_id *buff)
{
	int		prcsn;

	prcsn = (buff->size && buff->size->prcsn > 0) ? buff->size->prcsn : 6;
	if ((buff->data.f || buff->data.u_lf) && !(buff->data.f == 0.000000 || \
	buff->data.u_lf == 0.000000))
	{
		buff->s = (buff->len && buff->len->u_l) ? \
		ft_ftoa(buff->data.u_lf, prcsn) : ft_ftoa(buff->data.f, prcsn);
	}
	else if (buff->data.f == 0.000000 || buff->data.u_lf == 0.000000)
		buff->s = ft_strdup("0.000000");
	init_flt_format(buff);
}

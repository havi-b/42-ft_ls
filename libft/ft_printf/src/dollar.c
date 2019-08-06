/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 20:05:37 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_va(t_id *buff, t_va *va, va_list args)
{
	va = first_va(va);
	init_va_id(buff, va);
	init_va_data(va, args);
	copy_va(buff, va);
	free_va(va);
}

void		copy_data(t_id *dst, t_id *src)
{
	if (isflt_id(dst->id) && isflt_id(dst->id))
	{
		if (dst->len && dst->len->u_l && dst->len && dst->len->u_l)
			dst->data.u_lf = (long double)src->data.u_lf;
		else
			dst->data.f = src->data.f;
	}
	else
		dst->data.data = src->data.data;
}

void		init_dollar(t_id *buff, va_list args)
{
	t_id	*temp;
	t_id	*find;
	t_va	*va;

	temp = buff;
	find = NULL;
	va = NULL;
	while (temp)
	{
		if (temp->dollar)
		{
			find = buff;
			while (find && find->va_index != temp->dollar)
				find = find->next;
			if (find)
				copy_data(temp, find);
			if (!find && !va)
				va = make_va(buff);
		}
		temp = temp->next;
	}
	if (va)
		init_va(buff, va, args);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 00:10:13 by havi              #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		route(t_id *buff)
{
	if (buff->size && buff->size->width < 0)
		fix_width(buff);
	if (isint_id(buff->id))
		make_int_str(buff);
	else if (isuint_id(buff->id))
		make_uint_str(buff);
	else if (isflt_id(buff->id))
		make_flt_str(buff);
	else if (buff->id == 'c')
		make_char_str(buff);
	else if (buff->id == 's')
		make_str_str(buff);
	else if (ispntr_id(buff->id))
		make_pntr_str(buff);
	else if (buff->id == '%')
		make_percent_str(buff);
}

t_id		*validate(t_id *buff)
{
	t_id	*temp;
	int		spaces;
	int		l;

	temp = buff;
	while (temp)
	{
		if (temp->id)
			route(temp);
		spaces = (temp->space) ? ft_strlen(temp->space) : 0;
		l = (temp->s) ? ft_strlen(temp->s) : 0;
		temp->n = l + spaces;
		temp->n += (temp->id == 'c' && temp->data.data == NULL) ? 1 : 0;
		temp = temp->next;
		if (buff->id && buff->id == 'n')
			make_n(buff);
	}
	return (buff);
}

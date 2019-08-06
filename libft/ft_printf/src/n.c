/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 20:30:07 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		make_n(t_id *buff)
{
	t_id	*temp;
	int		*ptr;
	int		n;

	ptr = (int *)buff->data.data;
	temp = buff;
	n = 0;
	while (temp)
	{
		n += temp->n;
		temp = temp->prev;
	}
	*ptr = n;
}

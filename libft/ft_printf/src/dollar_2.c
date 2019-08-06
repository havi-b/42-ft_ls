/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 23:43:09 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		get_va_len(t_id *buff, int *n, int *va_len)
{
	t_id	*temp;

	temp = buff;
	while (temp)
	{
		if (temp->va_index && temp->va_index > *n)
			*n = temp->va_index;
		if (temp->dollar && temp->dollar > *va_len)
			*va_len = temp->dollar;
		temp = temp->next;
	}
}

t_va		*make_va(t_id *buff)
{
	t_va	*va;
	int		va_len;
	int		n;

	n = 0;
	va_len = 0;
	va = NULL;
	get_va_len(buff, &n, &va_len);
	while (n < va_len)
	{
		if (!va)
			va = new_va();
		else
			va = add_va(va);
		va->va_index = n + 1;
		n++;
	}
	return (va);
}

void		init_va_id(t_id *buff, t_va *va)
{
	t_id	*temp;
	t_va	*tmp;

	temp = buff;
	tmp = va;
	while (temp)
	{
		if (temp->dollar && !temp->data.data)
		{
			tmp = goto_va(temp->dollar, tmp);
			tmp->id = temp->id;
			if (temp->len)
				tmp->len = temp->len;
		}
		temp = temp->next;
	}
}

void		init_va_data(t_va *va, va_list args)
{
	t_va	*temp;

	temp = va;
	while (temp)
	{
		if (isflt_id(temp->id))
		{
			if (temp->len && temp->len->u_l)
				temp->data.u_lf = va_arg(args, long double);
			else
				temp->data.f = va_arg(args, double);
		}
		else
			temp->data.data = va_arg(args, void *);
		temp = temp->next;
	}
}

void		copy_va(t_id *buff, t_va *va)
{
	t_id	*temp;
	t_va	*tmp;

	temp = buff;
	tmp = va;
	while (temp)
	{
		if (temp->dollar && !temp->data.data)
		{
			tmp = goto_va(temp->dollar, tmp);
			if (isflt_id(temp->id) && isflt_id(tmp->id))
			{
				if (temp->len && temp->len->u_l && tmp->len && tmp->len->u_l)
					temp->data.u_lf = (long double)tmp->data.u_lf;
				else
					temp->data.f = tmp->data.f;
			}
			else
				temp->data.data = tmp->data.data;
		}
		temp = temp->next;
	}
}

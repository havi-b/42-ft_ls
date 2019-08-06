/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 23:41:21 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_va		*new_va(void)
{
	t_va	*va;

	if (!(va = (t_va *)malloc(sizeof(t_va))))
		return (NULL);
	va->prev = NULL;
	va->va_index = 0;
	va->data.data = NULL;
	va->id = 0;
	va->len = NULL;
	va->next = NULL;
	return (va);
}

t_va		*add_va(t_va *va)
{
	t_va	*new;

	new = new_va();
	new->prev = va;
	va->next = new;
	va = va->next;
	return (va);
}

t_va		*first_va(t_va *va)
{
	while (va->prev)
		va = va->prev;
	return (va);
}

t_va		*goto_va(int i, t_va *va)
{
	if (va->va_index > i)
	{
		while (va->va_index != i)
			va = va->prev;
	}
	else if (va->va_index < i)
	{
		while (va->va_index != i)
			va = va->next;
	}
	return (va);
}

void		free_va(t_va *va)
{
	t_va	*temp;

	while (va)
	{
		temp = va->next;
		if (va->len)
			va->len = NULL;
		free(va);
		va = temp;
	}
}

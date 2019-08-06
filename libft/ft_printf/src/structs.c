/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 23:58:24 by havi              #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_id		*new_node(void)
{
	t_id	*buff;

	if (!(buff = (t_id *)malloc(sizeof(t_id))))
		return (NULL);
	buff->prev = NULL;
	buff->index = 0;
	buff->va_index = 0;
	buff->dollar = 0;
	buff->data.data = NULL;
	buff->s = NULL;
	buff->n = 0;
	buff->id = 0;
	buff->space = NULL;
	buff->flags = NULL;
	buff->size = NULL;
	buff->len = NULL;
	buff->next = NULL;
	return (buff);
}

t_id		*add_node(t_id *buff)
{
	t_id	*new;

	new = new_node();
	new->index = buff->index + 1;
	new->prev = buff;
	buff->next = new;
	buff = buff->next;
	return (buff);
}

t_id		*first_node(t_id *buff)
{
	while (buff->index > 0 && buff->prev != NULL)
		buff = buff->prev;
	return (buff);
}

t_id		*goto_index(t_id *buff, int i)
{
	buff = first_node(buff);
	while (buff->index < i)
		buff = buff->next;
	return (buff);
}

void		free_list(t_id *buff)
{
	t_id	*temp;

	while (buff)
	{
		temp = buff->next;
		if (buff->s)
			free(buff->s);
		if (buff->space)
			free(buff->space);
		if (buff->flags)
			free(buff->flags);
		if (buff->size)
			free(buff->size);
		if (buff->len)
			free(buff->len);
		free(buff);
		buff = temp;
	}
}

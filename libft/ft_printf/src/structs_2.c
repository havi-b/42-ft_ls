/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 12:41:05 by havi              #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_flags		*new_flags(void)
{
	t_flags	*flags;

	flags = NULL;
	if (!(flags = (t_flags *)malloc(sizeof(t_flags))))
		return (NULL);
	flags->left_just = 0;
	flags->padding = 0;
	flags->pos_neg = 0;
	flags->hash = 0;
	flags->space = 0;
	return (flags);
}

t_size		*new_size(void)
{
	t_size	*size;

	size = NULL;
	if (!(size = (t_size *)malloc(sizeof(t_size))))
		return (NULL);
	size->width = 0;
	size->dot = 0;
	size->prcsn = 0;
	return (size);
}

t_len		*new_len(void)
{
	t_len	*len;

	if (!(len = (t_len *)malloc(sizeof(t_len))))
		return (NULL);
	len->h = 0;
	len->hh = 0;
	len->l = 0;
	len->ll = 0;
	len->j = 0;
	len->z = 0;
	len->u_l = 0;
	return (len);
}

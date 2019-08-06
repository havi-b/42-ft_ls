/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 08:06:56 by havi              #+#    #+#             */
/*   Updated: 2019/07/12 16:46:04 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ls_max_namelen(t_file *file)
{
	t_file	*tmp;
	int		l;
	int		r;

	r = 0;
	tmp = file;
	while (tmp)
	{
		if ((l = ft_strlen(tmp->name)) > r)
			r = l;
		tmp = tmp->next;
	}
	l = r / 2;
	l += (r % 2) ? 1 : 0;
	return ((l * 2) + 1);
}

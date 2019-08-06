/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:27:32 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/25 19:35:21 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_str_prcsn(t_id *buff)
{
	char	*s;
	char	*temp;
	int		i;
	int		l;

	i = 0;
	temp = buff->s;
	l = buff->size->prcsn;
	s = ft_strnew(l);
	while (i < l)
	{
		s[i] = buff->s[i];
		i++;
	}
	s[i] = '\0';
	buff->s = s;
	free(temp);
}

void		init_str_format(t_id *buff)
{
	int		w;
	int		p;
	int		l;

	w = (buff->size) ? buff->size->width : 0;
	p = (buff->size) ? buff->size->prcsn : 0;
	l = ft_strlen(buff->s);
	if (buff->size)
	{
		if (p < l && p > 0)
		{
			init_str_prcsn(buff);
			l = ft_strlen(buff->s);
		}
		if (w > l)
			init_width(buff);
	}
}

void		make_str_str(t_id *buff)
{
	if (buff->size && buff->size->dot && buff->size->prcsn == 0)
		buff->s = ft_strjoin("\0", "");
	else if (buff->data.data == NULL)
		buff->s = ft_strjoin("(null)", "\0");
	else
		buff->s = ft_strjoin((char *)buff->data.data, "\0");
	if (buff->s)
		init_str_format(buff);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:47:10 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*init_pos_neg(char *s)
{
	char	*temp;

	temp = s;
	s = ft_strjoin("+\0", temp);
	free(temp);
	return (s);
}

void		check_pos_neg(t_id *buff)
{
	if (isint_id(buff->id) && buff->flags &&
	buff->flags->pos_neg && !(ft_strchr(buff->s, '+') \
	|| ft_strchr(buff->s, '-')))
		buff->s = init_pos_neg(buff->s);
}

void		init_padding(t_id *buff)
{
	int		i;
	int		s;

	i = 0;
	s = 0;
	if (((buff->flags && buff->flags->pos_neg) || \
	((int)buff->data.data < 0 || buff->data.f < 0)) && \
	(isint_id(buff->id) || isflt_id(buff->id)))
	{
		while (!is_plusminus(buff->s[s]))
			s++;
		buff->s[i++] = buff->s[s];
		buff->s[s] = '0';
	}
	if (is_valid_hash(buff))
	{
		while (!(buff->s[s] == 'x' || buff->s[s] == 'X'))
			s++;
		buff->s[0] = '0';
		buff->s[1] = buff->s[s];
		buff->s[s] = '0';
		i = 2;
	}
	while (buff->s[i] == ' ')
		buff->s[i++] = '0';
}

void		check_padding(t_id *buff)
{
	if (isflt_id(buff->id))
		init_padding(buff);
	else if (ispntr_id(buff->id))
		init_padding(buff);
	else if (((!buff->size->prcsn || buff->size->prcsn < 0) \
	|| ((intmax_t)buff->data.data < 0 && \
	buff->size->prcsn + 1 == buff->size->width)) && \
	!(isint_id(buff->id) && ft_strlen(buff->s) == (size_t)buff->size->width \
	&& buff->s[0] != ' ' && buff->flags->pos_neg))
		init_padding(buff);
}

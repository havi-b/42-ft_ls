/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:11:49 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		init_width(t_id *buff)
{
	char	*s;
	char	*temp;
	int		i;
	int		l;

	i = 0;
	if (((isint_id(buff->id) && !buff->size->prcsn) || isflt_id(buff->id)) &&
	buff->flags && buff->flags->pos_neg && buff->s[0] != '-')
		buff->s = init_pos_neg(buff->s);
	if (isuint_id(buff->id) || ispntr_id(buff->id))
		check_hash(buff);
	temp = buff->s;
	l = (buff->data.data == NULL && buff->id == 'c') ? \
	buff->size->width - 1 : buff->size->width - ft_strlen(buff->s);
	s = ft_strnew(l);
	while (i < l)
		s[i++] = ' ';
	s[i] = '\0';
	buff->s = (buff->flags && buff->flags->left_just) ? ft_strjoin(temp, s) : \
	ft_strjoin(s, temp);
	if (buff->flags && buff->flags->padding && !buff->flags->left_just)
		check_padding(buff);
	free(temp);
	free(s);
}

void		init_prcsn(t_id *buff)
{
	char	*s;
	char	*temp;
	int		i;
	int		l;

	i = 0;
	temp = buff->s;
	l = (temp[0] == '-') ? (buff->size->prcsn - ft_strlen(temp)) + 2 : \
	buff->size->prcsn - ft_strlen(temp);
	s = ft_strnew(l);
	if (temp[0] == '-')
		s[i++] = temp[0];
	while (i < l)
		s[i++] = '0';
	s[i] = '\0';
	buff->s = (temp[0] == '-') ? ft_strjoin(s, &temp[1]) : ft_strjoin(s, temp);
	free(temp);
	free(s);
	if (buff->flags && buff->flags->pos_neg && isint_id(buff->id) &&
		buff->s[0] != '-')
		buff->s = init_pos_neg(buff->s);
	else if ((is_valid_hash(buff) && (intmax_t)buff->data.data > 0) && \
	!((buff->id == 'o' || buff->id == 'O') && \
	(size_t)buff->size->prcsn == ft_strlen(buff->s)))
		buff->s = init_hash(buff->s, buff->id);
}

void		fix_width(t_id *buff)
{
	if (!buff->flags)
		buff->flags = new_flags();
	buff->flags->left_just = 1;
	buff->size->width *= -1;
}

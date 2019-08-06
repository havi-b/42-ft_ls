/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uints.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:24:05 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/09 00:17:33 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				init_uint_format(t_id *buff)
{
	int				w;
	int				p;
	int				l;

	w = (buff->size) ? buff->size->width : 0;
	p = (buff->size) ? buff->size->prcsn : 0;
	l = ft_strlen(buff->s);
	if (buff->size)
	{
		if (buff->size->prcsn > l)
		{
			init_prcsn(buff);
			l = ft_strlen(buff->s);
		}
		if (buff->size->width > l)
			init_width(buff);
		if (w == 0 && p == 0 && (int)buff->data.data > 0)
			buff->s = init_hash(buff->s, buff->id);
	}
	else
	{
		if (is_valid_hash(buff) && (intmax_t)buff->data.data > 0)
			buff->s = init_hash(buff->s, buff->id);
	}
}

char				*init_uint_len(t_len *len, void *n, int base, int upper)
{
	char			*s;

	s = NULL;
	if (len->h)
		s = ft_itoa_base((unsigned short)n, base, upper);
	else if (len->hh)
		s = ft_itoa_base((unsigned char)n, base, upper);
	else if (len->l)
		s = ft_itoa_base((unsigned long)n, base, upper);
	else if (len->ll)
		s = ft_itoa_base((unsigned long long)n, base, upper);
	else if (len->j)
		s = ft_itoa_base((uintmax_t)n, base, upper);
	else if (len->z)
		s = ft_itoa_base((size_t)n, base, upper);
	return (s);
}

void				make_uint_str(t_id *buff)
{
	int				base;
	int				upper;
	unsigned long	n;

	base = 10;
	upper = (isupper_id(buff->id)) ? 1 : 0;
	n = (unsigned int)buff->data.data;
	if (buff->size && !buff->size->prcsn && buff->size->dot &&
		(intmax_t)buff->data.data == 0 &&
		!(buff->flags && buff->flags->hash && buff->id == 'o'))
		buff->s = ft_strjoin("", "\0");
	else if (buff->id == 'O' || buff->id == 'U')
		buff->s = (buff->id == 'O') ? \
		ft_itoa_base((unsigned long)buff->data.data, 8, upper) : \
		ft_itoa_base((unsigned long)buff->data.data, base, upper);
	else
	{
		if (buff->id == 'o' || buff->id == 'x' || buff->id == 'X')
			base = (buff->id == 'o') ? 8 : 16;
		buff->s = (buff->len && !buff->len->u_l) ? \
		init_uint_len(buff->len, buff->data.data, base, upper) : \
		ft_itoa_base(n, base, upper);
	}
	init_uint_format(buff);
}

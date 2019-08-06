/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:09:00 by havi              #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_id		*parse_id(const char *restrict format, va_list args, int *i, \
			t_id *buff)
{
	if (!buff->dollar && !(format[*i] == '%'))
	{
		if (isflt_id(format[*i]))
		{
			if (buff->len && buff->len->u_l)
				buff->data.u_lf = va_arg(args, long double);
			else
				buff->data.f = va_arg(args, double);
		}
		else
			buff->data.data = va_arg(args, void *);
	}
	buff->id = format[*i];
	*i += 1;
	return (buff);
}

t_len		*parse_len(const char *restrict format, int *i)
{
	t_len	*len;

	if (!(len = new_len()))
		return (NULL);
	len->l = (format[*i] == 'l' && format[*i + 1] != 'l') ? 1 : 0;
	len->ll = (format[*i] == 'l' && format[*i + 1] == 'l') ? 1 : 0;
	len->h = (format[*i] == 'h' && format[*i + 1] != 'h') ? 1 : 0;
	len->hh = (format[*i] == 'h' && format[*i + 1] == 'h') ? 1 : 0;
	len->j = (format[*i] == 'j') ? 1 : 0;
	len->z = (format[*i] == 'z') ? 1 : 0;
	len->u_l = (format[*i] == 'L') ? 1 : 0;
	*i += (len->hh == 1 || len->ll == 1) ? 2 : 1;
	return (len);
}

t_flags		*parse_flags(const char *restrict format, int *i)
{
	t_flags	*flags;

	if (!(flags = new_flags()))
		return (NULL);
	while (isflag(format[*i]) == 1)
	{
		if (format[*i] == '-')
			flags->left_just = 1;
		else if (format[*i] == '0')
			flags->padding = 1;
		else if (format[*i] == '+')
			flags->pos_neg = 1;
		else if (format[*i] == '#')
			flags->hash = 1;
		else if (format[*i] == ' ')
			flags->space = 1;
		*i += 1;
		if (format[*i] == ' ')
		{
			while (format[*i] == ' ')
				*i += 1;
		}
	}
	return (flags);
}

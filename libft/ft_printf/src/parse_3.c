/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 09:11:32 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		parse_width(const char *restrict format, va_list args, \
			int *i, t_size *size)
{
	if (format[*i] == '*')
		init_wildcard(format, i, &size->width, args);
	while (ft_isdigit(format[*i]))
	{
		size->width = size->width * 10 + (format[*i] - '0');
		*i += 1;
	}
}

void		parse_prcsn(const char *restrict format, va_list args, \
			int *i, t_size *size)
{
	int n;

	n = 0;
	*i += 1;
	if (format[*i] == '*')
		init_wildcard(format, i, &size->prcsn, args);
	else if (format[*i] == '-')
	{
		*i += 1;
		while (ft_isdigit(format[*i]) == 1)
		{
			n = n * 10 + (format[*i] - '0');
			*i += 1;
		}
		size->width = n * -1;
	}
	else
	{
		while (ft_isdigit(format[*i]) == 1)
		{
			size->prcsn = size->prcsn * 10 + (format[*i] - '0');
			*i += 1;
		}
	}
}

t_size		*parse_size(const char *restrict format, va_list args, int *i)
{
	t_size	*size;

	if (!(size = new_size()))
		return (NULL);
	parse_width(format, args, i, size);
	if (format[*i] == '.')
	{
		size->dot = 1;
		parse_prcsn(format, args, i, size);
	}
	return (size);
}

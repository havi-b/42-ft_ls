/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 16:03:24 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:57:08 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_char_str(t_id *buff)
{
	int l;

	l = (buff->space) ? buff->n - ft_strlen(buff->space) : buff->n;
	if (buff->data.data == NULL && buff->size && buff->size->width && \
	buff->flags && buff->flags->left_just)
	{
		ft_putchar('\0');
		l--;
	}
	ft_putnstr(buff->s, l);
}

int			print_strings(t_id *buff)
{
	t_id	*temp;
	int		n;

	n = 0;
	temp = buff;
	while (temp)
	{
		if (temp->id == 'c' && temp->data.data == NULL)
			print_char_str(temp);
		else if (temp->s)
			ft_putstr(temp->s);
		if (temp->space)
			ft_putstr(temp->space);
		n += temp->n;
		temp = temp->next;
	}
	return (n);
}

t_id		*make_buff(const char *restrict format, va_list args, int *i)
{
	t_id	*buff;

	buff = NULL;
	while (format[*i])
	{
		if (!buff)
			buff = new_node();
		else
			buff = add_node(buff);
		if (format[*i] != '%')
			buff = parse_string(format, i, buff);
		else
		{
			*i += 1;
			if (is_valid_fmt(format, i))
				buff = parse(format, args, i, buff);
		}
	}
	return (buff);
}

int			ft_printf(const char *restrict format, ...)
{
	t_id		*buff;
	va_list		ap;
	int			i;
	int			n;

	i = 0;
	n = 0;
	va_start(ap, format);
	buff = make_buff(format, ap, &i);
	if (buff)
	{
		buff = first_node(buff);
		init_dollar(buff, ap);
		buff = validate(buff);
		n = print_strings(buff);
		free_list(buff);
	}
	va_end(ap);
	return (n);
}

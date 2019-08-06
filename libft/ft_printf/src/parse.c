/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 00:08:29 by havi              #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_id		*parse_string(const char *restrict format, int *i, t_id *buff)
{
	int		k;

	k = *i;
	while (format[k] != '%' && format[k] != '\0')
		k++;
	k -= *i;
	buff->s = (char *)malloc(sizeof(char) * k + 1);
	buff->s = ft_strncpy(buff->s, &format[*i], k);
	buff->s[k] = '\0';
	buff->id = 0;
	*i += k;
	return (buff);
}

char		*parse_space(const char *restrict format, int *i)
{
	char	*ret;
	int		s;

	s = *i;
	while (ft_isspace(format[s]) == 1)
		s++;
	s -= *i;
	ret = (char *)malloc(sizeof(char) * s + 1);
	ret = ft_strncpy(ret, &format[*i], s);
	ret[s] = '\0';
	*i += s;
	return (ret);
}

int			find_va_index(t_id *buff)
{
	t_id	*temp;

	temp = buff;
	while (!temp->va_index)
	{
		if (temp->prev == NULL)
			return (1);
		temp = temp->prev;
	}
	return (temp->va_index + 1);
}

t_id		*parse_arg_index(const char *restrict format, int *i, t_id *buff)
{
	int		n;
	int		k;

	k = *i;
	n = 0;
	while (ft_isdigit(format[k]))
	{
		n = n * 10 + (format[*i] - '0');
		k++;
	}
	if (format[k] == '$')
	{
		buff->dollar = n;
		k -= *i;
		*i += k + 1;
	}
	return (buff);
}

t_id		*parse(const char *restrict format, va_list args, int *i, \
			t_id *buff)
{
	if (ft_isdigit(format[*i]))
		buff = parse_arg_index(format, i, buff);
	if (!buff->dollar && format[*i] != '%')
		buff->va_index = find_va_index(buff);
	buff->flags = (isflag(format[*i]) == 1) ? parse_flags(format, i) : NULL;
	buff->size = ((ft_isdigit(format[*i]) == 1) || format[*i] == '.' || \
	format[*i] == '*') ? parse_size(format, args, i) : NULL;
	buff->len = (islen(format[*i]) == 1) ? parse_len(format, i) : NULL;
	if (is_id(format[*i]))
		buff = parse_id(format, args, i, buff);
	else
		return (NULL);
	buff->space = (ft_isspace(format[*i]) ? parse_space(format, i) : NULL);
	return (buff);
}

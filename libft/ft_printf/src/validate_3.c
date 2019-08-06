/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:07:35 by havi              #+#    #+#             */
/*   Updated: 2019/07/12 16:24:54 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			isuhash_id(char c)
{
	return (c == 'o' || c == 'O' || c == 'x' || c == 'X');
}

int			is_valid_hash(t_id *buff)
{
	return ((buff->flags && buff->flags->hash && isuhash_id(buff->id)) || \
			ispntr_id(buff->id));
}

int			is_valid_fmt(const char *restrict format, int *i)
{
	int		k;

	k = *i;
	while ((isflag(format[k]) || ft_isdigit(format[k]) || islen(format[k]) || \
	format[k] == '.' || format[k] == '$' || format[k] == '*') && \
	(format[k] != '\0' && format[k] != '\n'))
		k++;
	if (is_id(format[k]) == 1)
		return (1);
	else
	{
		while (format[*i] == ' ')
			*i += 1;
		return (0);
	}
}

int			isupper_id(char c)
{
	return (c == 'O' || c == 'U' || c == 'X');
}

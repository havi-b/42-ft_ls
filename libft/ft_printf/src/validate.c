/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 00:12:42 by havi              #+#    #+#             */
/*   Updated: 2019/07/12 16:23:45 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_id(char c)
{
	return (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || \
			c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'f' || \
			c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G' || \
			c == 'c' || c == 's' || c == 'p' || c == 'P' || c == 'n' || \
			c == '%');
}

int		notstring_id(char c)
{
	return (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || \
			c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'f' || \
			c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G' || \
			c == 'c' || c == 'p' || c == 'P' || c == 'n');
}

int		isnum_id(char c)
{
	return (c == 'D' || c == 'd' || c == 'i' || c == 'o' || c == 'O' || \
			c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'f' || \
			c == 'e' || c == 'E' || c == 'n');
}

int		isint_id(char c)
{
	return (c == 'd' || c == 'i');
}

int		isuint_id(char c)
{
	return (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || \
			c == 'X');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 04:52:14 by hbhuiyan          #+#    #+#             */
/*   Updated: 2018/11/11 04:52:16 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_isspace(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ');
}

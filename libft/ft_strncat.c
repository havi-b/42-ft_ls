/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 15:42:30 by hbhuiyan          #+#    #+#             */
/*   Updated: 2018/10/29 01:13:08 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t len;

	len = ft_strlen(s1);
	while (*s2 && n-- > 0)
		s1[len++] = *s2++;
	s1[len] = '\0';
	return (s1);
}

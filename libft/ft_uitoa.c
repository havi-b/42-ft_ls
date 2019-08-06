/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 15:17:08 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/05 17:18:48 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(uintmax_t n)
{
	char	*s;
	size_t	l;

	l = ft_uintlen(n);
	if (!(s = ft_strnew(l)))
		return (NULL);
	if (n == ULLONG_MAX)
		return (ft_strdup("18446744073709551615"));
	if (n == 0)
		*s = '0';
	while (n > 0)
	{
		s[--l] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

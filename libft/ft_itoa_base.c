/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:26:26 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/05 17:16:26 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(uintmax_t n, int base, int upper)
{
	char	*s;
	char	*tab;
	int		l;

	if (n == 0)
		return (ft_strjoin("0", "\0"));
	if (base < 2 || base > 16)
		return (NULL);
	else if (base == 10)
		return (ft_uitoa(n));
	l = ft_uintlen_base(n, base);
	if (!(s = ft_strnew(l)))
		return (NULL);
	tab = ft_strjoin("0123456789abcdef", "\0");
	s[l--] = '\0';
	while (n > 0)
	{
		s[l--] = (upper && ft_isalpha(tab[n % base])) ? \
		tab[n % base] - 32 : tab[n % base];
		n /= base;
	}
	ft_strdel(&tab);
	return (s);
}

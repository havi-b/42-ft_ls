/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:18:56 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/05 18:47:40 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*add_dot(char *n, size_t prcsn)
{
	char	*ret;
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(n);
	ret = ft_strnew(l + 1);
	while (i < (l - prcsn))
	{
		ret[i] = n[i];
		i++;
	}
	ret[i++] = '.';
	while (prcsn > 0)
	{
		ret[i++] = n[l - prcsn];
		prcsn--;
	}
	ret[i] = '\0';
	free(n);
	return (ret);
}

char		*add_zero(char *n, size_t zero)
{
	char	*zero_s;
	size_t	i;

	i = 0;
	zero_s = ft_strnew(zero);
	while (i < zero)
		zero_s[i++] = '0';
	return (ft_strmerge(zero_s, n));
}

void		fix_neg(char *n)
{
	char	*neg;
	int		i;

	i = 0;
	neg = ft_strchr(n, '-');
	while (n[i] != '-' && n[i])
		i++;
	if (neg)
	{
		n[i] = '0';
		n[0] = '-';
	}
}

char		*make_fstr(long double n, size_t prcsn, size_t *zero)
{
	size_t i;

	i = 0;
	*zero = (n < 1) ? 1 : 0;
	while (i++ < prcsn)
	{
		n *= 10;
		if (n < 1 && n > -1)
			*zero += 1;
	}
	if (n < 0)
		n -= .5;
	else
		n += .5;
	return (ft_itoa((intmax_t)n));
}

char		*ft_ftoa(long double n, size_t prcsn)
{
	char	*num;
	size_t	zero;

	num = make_fstr(n, prcsn, &zero);
	if (zero > prcsn)
		zero = prcsn;
	if (zero && n > -1)
		num = add_zero(num, zero);
	num = add_dot(num, prcsn);
	if (n < 0)
		fix_neg(num);
	return (num);
}

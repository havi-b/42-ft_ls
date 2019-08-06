/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 17:45:36 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/05 18:21:21 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_uintlen_base(uintmax_t n, int base)
{
	int		c;

	c = 0;
	while (n > 0)
	{
		n /= base;
		c++;
	}
	return (c);
}

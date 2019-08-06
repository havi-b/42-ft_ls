/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 01:15:01 by hbhuiyan          #+#    #+#             */
/*   Updated: 2018/11/13 01:15:02 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*t;

	if (!s)
		return (NULL);
	while (*s && ft_iswspace(*s))
		s++;
	i = ft_strlen(s) - 1;
	while (*s && ft_iswspace(s[i]))
		i--;
	if (!(t = ft_strnew(i + 1)))
		return (NULL);
	ft_strncpy(t, s, i + 1);
	return (t);
}

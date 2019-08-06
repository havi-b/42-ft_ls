/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlink.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 02:56:05 by havi              #+#    #+#             */
/*   Updated: 2019/07/12 16:26:18 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_readlink(char *path)
{
	char	buf[128];
	ssize_t len;
	ssize_t buffsize;

	buffsize = 128;
	buf[0] = ' ';
	buf[1] = '-';
	buf[2] = '>';
	buf[3] = ' ';
	if (!(len = readlink(path, &buf[4], (buffsize - 4))))
		exit(EXIT_FAILURE);
	buf[len + 4] = '\0';
	return (ft_strdup(buf));
}

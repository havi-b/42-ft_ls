/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percents.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 20:42:21 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		make_percent_str(t_id *buff)
{
	buff->s = ft_strjoin("%\0", "");
	init_int_format(buff);
}

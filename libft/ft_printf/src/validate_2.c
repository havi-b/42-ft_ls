/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:06:39 by havi              #+#    #+#             */
/*   Updated: 2019/06/23 10:59:24 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		isflt_id(char c)
{
	return (c == 'f' || c == 'F');
}

int		ispntr_id(char c)
{
	return (c == 'p' || c == 'P');
}

int		isflag(char c)
{
	return (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#');
}

int		islen(char c)
{
	return (c == 'l' || c == 'h' || c == 'L' || c == 'j' || c == 'z');
}

int		is_plusminus(char c)
{
	return (c == '+' || c == '-');
}

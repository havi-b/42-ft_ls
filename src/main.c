/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:36:20 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/12 19:25:17 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			main(int ac, char **av)
{
	int		flags;
	int		i;

	i = 1;
	flags = 0;
	if (!ls_parse_flags(ac, av, &flags, &i))
		return (1);
	return (ls_init(ac, av, &flags, &i));
}

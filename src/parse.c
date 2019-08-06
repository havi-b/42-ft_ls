/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 19:57:15 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/12 16:30:38 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ls_parse_flags(int ac, char **av, int *flags, int *i)
{
	int n;
	int k;

	k = 1;
	while (*i < ac && av[*i][0] == '-')
	{
		while (av[*i][k])
		{
			if ((n = ft_strchr_index("alrRt1", av[*i][k])) == -1)
				ls_error(&av[*i][k], USAGE);
			*flags |= (1 << n);
			k++;
		}
		*i += 1;
	}
	return (1);
}

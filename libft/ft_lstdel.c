/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 02:37:50 by hbhuiyan          #+#    #+#             */
/*   Updated: 2018/11/16 02:37:52 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*c;
	t_list	*n;

	c = *alst;
	while (c)
	{
		n = c->next;
		del((c->content), (c->content_size));
		free(c);
		c = n;
	}
	*alst = NULL;
}

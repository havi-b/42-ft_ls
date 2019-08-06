/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 05:17:48 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/12 19:13:46 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file		*ls_new_file(void)
{
	t_file	*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		ls_error("", MALL_ERR);
	file->prev = NULL;
	file->parent = NULL;
	file->child = NULL;
	file->path = NULL;
	file->name = NULL;
	file->next = NULL;
	return (file);
}

t_file		*ls_add_file(t_file *file)
{
	t_file	*new;

	new = ls_new_file();
	new->prev = file;
	file->next = new;
	file = file->next;
	return (file);
}

t_file		*ls_goto_first_file(t_file *file)
{
	while (file->prev != NULL)
		file = file->prev;
	return (file);
}

t_file		*ls_reverse_files(t_file *file)
{
	t_file *tmp;

	while (file)
	{
		tmp = file->next;
		file->next = file->prev;
		file->prev = tmp;
		if (file->prev)
			file = file->prev;
		else
			return (file);
	}
	return (file);
}

void		ls_free_files(t_file *file)
{
	t_file *tmp;

	if (file->prev)
		file = ls_goto_first_file(file);
	while (file)
	{
		tmp = file->next;
		free(file->path);
		free(file->name);
		if (file->child)
			ls_free_files(file->child);
		free(file);
		file = tmp;
	}
	file = NULL;
}

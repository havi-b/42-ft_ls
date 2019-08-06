/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 11:02:27 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/12 16:46:42 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_file		*ls_swap_files(t_file *file)
{
	t_file *next;

	next = file->next;
	file->next = next->next;
	next->prev = file->prev;
	file->prev = next;
	next->next = file;
	if (file->next)
		file->next->prev = file;
	if (next->prev)
		next->prev->next = next;
	file = file->prev;
	return (file);
}

t_file		*ls_sort_time(t_file *file)
{
	if (!file)
		return (NULL);
	if (file->next && \
	file->stat.st_mtimespec.tv_sec < file->next->stat.st_mtimespec.tv_sec)
		file = ls_swap_files(file);
	else if (file->next && \
	file->stat.st_mtimespec.tv_sec == file->next->stat.st_mtimespec.tv_sec)
	{
		if (file->next && \
		file->stat.st_mtimespec.tv_nsec < file->next->stat.st_mtimespec.tv_nsec)
			file = ls_swap_files(file);
	}
	file->next = ls_sort_time(file->next);
	return (file);
}

t_file		*ls_sort_alpha(t_file *file)
{
	if (!file)
		return (NULL);
	if (file->next && ft_strcmp(file->name, file->next->name) > 0)
		file = ls_swap_files(file);
	file->next = ls_sort_alpha(file->next);
	return (file);
}

t_file		*ls_sort_bubble(t_file *file, int *flags)
{
	int c;
	int i;

	i = 0;
	c = ls_file_count(file);
	while (i < c)
	{
		if (*flags & T_FLAG)
			file = ls_sort_time(file);
		else
			file = ls_sort_alpha(file);
		i++;
	}
	if (*flags & R_FLAG)
		file = ls_reverse_files(file);
	return (file);
}

t_file		*ls_sort_files(t_file *file, int *flags)
{
	t_file *tmp;

	file = ls_goto_first_file(file);
	file = ls_sort_bubble(file, flags);
	tmp = file;
	while (tmp)
	{
		if (tmp->child && !is_ls_hidden(tmp->name))
			tmp->child = ls_sort_files(tmp->child, flags);
		tmp = tmp->next;
	}
	return (file);
}

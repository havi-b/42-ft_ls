/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 09:45:06 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/15 23:56:28 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ls_print_l(t_file *file, int *flags)
{
	char *perms;
	char *t;

	printf("total %d\n", ls_get_total_blocks(file, flags));
	while (file)
	{
		if (S_ISLNK(file->stat.st_mode))
			file->name = ft_strmerge(file->name, ft_readlink(file->path));
		if (file && file->name[0] == '.' && !(*flags & A_FLAG))
			file = file->next;
		else
		{
			perms = ls_get_perms(file->stat.st_mode);
			perms = ls_check_xattr(file->path, perms);
			t = ft_strsub(ctime(&file->stat.st_mtime), (unsigned int)4, \
			(size_t)12);
			printf("%s %3d %-9.9s %-13.13s %6llu %12.12s %-32.*s\n", \
			perms, file->stat.st_nlink, getpwuid(file->stat.st_uid)->pw_name, \
			getgrgid(file->stat.st_gid)->gr_name, \
			file->stat.st_size, t, (int)ft_strlen(file->name), file->name);
			free(perms);
			free(t);
			file = file->next;
		}
	}
}

void		ls_print(t_file *file, int *flags)
{
	struct winsize	ws;
	int				col;
	int				i;
	int				l;

	ioctl(1, TIOCGWINSZ, &ws);
	l = ls_max_namelen(file);
	col = (*flags & ONE_FLAG) ? 1 : (ws.ws_col / l);
	while (file)
	{
		i = 0;
		while (file && file->name && i < col)
		{
			if (file && file->name[0] == '.' && !(*flags & A_FLAG))
				file = file->next;
			else
			{
				printf("%-*.*s", l, l, file->name);
				file = file->next;
				i++;
			}
		}
		printf("\n");
	}
}

void		ls_print_recurs(t_file *file, int *flags)
{
	t_file			*tmp;

	(*flags & L_FLAG) ? ls_print_l(file, flags) : ls_print(file, flags);
	tmp = file;
	while (tmp)
	{
		if (S_ISDIR(tmp->stat.st_mode) && !(tmp->name[0] == '.' && \
		!(*flags & A_FLAG)) && !is_ls_hidden(tmp->name))
		{
			printf("\n%s:\n", tmp->path);
			ls_print_recurs(tmp->child, flags);
		}
		tmp = tmp->next;
	}
}

void		ls_print_files(t_file *file, int *flags)
{
	if (*flags & RR_FLAG)
		ls_print_recurs(file, flags);
	else
		(*flags & L_FLAG) ? ls_print_l(file, flags) : ls_print(file, flags);
}

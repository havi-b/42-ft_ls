/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 04:22:23 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/07/15 23:56:51 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*ls_get_path(char *dir, char *file)
{
	int		l;
	char	*tmp;
	char	*ret;

	tmp = NULL;
	l = ft_strlen(dir);
	tmp = (dir[l - 1] == '/') ? ft_strdup(dir) : ft_strjoin(dir, "/");
	ret = ft_strjoin(tmp, file);
	free(tmp);
	return (ret);
}

t_file		*ls_init_file(char *dir, t_file *file, int *flags, t_file *parent)
{
	DIR				*dirp;
	struct dirent	*entry;

	if ((dirp = opendir(dir)) == NULL)
		ls_error(dir, ERRNO);
	else
	{
		while ((entry = readdir(dirp)) != NULL)
		{
			file = (file) ? ls_add_file(file) : ls_new_file();
			file->parent = parent;
			file->name = ft_strdup(entry->d_name);
			file->path = ls_get_path(dir, file->name);
			if (!(lstat(file->path, &file->stat) == 0) && (*flags & L_FLAG))
				ls_lstat_error(file);
			if (S_ISDIR(file->stat.st_mode) && !is_ls_hidden(file->name) && \
			*flags & RR_FLAG)
				file->child = ls_init_file(file->path, file->child, flags, \
				file);
		}
		closedir(dirp);
	}
	return (file);
}

int			ls_init(int ac, char **av, int *flags, int *i)
{
	t_file	*file;

	ac += (av[*i]) ? 0 : 1;
	if (!av[*i])
		av[*i] = "./";
	while (*i < ac)
	{
		file = NULL;
		if (!(file = ls_init_file(av[*i], file, flags, NULL)))
			return (1);
		if (!(file = ls_sort_files(file, flags)))
			return (1);
		if ((ac - *i) > 1)
			printf("%s:\n", av[*i]);
		else if (ft_strcmp(av[*i], "./") && !(is_ls_flag(av[*i - 1][1])) && \
		*i - 1 != 0)
			printf("%s:\n", av[*i]);
		ls_print_files(file, flags);
		if ((ac - *i) > 1)
			printf("\n");
		*i += 1;
		ls_free_files(file);
	}
	return (0);
}

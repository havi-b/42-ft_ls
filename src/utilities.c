/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 04:24:15 by havi              #+#    #+#             */
/*   Updated: 2019/07/12 16:34:13 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*ls_check_xattr(char *path, char *perms)
{
	char *tmp;

	tmp = perms;
	perms = listxattr(path, 0, 0, XATTR_NOFOLLOW) > 0 ? \
	ft_strjoin(tmp, "@") : ft_strjoin(tmp, " ");
	free(tmp);
	return (perms);
}

char		ls_get_filetype(mode_t st_mode)
{
	if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else if (S_ISFIFO(st_mode))
		return ('p');
	else if (S_ISLNK(st_mode))
		return ('l');
	else
		return ('-');
}

char		*ls_get_perms(mode_t st_mode)
{
	char	*perms;

	perms = ft_strnew(11);
	perms[0] = ls_get_filetype(st_mode);
	perms[1] = (st_mode & S_IRUSR) ? 'r' : '-';
	perms[2] = (st_mode & S_IWUSR) ? 'w' : '-';
	perms[3] = (st_mode & S_IXUSR) ? 'x' : '-';
	perms[4] = (st_mode & S_IRGRP) ? 'r' : '-';
	perms[5] = (st_mode & S_IWGRP) ? 'w' : '-';
	perms[6] = (st_mode & S_IXGRP) ? 'x' : '-';
	perms[7] = (st_mode & S_IROTH) ? 'r' : '-';
	perms[8] = (st_mode & S_IWOTH) ? 'w' : '-';
	perms[9] = (st_mode & S_IXOTH) ? 'x' : '-';
	perms[10] = '\0';
	if (st_mode & S_ISUID)
		perms[3] = (st_mode & S_IXUSR) ? 's' : 'S';
	if (st_mode & S_ISGID)
		perms[6] = (st_mode & S_IXGRP) ? 's' : 'l';
	if (st_mode & S_ISVTX)
		perms[9] = (st_mode & S_IXOTH) ? 't' : 'T';
	return (perms);
}

int			ls_get_total_blocks(t_file *file, int *flags)
{
	t_file	*tmp;
	int		blocks;

	tmp = file;
	blocks = 0;
	while (tmp)
	{
		if (!(*flags & A_FLAG) && tmp->name[0] != '.')
			blocks += tmp->stat.st_blocks;
		else if (*flags & A_FLAG)
			blocks += tmp->stat.st_blocks;
		tmp = tmp->next;
	}
	return (blocks);
}

int			ls_file_count(t_file *file)
{
	t_file	*tmp;
	int		c;

	c = 1;
	tmp = file;
	while (tmp->next)
	{
		c++;
		tmp = tmp->next;
	}
	return (c);
}

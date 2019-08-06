/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbhuiyan <hbhuiyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:52:58 by hbhuiyan          #+#    #+#             */
/*   Updated: 2019/08/05 19:01:35 by hbhuiyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		fill_line(char **file, char **line, int fd, int len)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (file[fd][i] != '\n' && file[fd][i] != '\0')
		i++;
	if (file[fd][i] == '\n')
	{
		*line = ft_strsub(file[fd], 0, i);
		tmp = ft_strdup(file[fd] + i + 1);
		free(file[fd]);
		file[fd] = tmp;
		if (file[fd][0] == '\0')
			ft_strdel(&file[fd]);
	}
	else if (file[fd][i] == '\0')
	{
		if (len == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(file[fd]);
		ft_strdel(&file[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char *file[9999];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			len;

	if (fd < 0 || !line)
		return (-1);
	while ((len = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[len] = '\0';
		if (file[fd] == NULL)
			file[fd] = ft_strnew(0);
		tmp = ft_strjoin(file[fd], buf);
		free(file[fd]);
		file[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (len < 0)
		return (-1);
	else if (len == 0 && (file[fd] == NULL || file[fd][0] == '\0'))
		return (0);
	return (fill_line(file, line, fd, len));
}

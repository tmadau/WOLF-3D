/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:36:21 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/29 10:20:41 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_reader(int fd, char **row, char **str)
{
	t_type		read;

	read.index = 0;
	while (str[fd][read.index] != EOL && str[fd][read.index] != EOS)
		read.index++;
	if (str[fd][read.index] == EOS)
	{
		*row = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	else if (str[fd][read.index] == EOL)
	{
		*row = ft_strsub(str[fd], 0, read.index);
		read.store = ft_strdup(&str[fd][read.index + 1]);
		free(str[fd]);
		str[fd] = read.store;
		if (str[fd][0] == EOS)
			ft_strdel(&str[fd]);
	}
	return (LRD);
}

int		get_next_line(const int fd, char **line)
{
	static t_type	read_fd;

	if (fd < 0 || line == NULL)
		return (ERR);
	while ((read_fd.ret = read(fd, read_fd.buff, BUFF_SIZE)) > 0)
	{
		read_fd.buff[read_fd.ret] = EOS;
		if (read_fd.stock[fd] == NULL)
			read_fd.stock[fd] = ft_strnew(1);
		read_fd.store = ft_strjoin(read_fd.stock[fd], read_fd.buff);
		free(read_fd.stock[fd]);
		read_fd.stock[fd] = read_fd.store;
		if (ft_strchr(read_fd.buff, EOL))
			break ;
	}
	if (read_fd.ret < 0)
		return (ERR);
	else if (read_fd.ret == 0 && (read_fd.stock[fd] == NULL
				|| read_fd.stock[fd][0] == EOS))
		return (RDC);
	return (line_reader(fd, line, read_fd.stock));
}

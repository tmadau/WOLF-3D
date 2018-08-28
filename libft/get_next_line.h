/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 12:22:21 by tmadau            #+#    #+#             */
/*   Updated: 2018/08/11 15:50:02 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 32
# define EOL '\n'
# define EOS '\0'
# define ERR -1
# define LRD 1
# define RDC 0

typedef	struct	s_type
{
	char		buff[BUFF_SIZE + 1];
	char		*stock[1];
	char		*store;
	int			ret;
	int			index;
}				t_type;

int				get_next_line(const int fd, char **line);

#endif

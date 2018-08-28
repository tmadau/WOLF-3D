/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmadau <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:27:35 by tmadau            #+#    #+#             */
/*   Updated: 2018/06/15 11:32:48 by tmadau           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*flink;

	flink = (t_list *)malloc(sizeof(*flink));
	if (flink == NULL)
		return (NULL);
	if (!content)
	{
		flink->content = NULL;
		flink->content = 0;
	}
	else
	{
		if (!(flink->content = malloc(content_size)))
			return (NULL);
		ft_memcpy(flink->content, content, content_size);
		flink->content_size = content_size;
	}
	flink->next = NULL;
	return (flink);
}

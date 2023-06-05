/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:25:54 by ckojima-          #+#    #+#             */
/*   Updated: 2023/05/21 19:18:57 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	stash[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*stored;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		ft_bzero(stash[fd]);
		return (NULL);
	}
	stored = NULL;
	while (stash[fd][0] || read(fd, stash[fd], BUFFER_SIZE) > 0)
	{
		stored = joinline(stored, stash[fd]);
		if (newline(stash[fd]) == 1)
			break ;
	}
	return (stored);
}

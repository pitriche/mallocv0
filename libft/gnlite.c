/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:02:10 by pitriche          #+#    #+#             */
/*   Updated: 2019/05/08 16:52:33 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int		isolate(char **line, char *str)
{
	char *next_line;

	if (!str)
		return (0);
	if (!*str)
		return (0);
	if (!(next_line = ft_strchr(str, '\n')))
	{
		*line = ft_strdup(str);
		*str = 0;
	}
	else
	{
		if (!(*line = ft_strnew(next_line - str)))
			return (-1);
		ft_strncpy(*line, str, next_line - str);
		ft_strcpy(str, next_line + 1);
	}
	return (1);
}

static int		read_fd(int fd, char **str)
{
	char	buf[BUFF_SIZE + 1];
	char	*content;
	int		ret;

	ft_bzero(buf, BUFF_SIZE + 1);
	ret = 0;
	if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
		return (ret);
	content = *str;
	if (!(*str = ft_strjoin(content, buf)))
	{
		free(content);
		return (-1);
	}
	free(content);
	return (ret);
}

/*
** gnlite
** read one line in a file descriptor but optimized. Only one FD
** -
** takes the fd and a pointer to the pointer where the line will be stored
** return 1 if a line was read, 0 if there is no more lines to read (aka read
** return 0) and -1 if read encounters an error or one of the mallocs fails
*/

int				gnlite(const int fd, char **line)
{
	static char	*str;
	int			ret;

	while (!ft_strchr(str, '\n'))
	{
		ret = read_fd(fd, &str);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
	}
	return (isolate(line, str));
}

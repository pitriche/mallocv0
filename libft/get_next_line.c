/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pitriche <pitriche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:13:45 by pitriche          #+#    #+#             */
/*   Updated: 2019/03/18 17:26:01 by pitriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

/*
** isolate [TESTED]
** find the line to be returned from the static list, duplicates it and store
** it in line, then move backward the string the length of the picked string
** plus the newline. If no characters are left an empty string will be
** allocated.
** -
** takes a pointer to the line string and the current part of the static list
** return 1 if a line was cut, 0 if the string is empty and -1 if the malloc
** fails
*/

static int		isolate(char **line, t_list *cur)
{
	char *next_line;

	if (!*(char *)cur->data)
		return (0);
	if (!(next_line = ft_strchr((char *)cur->data, '\n')))
	{
		if (!(*line = ft_strdup((char *)cur->data)))
			return (-1);
		free(cur->data);
		if (!(cur->data = (void *)ft_strnew(0)))
			return (-1);
	}
	else
	{
		if (!(*line = ft_strnew(next_line - (char *)cur->data)))
			return (-1);
		ft_strncpy(*line, (char *)cur->data, next_line -
		(char *)cur->data);
		ft_strcpy((char *)cur->data, next_line + 1);
	}
	return (1);
}

/*
** read_fd [untested]
** read the fd one buffer, then merge the read line in the static list.
** -
** takes the fd to read and the current part of the static list
** return the read's return, and -1 if malloc fails.
*/

static int		read_fd(int fd, t_list *cur)
{
	char	*buf;
	char	*content;
	int		ret;

	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
	{
		free((void *)buf);
		return (ret);
	}
	content = (char *)cur->data;
	if (!(cur->data = (void *)ft_strjoin(cur->data, buf)))
	{
		free((void *)buf);
		return (-1);
	}
	free((void *)content);
	free((void *)buf);
	return (ret);
}

/*
** fd_find [TESTED / MODIFIED]
** finds the corresponding element in the static list. If no element correspond
** to the fd, one is created
** -
** takes the fd, the static list and a pointer to the static list
** return the corresponding element, and 0 if malloc fails.
*/

static t_list	*fd_find(int fd, t_list *list, t_list **root)
{
	t_list *tmp;

	if (!list)
	{
		if (!(tmp = ft_lstnew_empty()))
			return (0);
		if (!(tmp->data = (void *)ft_strnew(0)))
			return (0);
		tmp->d_size = (size_t)fd;
		ft_lstadd(root, tmp);
		return (*root);
	}
	if ((int)list->d_size == fd)
		return (list);
	else
		return (fd_find(fd, list->next, root));
}

/*
** get_next_line [TESTED]
** read one line in a file descriptor
** -
** takes the fd and a pointer to the pointer where the line shall be stored
** return 1 if a line was read, 0 if there is no more lines to read (aka read
** return 0) and -1 if read encounters an error or one of the mallocs fails
*/

int				get_next_line(const int fd, char **line)
{
	static t_list	*list;
	t_list			*cur;
	int				ret;

	if (!(cur = fd_find(fd, list, &list)))
		return (-1);
	while (!ft_strchr(cur->data, '\n'))
	{
		ret = read_fd(fd, cur);
		if (ret < 0)
			return (-1);
		if (ret == 0)
			break ;
	}
	return (isolate(line, cur));
}

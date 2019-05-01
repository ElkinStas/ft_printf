/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhudson <bhudson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 12:25:27 by bhudson           #+#    #+#             */
/*   Updated: 2019/03/26 11:47:56 by bhudson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int		check(int fd, char ***line, char **masfd)
{
	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	if (!*masfd && (*masfd = (char *)ft_memalloc(sizeof(char))) == NULL)
		return (-1);
	else
		return (1);
}

static void		clean(char **masfd, char **find, int *i)
{
	*find = ft_strdup(*(find) + *i);
	free(*masfd);
	*masfd = *find;
}

static int		bigger(int const fd, char **stock)
{
	char	buff[BUFF_SIZE + 1];
	int		read_bytes;
	char	*nstr;

	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		nstr = ft_strjoin(*stock, buff);
		if (!nstr)
			return (-1);
		free(*stock);
		*stock = nstr;
	}
	return (read_bytes);
}

int				get_next_line(int const fd, char **line)
{
	char		*find;
	int			ret;
	int			i;
	static char *masfd[10240];

	if ((i = 1) && check(fd, &line, &masfd[fd]) < 0)
		return (-1);
	find = ft_strchr(masfd[fd], '\n');
	while (find == NULL)
	{
		if (!(ret = bigger(fd, &masfd[fd])))
		{
			i = 0;
			if ((find = ft_strchr(masfd[fd], '\0')) == masfd[fd])
				return (0);
		}
		else if (ret < 0)
			return (-1);
		else
			find = ft_strchr(masfd[fd], '\n');
	}
	if (!(*line = ft_strsub(masfd[fd], 0, find - masfd[fd])))
		return (0);
	clean(&masfd[fd], &find, &i);
	return (1);
}

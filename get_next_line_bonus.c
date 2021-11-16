/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:34:49 by mikabuto          #+#    #+#             */
/*   Updated: 2021/11/11 19:17:40 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int set_buf(char *rmd, char **buf)
{
	if (rmd)
		*buf = ft_strdup(rmd);
	else
		*buf = ft_strdup("");
	if (!(*buf))
		return (0);
	return (1);
}

static int	read_file(int fd, char **buf, char **rmd)
{
	int		r;
	int		n;
	char	*tmp;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (-2);
	n = ft_strchr_int(*buf, '\n');
	r = BUFFER_SIZE;
	while (n == -1 && r == BUFFER_SIZE)
	{
		r = read(fd, (void *)tmp, BUFFER_SIZE);
		if (r == -1)
		{
			free(tmp);
			return (-2);
		}
		tmp[r] = '\0';
		*buf = ft_strjoin(*buf, tmp);
		n = ft_strchr_int(*buf, '\n');
	}
	*rmd = ft_strjoin(*rmd, *buf);
	free(tmp);
	return (n);
}

static void	case_no_nl(int n, char **buf, char **rmd)
{
	if (n == -1)
	{
		if(!((*buf)[0]))
		{
			free(*buf);
			*buf = NULL;
		}
		free(*rmd);
		*rmd = NULL;
	}
}

char	*get_next_line(int fd)
{
	static char	*rmd[FOPEN_MAX];
	char		*buf;
	int			n;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > FOPEN_MAX)
		return (NULL);
	if (!set_buf(rmd[fd], &buf))
		return (NULL);
	n = read_file(fd, &buf, &(rmd[fd]));
	if (n != -1 && n != -2)
	{
		if (rmd[fd])
			free(rmd[fd]);
		rmd[fd] = ft_strdup((const char *)&buf[n + 1]);
		buf[n + 1] = '\0';
	}
	if (n == -2)
	{
		if (rmd[fd])
			free(rmd[fd]);
		free(buf);
		return (NULL);
	}
	case_no_nl(n, &buf, &(rmd[fd]));
	return (buf);
}

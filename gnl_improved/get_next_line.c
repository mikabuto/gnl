/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:34:49 by mikabuto          #+#    #+#             */
/*   Updated: 2021/11/22 20:41:40 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	set_buf(char *rmd, char **buf)
{
	if (rmd)
	{
		*buf = ft_strdup(rmd);
		free(rmd);
		rmd = NULL;
	}
	else
		*buf = ft_strdup("");
	if (!(*buf))
		return (0);
	return (1);
}

static int	read_file(int fd, char **buf)
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
	free(tmp);
	return (n);
}

static void	case_no_nl(int n, char **buf, char **rmd)
{
	if (n == -1)
	{
		if (!((*buf)[0]))
		{
			free(*buf);
			*buf = NULL;
		}
		*rmd = NULL;
	}
}

static char	*reset_buf(char *buf, char *rmd, int n)
{
	int		i;
	char	*ret;

	i = -1;
	if (!buf)
		return (NULL);
	if (!rmd)
	{
		free(buf);
		return (NULL);
	}
	ret = (char *)malloc(n + 2);
	if (!ret)
		return (NULL);
	while (++i < (n + 1))
		ret[i] = buf[i];
	ret[i] = '\0';
	free(buf);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*rmd = NULL;
	char		*buf;
	int			n;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	if (!set_buf(rmd, &buf))
		return (NULL);
	n = read_file(fd, &buf);
	if (n != -1 && n != -2)
	{
		rmd = ft_strdup((const char *)&buf[n + 1]);
		buf = reset_buf(buf, rmd, n);
	}
	if (n == -2)
	{
		free(buf);
		return (NULL);
	}
	case_no_nl(n, &buf, &rmd);
	return (buf);
}

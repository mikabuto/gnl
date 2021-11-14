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

#include "get_next_line.h"

char	*add_str(char *buf, char *tmp)
{
	char	*meow;

	meow = ft_strjoin((const char *)buf, (const char *)tmp);
	free(buf);
	return (meow);
}

char	*case_rmd(char *rmd, char *tmp)
{
	char	*buf;

	if (rmd)
		buf = ft_strjoin(rmd, tmp);
	else
		buf = ft_strdup(tmp);
	return (buf);
}

int	read_file(int fd, char **tmp, char **buf, int *n, char **rmd)
{
	int	r;

	r = read(fd, (void *)(*tmp), BUFFER_SIZE);
	(*tmp)[r] = '\0';
	*buf = add_str(*buf, *tmp);
	*n = ft_strchr_int(*buf, '\n');
	*rmd = add_str(*rmd, *buf);
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*rmd = NULL;
	char		*buf;
	char		*tmp;
	int			r;
	int			n;

	tmp = (char *)malloc(BUFFER_SIZE + 1);
	r = read(fd, (void *)tmp, BUFFER_SIZE);
	tmp[r] = '\0';
	buf = case_rmd(rmd, tmp);
	n = ft_strchr_int(buf, '\n');
	while (n == -1 && r == BUFFER_SIZE)
		r = read_file(fd, &tmp, &buf, &n, &rmd);
	free(tmp);
	if (n != -1)
	{
		rmd = ft_strdup((const char *)&buf[n + 1]);
		buf[n + 1] = '\0';
	}
	if (!r && rmd && n == -1)
	{
		if (buf[0])
			buf = add_str(buf, "\n");
		free(rmd);
		rmd = NULL;
	}
	return (buf);
}

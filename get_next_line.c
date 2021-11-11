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

char	*get_next_line(int fd)
{
	static char	*rmd;
	char		*buf;
	int			r;
	int			n;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	rmd = NULL;
	r = read(fd, (void *)buf, BUFFER_SIZE);
	buf[r] = '\0';
	if (rmd)
		buf = ft_strjoin(rmd, buf);
	n = ft_strchr_int(buf, '\n');
	if (n < ft_strlen(buf))
	{
		buf += n;
		rmd = ft_strdup((const char *)buf);
	}
	return (buf);
}

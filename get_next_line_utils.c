/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikabuto <mikabuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:34:47 by mikabuto          #+#    #+#             */
/*   Updated: 2021/11/11 19:15:40 by mikabuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		i;

	i = -1;
	ret = (char *)malloc(ft_strlen(s1) + 1);
	if (!ret)
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}

int	ft_strchr_int(const char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
	{
		if (s[i] == (char)c)
			return (i);
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = (char *)malloc(s1_len + s2_len + 1);
	if (!s)
		return (NULL);
	while (s1[++i])
		s[i] = s1[i];
	while (*s2)
		s[i++] = *s2++;
	s[i] = '\0';
	free(s1);
	return (s);
}

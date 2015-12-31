/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 11:30:30 by eleclet           #+#    #+#             */
/*   Updated: 2015/12/31 16:26:58 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		n(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			return (i + 1);
		}
		i++;
	}
	return (i);
}
void	join_buff(char **s, char **buff)
{
	char *tmp0;
	char *tmp1;

	tmp0 = NULL;
	tmp1 = NULL;

	if (*buff && **buff)
	{
		tmp1 = ft_strdup(*buff);
		if (*s)
		{
			tmp0 = ft_strdup(*s);
			free(*s);
		}
		*s = ft_strjoin(tmp0, tmp1);
		if (tmp0)
			free(tmp0);
		if (tmp1)
			free(tmp1);
	}
}
int		rline(char **s, char **buff, char **line)
{
	int i;
	char *tmp;

	tmp = NULL;
	*line = NULL;
	i = n(*s);
	*line = ft_strdup(*s);
	tmp = ft_strdup(*s + i);
	free(*s);
	*s = tmp;
	if (buff)
		free(*buff), *buff = NULL;
	return (1);
}
int		get_next_line(int fd, char **line)
{
	static char *s = NULL;
	char *buff;
	int r;
	
	if (fd <= 0 || !line || BUFF_SIZE < 1)
		return(-1);
	if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	ft_bzero(buff, BUFF_SIZE + 1);
	while (((r = read(fd, buff, BUFF_SIZE)) > 0 ) && !ft_strchr(buff, '\n'))
		buff[r] = '\0',	join_buff(&s, &buff);
	if (r < 0)
		return (-1);
	if (buff && *buff && r > 0)
		buff[r] = '\0', join_buff(&s, &buff);
	if (s && s[0] != '\0')
		return (rline(&s, &buff, line));
	if (buff)
		free(buff), buff = NULL;
	ft_strdel(&s);
	*line = NULL;
	return (0);
}

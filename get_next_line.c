/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:18:05 by eleclet           #+#    #+#             */
/*   Updated: 2015/12/29 18:31:21 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		n(char *s)
{
	int i;

	i = 0;
	while (s && s[i] != '\n' && s[i] != '\0')
		i++;
	return (i);
}
char	*split(char *s,char **line)
{
	char *ret;
	char *tmp;
	
	tmp = NULL;
	*line = NULL;
	ft_strdel(&tmp);
	if (!(ret = (char *)malloc(n(s) + 1)))
		return ("");
	ft_bzero(ret, n(s) + 1);
	ft_strncpy(ret, s, n(s));
	*line = ret;
	if (s[n(s)] == '\0')
		return (ft_strdup(""));
	tmp = ft_strdup((s + n(s) + 1));
	ft_strdel(&s);
	ft_strdel(&ret);
	s = &tmp[0];
	return (s);

}
int		get_next_line(int fd,char **line)
{
	static char *s = NULL;
	char buff[BUFF_SIZE + 1];
	int ret;
	
	ft_bzero(buff, BUFF_SIZE + 1);
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while (((ret = read(fd, buff, BUFF_SIZE)) > 0 ) && !ft_strchr(buff, '\n') &&
			ft_strchr(buff, '\0'))
		buff[ret] = '\0', s = ft_strjoin(s , buff);
	if (ret < 0)
		return (-1);
	if (ft_strchr(buff, '\n'))
		buff[ret] = '\0', s = ft_strjoin(s, buff);
	if (!ret && !ft_strlen(s))
	{	
		if (s)
			free(s) , s = NULL;
		line = NULL;
		return (0);
	}
	if (!(s = split(s, line)))
		return (0);
	return (1);
}

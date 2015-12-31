/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:27:57 by eleclet           #+#    #+#             */
/*   Updated: 2015/12/31 16:27:07 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 19
#include "libft/libft.h"
#include <stdio.h>

int		get_next_line(int const fd, char **line);
int	es_read(int fd, char **line);
char	*split(char *s,char **line);
int		n(char *s);
#endif

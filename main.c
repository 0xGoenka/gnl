/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 19:20:20 by eleclet           #+#    #+#             */
/*   Updated: 2015/12/29 17:46:03 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"
int	main(int argc, char **argv)
{
	int fd;
	char *line;
	int ret;	
	fd = open(argv[1], O_RDONLY);
	int i;

	i = 0;
	while (i < ft_atoi(argv[2]))
	{
		ret = get_next_line(fd, &line);
		printf("******line %s\n", line);
		printf("ret = %d\n", ret);
		i++;
	}
	//printf ("line %s \n", line);
	//ft_strdel(&line);
	//while (1);
	return (0);
}

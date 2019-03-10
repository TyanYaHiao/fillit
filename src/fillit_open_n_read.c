/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:24:44 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 19:20:34 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				fillit_open(int argc, char **argv, int *fd)
{
	if (argc < 2)
	{
		ft_putendl("Usage: ./fillit source_file");
		return (0);
	}
	if ((*fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putendl("error");
		return (0);
	}
	return (1);
}

int				fillit_read(int *fd, int *num, char **tetriminos)
{
	int			number;
	char		buff[545];

	number = (int)read(*fd, buff, 545);
	*tetriminos = ft_strdup(buff);
	*num = ((number + 2) / 21);
	if (((number + 2) % 21) != 1)
	{
		ft_putendl("error");
		return (0);
	}
	(*tetriminos)[number] = '\0';
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:12:47 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 21:13:21 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				main(int argc, char **argv)
{
	int			fd;
	int			num;
	int			*map_size;
	char		*tetriminos;
	t_figure	*figure;

	if (!(fillit_open(argc, argv, &fd)))
		return (0);
	if (!(fillit_read(&fd, &num, &tetriminos)))
		return (0);
	if (!(figure = (t_figure*)malloc(sizeof(*figure) * (num + 1))) || \
		!(map_size = (int*)malloc(sizeof(*map_size) * 2)))
		return (0);
	if (!(fillit_validate(figure, &tetriminos, num)))
		return (0);
	fillit_evaluate(figure, map_size, num);
	fillit_output(figure, map_size[0]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_change_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 23:34:15 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 23:37:59 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_figure		decrease_size(t_figure figure, int new_map_size)
{
	int			i;
	int			diff;
	t_figure	new_figure;
	t_figure	new_string;

	T_PRPCPY(new_figure, figure);
	T_ZERO(new_figure);
	if (((new_map_size == 3) && ((figure.prototype & 4383) != 0))
		|| ((new_map_size == 2) && (figure.prototype != 52224)))
		return (new_figure);
	i = 1;
	T_ZERO(new_string);
	diff = PROT_MAP_SIZE - new_map_size;
	while (i <= new_map_size)
	{
		new_string.low = (((uint64_t)figure.prototype >>
				(PROT_MAP_SIZE * (PROT_MAP_SIZE - i))) & 0xF) >> diff;
		if ((new_string.high == 0) && (new_string.low == 0))
			break ;
		new_figure = bit_or(bit_shift_up(new_figure, new_map_size), new_string);
		i++;
	}
	new_figure = bit_shift_up(new_figure,
	(new_map_size * (new_map_size - i + 1)));
	return (new_figure);
}

t_figure		increase_size(t_figure figure, int new_map_size)
{
	int			i;
	int			diff;
	t_figure	new_figure;
	t_figure	new_string;

	figure.low = (uint64_t)figure.prototype;
	T_PRPCPY(new_figure, figure);
	T_ZERO(new_figure);
	T_ZERO(new_string);
	i = 1;
	diff = new_map_size - PROT_MAP_SIZE;
	while (i <= PROT_MAP_SIZE)
	{
		new_string.low = (((uint64_t)figure.prototype >>
				(PROT_MAP_SIZE * (PROT_MAP_SIZE - i))) & 0xF) << diff;
		if ((new_string.high == 0) && (new_string.low == 0))
			break ;
		new_figure = bit_shift_up(new_figure, new_map_size);
		B_OR(new_figure, new_string);
		i++;
	}
	new_figure = bit_shift_up(new_figure, (new_map_size
	* (new_map_size - i + 1)));
	return (new_figure);
}

t_figure		change_size(t_figure figure, int new_map_size)
{
	if (new_map_size > PROT_MAP_SIZE)
		return (increase_size(figure, new_map_size));
	else if (new_map_size < PROT_MAP_SIZE)
		return (decrease_size(figure, new_map_size));
	else
	{
		figure.high = 0;
		figure.low = figure.prototype;
		return (figure);
	}
}

int				map_generation(t_figure *figure, int num)
{
	t_figure	map;
	int			map_size;
	int			i;

	t_figure_init(&map);
	map_size = ft_sqrt_up(num * 4);
	i = 0;
	while (i < num)
	{
		figure[i] = change_size(figure[i], map_size);
		i++;
	}
	return (map_size);
}

int				extend_map(t_figure *figure, int *map_size)
{
	int			i;

	map_size[0] += 1;
	i = 0;
	while ((figure[i].flag != END_OF_ARRAY))
	{
		figure[i] = change_size(figure[i], map_size[0]);
		i++;
	}
	return (-1);
}

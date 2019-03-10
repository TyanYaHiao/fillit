/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_evaluate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 22:27:42 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 23:39:53 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				backtrack(t_figure *figure, t_figure *map,
							int *map_size, int *nbr)
{
	int			result;

	if (figure[*nbr].flag == START_OF_ARRAY
		&& (figure[0].low == 0 && (figure[0].high == 0)))
		return (extend_map(figure, map_size));
	if (figure[*nbr].flag == END_OF_ARRAY)
		return (1);
	result = step_forward(figure, map, map_size, nbr);
	if (result == 1)
	{
		*nbr += 1;
		backtrack(figure, map, map_size, nbr);
	}
	else if (result == -1)
	{
		*nbr -= 1;
		step_back(figure, map, map_size, nbr);
	}
	return (-1);
}

int				step_forward(t_figure *figure, t_figure *map,
							int *map_size, int *nbr)
{
	t_figure	temp_map;

	if ((figure[*nbr].low == 0) && (figure[*nbr].high == 0))
		return (-1);
	temp_map.low = map->low ^ figure[*nbr].low;
	temp_map.high = map->high ^ figure[*nbr].high;
	if (((temp_map.low & figure[*nbr].low) == figure[*nbr].low)
	&& ((temp_map.high & figure[*nbr].high) == figure[*nbr].high))
	{
		*map = temp_map;
		return (1);
	}
	else if (figure[*nbr].flag != END_OF_ARRAY)
	{
		figure = move(figure, map_size, *nbr);
		return (step_forward(figure, map, map_size, nbr));
	}
	return (0);
}

int				step_back(t_figure *figure, t_figure *map,
							int *map_size, int *nbr)
{
	map->low = map->low ^ figure[*nbr].low;
	map->high = map->high ^ figure[*nbr].high;
	figure[*nbr + 1] = change_size(figure[*nbr + 1], map_size[0]);
	move(figure, map_size, *nbr);
	return (0);
}

void			fillit_evaluate(t_figure *figure, int *map_size, int num)
{
	int			nbr;
	t_figure	map;

	nbr = 0;
	T_INIT(map);
	map_size[0] = map_generation(figure, num);
	map_size[1] = 0;
	while (backtrack(figure, &map, map_size, &nbr) != 1)
		;
}

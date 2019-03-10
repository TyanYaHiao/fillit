/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:13:00 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 17:42:27 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		*generate_empty_map(int map_size)
{
	char	*map;
	int		i;
	int		strlen;

	i = 0;
	strlen = map_size * (map_size + 1);
	map = ft_strnew((size_t)strlen);
	while (i < strlen)
	{
		if ((i + 1) % (map_size + 1) == 0)
			map[i] = '\n';
		else
			map[i] = '.';
		i++;
	}
	return (map);
}

void		fillit_output(t_figure *figure1, int map_size)
{
	int		i;
	int		j;
	int		side;
	char	*map;

	map = generate_empty_map(map_size);
	i = 0;
	while (figure1[i].flag != END_OF_ARRAY)
	{
		side = map_size * (map_size + 1);
		j = 0;
		while (side - map_size)
		{
			if (side % map_size == 0)
				j++;
			if ((figure1[i].low & 1) == 1)
				map[side - j - 1] = 'A' + i;
			figure1[i] = bit_shift_down(figure1[i], 1);
			side--;
		}
		i++;
	}
	ft_putstr(map);
}

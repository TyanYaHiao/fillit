/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 23:40:45 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 23:43:01 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void			move_check(t_figure *figure, t_figure *mask,
						int *map_size, int nbr)
{
	int			i;

	if (map_size[1] != map_size[0])
	{
		map_size[1] = map_size[0];
		T_INIT(mask[0]);
		T_INIT(mask[1]);
		mask[0].low = ft_power(2, map_size[0]) - 1;
		i = -1;
		while (i++ < map_size[0])
		{
			mask[1] = bit_shift_up(mask[1], map_size[0]);
			mask[1].low = mask[1].low | 1;
		}
		mask[2] = bit_shift_up(mask[1], map_size[0] - 1);
	}
	i = -1;
	while (i++ < nbr)
		if ((figure[nbr].prototype == figure[i].prototype)
			&& figure[nbr].low > figure[i].low)
		{
			figure[nbr].low = figure[i].low;
			figure[nbr].high = figure[i].high;
		}
}

/*
** [0] - low; [1] - right; [2] - left
*/

t_figure		*move(t_figure *f, int *map_size, int nbr)
{
	static t_figure		*m;

	if (!m && !(m = (t_figure*)malloc(sizeof(*m) * 3)))
	{
		T_ZERO(f[nbr]);
		return (f);
	}
	move_check(f, m, map_size, nbr);
	if (((m[1].low & f[nbr].low) == 0) && ((m[1].high & f[nbr].high) == 0))
		f[nbr] = bit_shift_down(f[nbr], 1);
	else if (((m[2].low & f[nbr].low) != 0 || (m[2].high & f[nbr].high) != 0)
			&& ((f[nbr].low & m[0].low) == 0))
		f[nbr] = bit_shift_down(f[nbr], map_size[0]);
	else if (((m[2].low & f[nbr].low) == 0) && ((f[nbr].low & m[0].low) == 0))
	{
		f[nbr] = bit_shift_down(f[nbr], 1);
		while (((m[1].low & f[nbr].low) != 0) ||
				((m[1].high & f[nbr].high) != 0))
			f[nbr] = bit_shift_down(f[nbr], 1);
	}
	else
		t_figure_zero(&f[nbr]);
	return (f);
}

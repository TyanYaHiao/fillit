/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 21:12:30 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 19:42:15 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_figure		fillit_shift(t_figure figure)
{
	t_figure	temp;

	if (figure.prototype == 0)
		return (figure);
	temp = figure;
	while (temp.prototype < 4096)
		temp.prototype <<= 4;
	while (temp.prototype < 32768 && (temp.prototype / 2048) % 2 == 0\
		&& (temp.prototype / 128) % 2 == 0 && (temp.prototype / 8) % 2 == 0)
		temp.prototype <<= 1;
	return (temp);
}

int				fillit_validate(t_figure *figure, char **tetriminos, int num)
{
	int			i;
	t_figure	temp_fig;

	i = 0;
	T_ZERO(temp_fig);
	while (i < num)
	{
		figure[i] = validate_tetriminos(temp_fig, tetriminos, i);
		figure[i] = fillit_shift(figure[i]);
		if ((fillit_compare(figure[i])) && (i != num))
		{
			ft_putendl("error");
			return (0);
		}
		i++;
	}
	figure[0].flag = START_OF_ARRAY;
	figure[num].flag = END_OF_ARRAY;
	return (1);
}

t_figure		validate_tetriminos(t_figure figure, char **tetriminos, int num)
{
	int			i;

	i = num * 21;
	while (i < (num + 1) * 20 + num)
	{
		if ((*tetriminos)[i] != '\n' && (*tetriminos)[i] != '.'
			&& (*tetriminos)[i] != '#')
			break ;
		if ((*tetriminos)[i] == '#')
		{
			figure.prototype <<= 1;
			figure.prototype++;
		}
		if ((*tetriminos)[i] == '.')
			figure.prototype <<= 1;
		if ((*tetriminos)[i] == '\n')
			if (i != (num * 21) + 4 && i != (num * 21) + 9
				&& i != (num * 21) + 14 && i != (num * 21) + 19)
				break ;
		i++;
	}
	return (figure);
}

int				fillit_compare(t_figure figure)
{
	if (figure.prototype == 11776 || figure.prototype == 17600\
	|| figure.prototype == 19520 || figure.prototype == 19584\
	|| figure.prototype == 19968 || figure.prototype == 27648\
	|| figure.prototype == 34952 || figure.prototype == 35008\
	|| figure.prototype == 35904 || figure.prototype == 35968\
	|| figure.prototype == 36352 || figure.prototype == 50240\
	|| figure.prototype == 50688 || figure.prototype == 51328\
	|| figure.prototype == 52224 || figure.prototype == 58368\
	|| figure.prototype == 57856 || figure.prototype == 59392\
	|| figure.prototype == 61440)
		return (0);
	return (1);
}

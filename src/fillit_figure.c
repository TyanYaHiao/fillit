/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 15:22:10 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 22:15:08 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int				t_figure_equal(t_figure figure1, t_figure figure2)
{
	if ((figure1.low == figure2.low)
		&& (figure1.high == figure2.high))
		return (1);
	return (0);
}

void			t_figure_init(t_figure *figure)
{
	figure->low = 0;
	figure->high = 0;
	figure->prototype = 0;
	figure->flag = 0;
}

void			t_figure_zero(t_figure *figure)
{
	figure->low = 0;
	figure->high = 0;
}

t_figure		t_figure_copy(t_figure figure1, t_figure figure2)
{
	t_figure		temp;

	temp = figure1;
	temp.low = figure2.low;
	temp.high = figure2.high;
	return (temp);
}

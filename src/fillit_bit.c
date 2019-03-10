/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_bit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:22:24 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 23:01:19 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_figure		bit_and(t_figure figure1, t_figure figure2)
{
	figure1.high = figure1.high & figure2.high;
	figure1.low = figure1.low & figure2.low;
	return (figure1);
}

t_figure		bit_or(t_figure figure1, t_figure figure2)
{
	figure1.high = figure1.high | figure2.high;
	figure1.low = figure1.low | figure2.low;
	return (figure1);
}

t_figure		bit_shift_down(t_figure figure, int step)
{
	uint64_t	temp;
	t_figure	result;

	if (step > 63)
		return (bit_shift_down(bit_shift_down(figure, 63), step - 63));
	if (step == 0)
		return (figure);
	result.prototype = figure.prototype;
	result.flag = figure.flag;
	temp = figure.high << (64 - step);
	result.low = figure.low >> step;
	if (figure.high)
		result.high = figure.high >> step;
	else
		result.high = 0;
	if (temp)
		result.low = result.low | temp;
	return (result);
}

t_figure		bit_shift_up(t_figure figure, int step)
{
	uint64_t	temp;
	t_figure	result;

	if (step > 63)
		return (bit_shift_up(bit_shift_up(figure, 63), step - 63));
	if (step == 0)
		return (figure);
	result.prototype = figure.prototype;
	result.flag = figure.flag;
	temp = figure.low >> (64 - step);
	result.low = figure.low << step;
	if (figure.high)
		result.high = figure.high << step;
	else
		result.high = 0;
	if (temp)
		result.high = result.high | temp;
	return (result);
}

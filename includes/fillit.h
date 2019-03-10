/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 20:12:29 by fsmith            #+#    #+#             */
/*   Updated: 2019/03/09 23:09:52 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define PROT_MAP_SIZE		4
# define START_OF_ARRAY		1
# define END_OF_ARRAY		2
# define REGULAR_FIGURE		0
# define B_OR(a,b) a.high=a.high|b.high;a.low=a.low|b.low;
# define B_AND(a,b) a.high=a.high&b.high;a.low=a.low&b.low;
# define T_VALCPY(a,b) a.high=b.high;a.low=b.low;
# define T_PRPCPY(a,b) a.flag=b.flag;a.prototype=b.prototype;
# define T_CPY(a,b) T_VALCPY(a,b);T_OTHCPY(a,b);
# define T_ZERO(a) a.high=0;a.low=0;
# define T_INIT(a) a.low=0;a.high=0;a.prototype=0;a.flag=0;
# define T_REQ(a) a.high=a.prot_high;a.low=a.prot_low;

typedef struct	s_figure{
	uint8_t		flag;
	uint16_t	prototype;
	uint64_t	high;
	uint64_t	low;
}				t_figure;

int				t_figure_equal(t_figure figure1, t_figure figure2);
t_figure		bit_and(t_figure figure1, t_figure figure2);
t_figure		bit_or(t_figure figure1, t_figure figure2);
t_figure		bit_shift_down(t_figure figure, int step);
t_figure		bit_shift_up(t_figure figure, int step);
int				fillit_validate(t_figure *figure, char **tetriminos, int num);
t_figure		validate_tetriminos(t_figure figure, char **tetriminos,
									int num);
void			fillit_evaluate(t_figure *figure, int *map_size, int num);
t_figure		fillit_shift(t_figure figure);
t_figure		change_size(t_figure figure, int new_map_size);
t_figure		increase_size(t_figure figure, int new_map_size);
t_figure		decrease_size(t_figure figure, int new_map_size);
t_figure		*move(t_figure *figure, int *map_size, int nbr);
t_figure		t_figure_copy(t_figure figure1, t_figure figure2);
void			move_check(t_figure *figure, t_figure *mask,
							int *map_size, int nbr);
int				map_generation(t_figure *figure, int num);
int				backtrack(t_figure *figure, t_figure *map,
							int *map_size, int *nbr);
int				step_forward(t_figure *figure, t_figure *map,
							int *map_size, int *nbr);
int				step_back(t_figure *figure, t_figure *map,
							int *map_size, int *nbr);
int				try_figure(t_figure *figure, int num, int map_size);
int				try_point(t_figure figure, t_figure *map, int map_size);
int				move_point_check(t_figure figure, int map_size);
void			t_figure_init(t_figure *figure);
void			t_figure_zero(t_figure *figure);
int				fillit_open(int argc, char **argv, int *fd);
int				fillit_read(int *fd, int *num, char **tetriminos);
int				fillit_compare(t_figure figure);
char			*generate_empty_map(int map_size);
void			fillit_output(t_figure *figure, int map_size);
int				extend_map (t_figure *figure, int *map_size);

#endif

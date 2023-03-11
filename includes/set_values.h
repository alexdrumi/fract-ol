/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_values.h                                 :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_VALUES_H
# define SET_VALUES_H

# include "structs.h"
# include "macros.h"
# include "../minilibx/mlx.h"

void	set_colorset(t_parse *info, int color_set, int *nr_of_valid_input);
void	set_const(double *jul_const, double input_val, int *nr_of_valid_input);
void	set_bools_for_julia(t_parse *info, int *nr_of_valid_input);
void	set_bools_for_mandelbrot(t_parse *info, int *nr_of_valid_input);
t_bool	set_canvas_succ(t_canvas *canvas, t_parse *info, int width, int height);

#endif
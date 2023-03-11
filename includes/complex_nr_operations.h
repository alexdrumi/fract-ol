/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_nr_operations.h             :+:    :+:                           */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_NR_OPERATIONS_H
# define COMPLEX_NR_OPERATIONS_H

# include <math.h>
# include "structs.h"

t_complex	get_map_point(t_canvas *canvas, int x, int y);
t_complex	add(t_complex a, t_complex b);
t_complex	sqr(t_complex a);
double		mod(t_complex a);
double		interpolate(double color1, double color2, double t);

#endif
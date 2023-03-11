/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   complex_nr_operations.c             :+:    :+:                           */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/complex_nr_operations.h"

t_complex	get_map_point(t_canvas *canvas, int x, int y)
{
	t_complex	c;
	double		range_re;
	double		range_im;

	range_re = canvas->info.real.max - canvas->info.real.min; //mitol meddig terjed, teljesen felesleges mindig kiszamolni
	range_im = canvas->info.imaginary.max - canvas->info.imaginary.min; //mitol meddig
	c.x = (x * (range_re / canvas->width) + canvas->info.real.min);
	c.y = (y * (range_im / canvas->height) + canvas->info.imaginary.min);
	return (c);
}

//eloszor a c megvaltozi
//a vaktizitt ct emelem negyzetres
t_complex	add(t_complex a, t_complex b)
{
	t_complex	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}

t_complex	sqr(t_complex a)
{
	t_complex	c;

	c.x = a.x * a.x - a.y * a.y;
	c.y = 2 * a.x * a.y;
	return (c);
}

double	mod(t_complex a)
{
	return (sqrt(a.x * a.x + a.y * a.y));
}

double	interpolate(double color1, double color2, double t)
{
	return (color1 * (1 - t) + color2 * t);
}

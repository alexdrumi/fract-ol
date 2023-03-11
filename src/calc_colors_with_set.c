/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_colors_with_set.c           :+:    :+:                              */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/calc_colors_with_set.h"

static void	assign_to_z_and_c(t_canvas *canvas, t_complex *z0, t_complex *c)
{
	z0->x = c->x;
	z0->y = c->y;
	if (canvas->info.is_mandelbrot_selected == false)
	{
		c->x = canvas->info.jul_const.x;
		c->y = canvas->info.jul_const.y;
	}
}

static void	create_black_and_white(t_rgb *rgb, double i)
{
	int	black_and_white;

	black_and_white = 255 - (int)(i * 255 / MAX_ITER);
	rgb->r = black_and_white;
	rgb->g = black_and_white;
	rgb->b = black_and_white;
}

static void	create_green_trip(t_rgb *rgb, double i)
{
	if (i == MAX_ITER)
	{
		i = 0;
	}
	rgb->r = (int)(i * 0.18) % 256;
	rgb->g = (int)(i * 5) % 256;
	rgb->b = ((int)i % 256) + 5;
}

static void	get_rgb_based_on_userchoice(t_canvas *canvas, t_rgb *rgb, double i)
{
	if (canvas->info.color_set == HUE_SATURATED_VAL)
	{
		create_rgb_from_hsv(rgb, i);
	}
	else if (canvas->info.color_set == GREEN_TRIP)
	{
		create_green_trip(rgb, i);
	}
	else
	{
		create_black_and_white(rgb, i);
	}
}


t_rgb	calc_colors_with_set(t_canvas *canvas, int x, int y)
{
	double		i;
	t_rgb		rgb;
	t_complex	z0;
	t_complex	z1;
	t_complex	c;

	i = 0;
	c = get_map_point(canvas, x, y); //
	assign_to_z_and_c(canvas, &z0, &c);
	while (i < MAX_ITER)
	{
		z1 = add(sqr(z0), c);
		if (mod(z1) > ESCAPE_RADIUS)
			break ;
		z0 = z1;
		i++;
	}
	get_rgb_based_on_userchoice(canvas, &rgb, i);
	return (rgb);
}

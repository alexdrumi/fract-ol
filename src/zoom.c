/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zoom.c                    :+:    :+:                                     */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/zoom.h"

static void	calculate_complex_vals(t_canvas *canvas, int keycode)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == WHEEL_ZOOM_OUT || keycode == WHEEL_ZOOM_IN)
	{
		x = canvas->width * 0.5;
		y = canvas->height * 0.5;
		canvas->info.mouse_re = map_to_real_val(x, canvas->width,
				canvas->info.real.min, canvas->info.real.max);
		canvas->info.mouse_im = map_to_imag_val(y, canvas->height,
				canvas->info.imaginary.min, canvas->info.imaginary.max);
	}
	else if (keycode == LEFT_CLICK || keycode == RIGHT_CLICK)
	{
		mlx_mouse_get_pos(canvas->win, &x, &y);
		canvas->info.mouse_re = map_to_real_val(x, canvas->width,
				canvas->info.real.min, canvas->info.real.max);
		canvas->info.mouse_im = map_to_imag_val(y, canvas->height,
				canvas->info.imaginary.min, canvas->info.imaginary.max);
	}
}

static void	interpolate_range_vals(t_canvas *canvas, double interpolation)
{
	canvas->info.real.min = interpolate(canvas->info.mouse_re,
			canvas->info.real.min, interpolation);
	canvas->info.imaginary.min = interpolate(canvas->info.mouse_im,
			canvas->info.imaginary.min, interpolation);
	canvas->info.real.max = interpolate(canvas->info.mouse_re,
			canvas->info.real.max, interpolation);
	canvas->info.imaginary.max = interpolate(canvas->info.mouse_im,
			canvas->info.imaginary.max, interpolation);
}

static void	zoom_with_mouse(t_canvas *canvas, int keycode)
{
	double	interpolation;

	interpolation = 0;
	if (keycode == RIGHT_CLICK)
	{
		interpolation = 1.0 * ZOOM_FACTOR;
	}
	else if (keycode == LEFT_CLICK)
	{
		interpolation = 1.0 / ZOOM_FACTOR;
	}
	calculate_complex_vals(canvas, keycode);
	interpolate_range_vals(canvas, interpolation);
	display_to_mlx(canvas);
}

static void	zoom_with_scroll(t_canvas *canvas, int keycode)
{
	double	interpolation;

	interpolation = 0;
	if (keycode == WHEEL_ZOOM_OUT)
	{
		interpolation = 1.0 * ZOOM_FACTOR;
	}
	else if (keycode == WHEEL_ZOOM_IN)
	{
		interpolation = 1.0 / ZOOM_FACTOR;
	}
	calculate_complex_vals(canvas, keycode);
	interpolate_range_vals(canvas, interpolation);
	display_to_mlx(canvas);
}

int	mouse_press_handler(int button, int x, int y, void *param)
{
	t_canvas	*canvas;
	int			i;
	int			j;

	i = x;
	j = y;
	canvas = (t_canvas *)param;
	if (button == LEFT_CLICK)
	{
		zoom_with_mouse(canvas, LEFT_CLICK);
	}
	else if (button == RIGHT_CLICK)
	{
		zoom_with_mouse(canvas, RIGHT_CLICK);
	}
	else if (button == WHEEL_ZOOM_IN)
	{
		zoom_with_scroll(canvas, WHEEL_ZOOM_IN);
	}
	else if (button == WHEEL_ZOOM_OUT)
	{
		zoom_with_scroll(canvas, WHEEL_ZOOM_OUT);
	}
	return (j * i);
}

/*
void	select_zoom_method_based_on_keycode(t_canvas *canvas, int keycode)
{
	int x;
	int y;
	double interpolation;

	if (keycode == WHEEL_ZOOM_OUT || keycode == RIGHT_CLICK)
	{
		interpolation = 1.0 * ZOOM_FACTOR;
	}
	else if (keycode == WHEEL_ZOOM_IN || keycode == LEFT_CLICK)
	{
		interpolation = 1.0 / ZOOM_FACTOR;
	}
	calculate_complex_vals(canvas, keycode);
	interpolate_range_vals(canvas, interpolation);
	display_to_mlx(canvas);
}
*/
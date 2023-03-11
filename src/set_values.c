/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_values.c                                 :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/set_values.h"

void	set_const(double *jul_const, double input_val, int *nr_of_valid_input)
{
	(*jul_const) = input_val;
	(*nr_of_valid_input)++;
}

void	set_bools_for_julia(t_parse *info, int *nr_of_valid_input)
{
	info->set_already_chosen = true;
	info->is_mandelbrot_selected = false;
	(*nr_of_valid_input)++;
}

void	set_bools_for_mandelbrot(t_parse *info, int *nr_of_valid_input)
{
	info->set_already_chosen = true;
	info->is_mandelbrot_selected = true;
	(*nr_of_valid_input) = EXPECTED_NR_OF_MAX_INPUTS - 1;
}

void	set_colorset(t_parse *info, int color_set, int *nr_of_valid_input)
{
	info->color_set = color_set;
	(*nr_of_valid_input) = EXPECTED_NR_OF_MAX_INPUTS;
}

t_bool	set_canvas_succ(t_canvas *canvas, t_parse *info, int width, int height)
{
	canvas->width = width;
	canvas->height = height;
	canvas->mlx = mlx_init();
	if (canvas->mlx == NULL)
		return (false);
	canvas->win = mlx_new_window(canvas->mlx, canvas->width,
			canvas->height, "42 fract-ol\n");
	if (canvas->win == NULL)
		return (false);
	canvas->info.real.min = -2;
	canvas->info.real.max = 2;
	canvas->info.imaginary.min = -2;
	canvas->info.imaginary.max = 2;
	canvas->info.color_set = info->color_set;
	canvas->info.set_already_chosen = info->set_already_chosen;
	if (info->is_mandelbrot_selected == false)
	{
		canvas->info.jul_const.x = info->jul_const.x;
		canvas->info.jul_const.y = info->jul_const.y;
		canvas->info.is_mandelbrot_selected = false;
	}
	else
		canvas->info.is_mandelbrot_selected = true;
	return (true);
}

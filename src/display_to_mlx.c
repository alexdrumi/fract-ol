/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_to_mlx.c                          :+:    :+:                     */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/display_to_mlx.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length) + (x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

double	clamp(double low, double high, double value)
{
	return (fmax(low, fmin(high, value)));
}

int	get_color_at_pixel(t_canvas *canvas, int x, int y) //adtt x y nal
{
	int			color;
	t_rgb		rgb;

	rgb = calc_colors_with_set(canvas, x, y);
	color = create_trgb(0, rgb.r, rgb.g, rgb.b);
	return (color);
}

void	display_to_mlx(t_canvas *canvas)
{
	canvas->image_ptr.img = mlx_new_image(canvas->mlx, canvas->width,
			canvas->height);
	if (canvas->image_ptr.img == NULL)
	{
		return ;
	}
	canvas->image_ptr.addr = mlx_get_data_addr(canvas->image_ptr.img,
			&canvas->image_ptr.bits_per_pixel, &canvas->image_ptr.line_length,
			&canvas->image_ptr.endian);
	if (canvas->image_ptr.addr == NULL)
	{
		mlx_destroy_image(canvas->mlx, canvas->image_ptr.img);
		return ;
	}
	display_to_mlx_loop(canvas);
	mlx_put_image_to_window(canvas->mlx, canvas->win, canvas->image_ptr.img,
		0, 0);
	mlx_destroy_image(canvas->mlx, canvas->image_ptr.img);
}

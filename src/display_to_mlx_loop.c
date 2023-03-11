/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_to_mlx_loop.h           :+:    :+:                               */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/display_to_mlx_loop.h"

void	display_to_mlx_loop(t_canvas *canvas)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	x = 0;
	while (y < canvas->height)
	{
		x = 0;
		while (x < canvas->width)
		{
			color = get_color_at_pixel(canvas, x, y);
			my_mlx_pixel_put(&canvas->image_ptr, x, y, color);
			x++;
		}
		y++;
	}
}

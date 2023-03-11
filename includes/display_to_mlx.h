/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_to_mlx.h                          :+:    :+:                     */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_TO_MLX_H
# define DISPLAY_TO_MLX_H

# include "../minilibx/mlx.h"
# include "calc_colors_with_set.h"
# include "../includes/display_to_mlx_loop.h"

void	display_to_mlx(t_canvas *canvas);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
double	clamp(double low, double high, double value);
int		get_color_at_pixel(t_canvas *canvas, int x, int y);

#endif
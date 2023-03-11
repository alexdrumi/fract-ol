/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_colors_with_set.h           :+:    :+:                              */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_COLORS_WITH_SET_H
# define CALC_COLORS_WITH_SET_H

# include "structs.h"
# include "macros.h"
# include "complex_nr_operations.h"
# include "create_rgb_from_hsv.h"

t_rgb	calc_colors_with_set(t_canvas *canvas, int x, int y);

#endif
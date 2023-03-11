/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_operations.h                            :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MORE_OPERATIONS_H
# define MORE_OPERATIONS_H

# include "get_next_line.h"
# include "structs.h"
# include "set_values.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_if_input_correct(const char *s1, const char *s2, int len);
void	set_bools_for_info(t_parse *info, int *nr_of_valid_input);
double	map_to_real_val(int x, int image_width, double min_R, double max_R);
double	map_to_imag_val(int y, int image_height, double min_I, double max_I);

#endif
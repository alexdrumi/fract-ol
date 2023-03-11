/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   more_operations.c                            :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/more_operations.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (!n)
		return (0);
	i = 0;
	if (ft_strlen(s1) < ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	while (i < len && i < n - 1)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			break ;
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_if_input_correct(const char *s1, const char *s2, int len)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
	{
		return (0);
	}
	while (s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
	}
	if (i == len && i == 5)
	{
		return ((ft_strncmp(s1, "julia", 5) == 0));
	}
	else if (i == len && i == 10)
	{
		return ((ft_strncmp(s1, "mandelbrot", 10) == 0));
	}
	else
	{
		return (0);
	}
}

double	map_to_real_val(int x, int image_width, double min_R, double max_R)
{
	double	range;

	range = max_R - min_R;
	return (x * (range / image_width) + min_R);
}

double	map_to_imag_val(int y, int image_height, double min_I, double max_I)
{
	double	range;

	range = max_I - min_I;
	return (y * (range / image_height) + min_I);
}

void	set_bools_for_info(t_parse *info, int *nr_of_valid_input)
{
	if (info->is_mandelbrot_selected == true)
	{
		set_bools_for_mandelbrot(info, nr_of_valid_input);
		write(1, DISPLAY_MANDELBROT_CHOSEN_MESSAGE,
			ft_strlen(DISPLAY_MANDELBROT_CHOSEN_MESSAGE));
		write(1, DISPLAY_CHOSE_COLOR_MESSAGE,
			ft_strlen(DISPLAY_CHOSE_COLOR_MESSAGE));
	}
	else
	{
		write(1, DISPLAY_JULIA_CHOSEN_MESSAGE,
			ft_strlen(DISPLAY_JULIA_CHOSEN_MESSAGE));
		set_bools_for_julia(info, nr_of_valid_input);
		write(1, DISPLAY_FIRST_CONSTANT_MESSAGE,
			ft_strlen(DISPLAY_FIRST_CONSTANT_MESSAGE));
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse.c                              :+:    :+:                          */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parse.h"

static void	info_for_jul(t_parse *info, char *line, int *nr_of_valid_input)
{
	double	n;

	n = atof(line);
	if (n == FATOI_ERROR)
	{
		write(1, DISPLAY_INCORRECT_DECIMAL_MESSAGE,
			ft_strlen(DISPLAY_INCORRECT_DECIMAL_MESSAGE));
	}
	else if (*nr_of_valid_input == 1)
	{
		set_const(&info->jul_const.x, n, nr_of_valid_input);
		write(1, DISPLAY_SECOND_CONSTANT_MESSAGE,
			ft_strlen(DISPLAY_SECOND_CONSTANT_MESSAGE));
	}
	else if ((*nr_of_valid_input) == 2)
	{	
		set_const(&info->jul_const.y, n, nr_of_valid_input);
		write(1, DISPLAY_CHOSE_COLOR_MESSAGE,
			ft_strlen(DISPLAY_CHOSE_COLOR_MESSAGE));
	}
}

static void	chose_julia_set(t_parse *info, int *nr_of_valid_input, char *line)
{
	if (info->is_mandelbrot_selected == true)
	{
		write(1, DISPLAY_MANDELBROT_SET_CHOSEN,
			ft_strlen(DISPLAY_MANDELBROT_SET_CHOSEN));
		write(1, DISPLAY_CHOSE_COLOR_MESSAGE,
			ft_strlen(DISPLAY_CHOSE_COLOR_MESSAGE));
	}
	else if (*nr_of_valid_input == 1 || *nr_of_valid_input == 2)
	{
		info_for_jul(info, line, nr_of_valid_input);
	}
	else if (*nr_of_valid_input == 3)
	{
		write(1, DISPLAY_CHOSE_COLOR_MESSAGE,
			ft_strlen(DISPLAY_CHOSE_COLOR_MESSAGE));
	}
	else
	{
		write(1, DISPLAY_JULIA_CHOSEN_MESSAGE,
			ft_strlen(DISPLAY_JULIA_CHOSEN_MESSAGE));
		(*nr_of_valid_input) = 1;
	}
}

static void	chose_mandelbrot_set(int *nr_of_valid_input)
{
	if (*nr_of_valid_input == EXPECTED_NR_OF_MAX_INPUTS - 1)
	{
		write(1, DISPLAY_CHOSE_COLOR_MESSAGE,
			ft_strlen(DISPLAY_CHOSE_COLOR_MESSAGE));
	}
	else
	{
		write(1, DISPLAY_MANDELBROT_SET_CHOSEN,
			ft_strlen(DISPLAY_MANDELBROT_SET_CHOSEN));
		write(1, DISPLAY_CHOSE_COLOR_MESSAGE,
			ft_strlen(DISPLAY_CHOSE_COLOR_MESSAGE));
	}
}

static void	check_input(t_parse *info, char *line, int *nr_of_valid_input)
{
	if (ft_strncmp(line, "", 1) == 0)
		write(1, DISPLAY_INCORRECT_INPUT_MESSAGE,
			ft_strlen(DISPLAY_INCORRECT_INPUT_MESSAGE));
	else if (ft_strncmp(line, "--exit", 6) == 0)
		(*nr_of_valid_input) = CALL_FOR_EXIT;
	else if (ft_strncmp(line, "bnw", 3) == 0 && *nr_of_valid_input == 3)
		set_colorset(info, BLACK_AND_WHITE, nr_of_valid_input);
	else if (ft_strncmp(line, "hsv", 3) == 0 && *nr_of_valid_input == 3)
		set_colorset(info, HUE_SATURATED_VAL, nr_of_valid_input);
	else if (ft_strncmp(line, "green", 5) == 0 && *nr_of_valid_input == 3)
		set_colorset(info, GREEN_TRIP, nr_of_valid_input);
	else if (ft_strncmp(line, "--help", 6) == 0)
		write(1, DISPLAY_HELP_MESSAGE, ft_strlen(DISPLAY_HELP_MESSAGE));
	else if (info->is_mandelbrot_selected == true)
		chose_mandelbrot_set(nr_of_valid_input);
	else if (info->is_mandelbrot_selected == false
		|| ((*nr_of_valid_input) > 0 && (*nr_of_valid_input) < 3))
		chose_julia_set(info, nr_of_valid_input, line);
	else
		write(1, DISPLAY_INCORRECT_INPUT_MESSAGE,
			ft_strlen(DISPLAY_INCORRECT_INPUT_MESSAGE));
	free(line);
}

t_bool	parse_succ(t_parse *info)
{
	int		nr_of_valid_input;
	int		ret;
	char	*line;

	nr_of_valid_input = 0;
	ret = 1;
	line = 0;
	set_bools_for_info(info, &nr_of_valid_input);
	write(1, DISPLAY_OPENING_MESSAGE, ft_strlen(DISPLAY_OPENING_MESSAGE));
	while (ret == 1 && nr_of_valid_input != EXPECTED_NR_OF_MAX_INPUTS)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == AN_ERROR_OCCURED)
		{
			write(1, DISPLAY_FAILED_GET_LINE_MESSAGE,
				ft_strlen(DISPLAY_FAILED_GET_LINE_MESSAGE));
			return (false);
		}
		check_input(info, line, &nr_of_valid_input);
		if (nr_of_valid_input == CALL_FOR_EXIT)
		{
			return (false);
		}
	}
	return (true);
}

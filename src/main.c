/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                       :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static int	close_window(void)
{
	exit(0);
}

static void	exit_function(void)
{
	write(1, DISPLAY_INCORRECT_ARGUMENT_MESSAGE,
		ft_strlen(DISPLAY_INCORRECT_ARGUMENT_MESSAGE));
	close_window();
}

static void	set_info(t_parse *info, char *argv[])
{
	info->set_already_chosen = false;
	if (check_if_input_correct(argv[1], "mandelbrot", ft_strlen(argv[1])) == 1)
	{
		info->is_mandelbrot_selected = true;
	}
	else if (check_if_input_correct(argv[1], "julia", ft_strlen(argv[1])) == 1)
	{
		info->is_mandelbrot_selected = false;
	}
	else
	{
		exit_function();
	}
}


//HAVE TO PASS INT KEYCODES TO ONLY EXIT IN CASE OF ESC, LIKE THIS IT EXITS ALSO WITH OTHER KEYS
static void	set_hooks(t_canvas *canvas)
{
	mlx_hook(canvas->win, 4, 0, mouse_press_handler, canvas);
	mlx_hook(canvas->win, 17, 0, close_window, canvas);
	mlx_hook(canvas->win, 2, 0, close_window, canvas);
	mlx_loop(canvas->mlx);
}

int	main(int argc, char *argv[])
{
	t_canvas	canvas;
	t_parse		info;

	if (argc < 2)
	{
		exit_function();
	}
	set_info(&info, argv);
	if (parse_succ(&info) == false)
	{
		return (AN_ERROR_OCCURED);
	}
	if (set_canvas_succ(&canvas, &info, 640, 480) == false)
	{
		return (AN_ERROR_OCCURED);
	}
	display_to_mlx(&canvas);
	set_hooks(&canvas);
	return (0);
}

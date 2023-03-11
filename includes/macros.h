/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   macros.h                                       :+:    :+:                */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# include <stddef.h>
# ifndef MAX_ITER
#  define MAX_ITER 300
# endif

# ifndef ESCAPE_RADIUS
#  define ESCAPE_RADIUS 5
# endif

# ifndef ZOOM_FACTOR
#  define ZOOM_FACTOR 1.3
# endif

# ifndef LEFT_CLICK
#  define LEFT_CLICK 1
# endif

# ifndef RIGHT_CLICK
#  define RIGHT_CLICK 2
# endif

# ifndef WHEEL_ZOOM_IN
#  define WHEEL_ZOOM_IN 4
# endif

# ifndef WHEEL_ZOOM_OUT
#  define WHEEL_ZOOM_OUT 5
# endif

# ifndef EXPECTED_NR_OF_MAX_INPUTS
#  define EXPECTED_NR_OF_MAX_INPUTS 4
# endif

# ifndef CALL_FOR_EXIT
#  define CALL_FOR_EXIT 9
# endif

# ifndef BLACK_AND_WHITE
#  define BLACK_AND_WHITE 6
# endif

# ifndef HUE_SATURATED_VAL
#  define HUE_SATURATED_VAL 7
# endif

# ifndef GREEN_TRIP
#  define GREEN_TRIP 8
# endif

# ifndef DISPLAY_OPENING_MESSAGE
#  define DISPLAY_OPENING_MESSAGE "If you need more information type: --help\n\
If you would like to quit the program now type: --exit\n\n"
# endif

# ifndef DISPLAY_JULIA_CHOSEN_MESSAGE
#  define DISPLAY_JULIA_CHOSEN_MESSAGE "\n-------------------------------------------------------------\n\
Welcome in the fractol project, you \
have chosen the julia set.\n\
-------------------------------------------------------------\n\n"
# endif

# ifndef DISPLAY_MANDELBROT_CHOSEN_MESSAGE
#  define DISPLAY_MANDELBROT_CHOSEN_MESSAGE "\n------------------------------------------------------------------\n\
Welcome in the fractol project, \
you have chosen the mandelbrot set.\n\
------------------------------------------------------------------\n\n\
"
# endif

# ifndef DISPLAY_FAILED_GET_LINE_MESSAGE
#  define DISPLAY_FAILED_GET_LINE_MESSAGE "Getting next line failed \
for unexpected reasons, exciting program\n\n"
# endif 

# ifndef DISPLAY_PARSE_OPENING_MESSAGE
#  define DISPLAY_PARSE_OPENING_MESSAGE "\nPlease enter the name of \
the set you would like to display (mandelbrot or julia).\nYou could also \
type --help for more information or --exit to quit the program at this \
point.\n\n"
# endif

# ifndef DISPLAY_CHOSE_COLOR_MESSAGE
#  define DISPLAY_CHOSE_COLOR_MESSAGE "Please enter bnw for BLACK & \
WHITE, enter hsv for HUE SATURATED VALUE or enter green for GREEN \
TRIP color scheme. Your input will be only checked until they \
match one of the offered color scheme.\n\n"
# endif

# ifndef DISPLAY_MANDELBROT_SET_CHOSEN
#  define DISPLAY_MANDELBROT_SET_CHOSEN "You have already choosen \
Mandelbrot set.\n\n"
# endif

# ifndef DISPLAY_HELP_MESSAGE
#  define DISPLAY_HELP_MESSAGE "\n\n-------------------------------------------------------------\n\nIf you gave mandelbrot (set) as a \
parameter when launching the program then the next expected input is \
a color set of your choice. (In case you type mandelbrot followed by \
an incorrect input, it will still wait for your color set of choice <bnw, hsv \
or green>.\n\nIf you gave julia (set) as a parameter when launching the program\
 then we would like to ask you to chose the components\
 of complex number c (real, imaginary), then chose a color set <type bnw, hsv \
or green>.\n\nHere are some of the usual julia set constants:\n\
- <input 1: -0.4> <input 2: 0.6>\n- <input 1: -0.8> <input 2: 0.156>\n\
- <input 1: 0.285> <input 2: 0>\n- <input 1: 0.285> <input 2: 0.01>\n\
- <input 1: -0.7269> <input 2: 0.1889>\n\nMore information on Julia set can \
be found on wikipedia.\n\nIf you would like to use zoom following your mouse \
position, just click on the spot of interest inside the display window \
with left click.\nZoom out with the same approach is right click.\nYou can \
also use your mouse wheels to zoom in and out, this will remain centered \
compared to previous position.\nYou can exit the program now by typing: \
--exit or continue according to the above mentioned process.\n\n"
# endif

# ifndef DISPLAY_INCORRECT_DECIMAL_MESSAGE
#  define DISPLAY_INCORRECT_DECIMAL_MESSAGE "Please enter correct \
decimal input, (eg: -0.7269): \n\n"
# endif

# ifndef DISPLAY_SECOND_CONSTANT_MESSAGE
#  define DISPLAY_SECOND_CONSTANT_MESSAGE "Please enter the \
second constant in decimal notation (eg: 0.1889): \n\n"
# endif

# ifndef DISPLAY_FIRST_CONSTANT_MESSAGE
#  define DISPLAY_FIRST_CONSTANT_MESSAGE "Please enter the first \
constant in decimal notation (eg: -0.7269): \n\n"
# endif

# ifndef DISPLAY_INCORRECT_ARGUMENT_MESSAGE
#  define DISPLAY_INCORRECT_ARGUMENT_MESSAGE "expected ./fractol \
[name of set]\nName of set can be either [julia] or [mandelbrot] \
without the brackets\n\n"
# endif

# ifndef DISPLAY_INCORRECT_INPUT_MESSAGE
#  define DISPLAY_INCORRECT_INPUT_MESSAGE "Incorrect input. You \
could also type --help for more information or --exit to quit the program \
at this point.\n\n"
# endif

# ifndef FATOI_ERROR
#  define FATOI_ERROR -1.2300123344
# endif

#endif
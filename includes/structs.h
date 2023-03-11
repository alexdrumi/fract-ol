/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                    :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_data;

typedef enum bool
{
	true,
	false
}				t_bool;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_hsv
{
	double	h;
	double	s;
	double	v;
}				t_hsv;

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct real_set
{
	double	min;
	double	max;
}				t_real_set;

typedef struct imaginary_set
{
	double	min;
	double	max;
}				t_imag_set;

typedef struct s_mandelbrot_info
{
	t_real_set		real;
	t_imag_set		imaginary;
	t_bool			is_mandelbrot_selected;
	t_bool			set_already_chosen;
	t_complex		jul_const;
	int				color_set;
	double			mouse_re;
	double			mouse_im;

}				t_mandelbrot_info;

typedef struct canvas
{
	int					width;
	int					height;
	void				*mlx;
	void				*win;
	t_mandelbrot_info	info;
	t_data				image_ptr;
}				t_canvas;

typedef struct s_parse_info
{
	t_bool			is_mandelbrot_selected;
	t_bool			set_already_chosen;
	t_complex		jul_const;
	int				color_set;
}				t_parse;

#endif
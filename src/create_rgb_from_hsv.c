/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_rgb_from_hsv.c                     :+:    :+:                     */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/create_rgb_from_hsv.h"

static void	assign_to_hsv(t_hsv *hsv, double val1, double val2, double val3)
{
	hsv->h = val1;
	hsv->s = val2;
	hsv->v = val3;
}

static void	assign_to_rgb(t_rgb *rgb, int val1, int val2, int val3)
{
	rgb->r = val1;
	rgb->g = val2;
	rgb->b = val3;
}

static void	calculate_pqt(t_hsv *hsv, double *P, double *Q, double *T)
{
	double	fract;

	fract = 0;
	if (hsv->h == 360)
	{
		hsv->h = 0;
	}
	else
	{
		hsv->h = hsv->h / 60;
	}
	fract = hsv->h - floor(hsv->h);
	*P = hsv->v * (1 - hsv->s);
	*Q = hsv->v * (1 - hsv->s * fract);
	*T = hsv->v * (1 - hsv->s * (1 - fract));
}

static t_rgb	hsv_to_rgb(t_hsv hsv)
{
	t_rgb	rgb;
	double	p;
	double	q;
	double	t;

	calculate_pqt(&hsv, &p, &q, &t);
	if (0 <= hsv.h && hsv.h < 1)
		assign_to_rgb(&rgb, hsv.v, t, p);
	else if (1 <= hsv.h && hsv.h < 2)
		assign_to_rgb(&rgb, q, hsv.v, p);
	else if (2 <= hsv.h && hsv.h < 3)
		assign_to_rgb(&rgb, p, hsv.v, t);
	else if (3 <= hsv.h && hsv.h < 4)
		assign_to_rgb(&rgb, p, q, hsv.v);
	else if (4 <= hsv.h && hsv.h < 5)
		assign_to_rgb(&rgb, t, p, hsv.v);
	else if (5 <= hsv.h && hsv.h < 6)
		assign_to_rgb(&rgb, hsv.v, p, q);
	else
		assign_to_rgb(&rgb, 0, 0, 0);
	rgb.r = (int)(255 * clamp(0, 1, rgb.r * 0.7));
	rgb.g = (int)(255 * clamp(0, 1, rgb.g * 1.1));
	rgb.b = (int)(255 * clamp(0, 1, rgb.b));
	return (rgb);
}

void	create_rgb_from_hsv(t_rgb *rgb, double i)
{
	t_hsv	hsv;
	double	linear;

	linear = interpolate(floor(i), ceil(i), fmod(i, 1));
	assign_to_hsv(&hsv, (360 / 255 * linear), 0.8, 1);
	*rgb = hsv_to_rgb(hsv);
}

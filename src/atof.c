/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   atof.c                                       :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/atof.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r');
}

static void	skip_space_n_sign(const char *s, double *si, int *dec_flag, int *i)
{
	*i = 0;
	*dec_flag = 0;
	*si = 1;
	while (s[*i] != '\0' && ft_isspace(s[*i]))
		(*i)++;
	if (s[*i] != '\0' && (s[*i] == '-' || s[*i] == '+'))
	{
		if (s[*i] == '-')
			*si = -(*si);
		(*i)++;
	}
}

static int	calc_dec(const char *s, int *dec_flag, double *j, double *res)
{
	if (*dec_flag == 1 && *s == '.')
		return (-1);
	else if (*j == 0)
	{
		*dec_flag = 1;
		*j = 1;
	}
	else
	{
		*res = *res + (*s - '0') / (pow(10, *j));
		(*j)++;
	}
	return (1);
}

double	atof(const char *str)
{
	int		dec_flag;
	int		i;
	double	j;
	double	sign;
	double	res;

	if (!str)
		return (FATOI_ERROR);
	j = 0;
	res = 0;
	skip_space_n_sign(str, &sign, &dec_flag, &i);
	while ((str[i] != '\0' && ft_isdigit(str[i])) || str[i] == '.')
	{
		if (str[i] != '.' && dec_flag == 0)
			res = res * 10 + (str[i] - '0');
		else
		{
			if (calc_dec(str + i, &dec_flag, &j, &res) == -1)
				return (FATOI_ERROR);
		}
		i++;
	}
	if (str[i] != '\0')
		return (FATOI_ERROR);
	return (res * sign);
}

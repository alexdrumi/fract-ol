/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                        :+:    :+:                  */
/*                                                     +:+                    */
/*   By: bmajor <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/11 11:55:37 by bmajor        #+#    #+#                 */
/*   Updated: 2021/07/11 11:55:39 by bmajor        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	is_n_in_str(char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == 0)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*ret;
	unsigned char	*s;
	size_t			i;
	size_t			total_bytes;

	total_bytes = count * size;
	ret = malloc(total_bytes);
	if (ret == 0)
		return (NULL);
	s = ret;
	i = 0;
	while (i < total_bytes)
	{
		s[i] = 0;
		i++;
	}
	return (ret);
}

void	ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	if ((dst && src) == 0)
		return ;
	i = 0;
	while (i < len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
}
